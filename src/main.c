#include <stdlib.h>
#include "ft_printf.h"
#include "cub3d.h"
#include "minilib.h"
#include "error.h"

int		exit_failure(void *data)
{
	free(data);
	print_error("cub3d");
	return (EXIT_FAILURE);
}

void	usage()
{
	ft_dprintf(
		0,
		"usage: ./cub3d [-s/--save] <path/map.cub>\n"
		"		-s --save: ???\n"
		);
}

void	print_data(char **data)
{
	while (*data)
	{
		ft_printf("%s\n", *data);
		++data;
	}
	ft_printf("======================================\n");
}

int		main(int argc, char **argv)
{
	t_data	data;
	int		nb_opt;
	char	**raw_data;
	int		options;

	errno = 0;
	data = (t_data){0};
	if (argc > 1)
	{
		if ((nb_opt = get_options(argv, &options, OPTS, OPTT)) < 0)
			return (exit_failure(NULL));
		if (!(raw_data = read_file(argv[nb_opt])))
			return (exit_failure(NULL));
		if (parse_data(&data, raw_data, options) < 0)
			return (exit_failure(raw_data));
//		print_data(raw_data);
		test(&data);
		for (int i = 0; raw_data[i]; ++i)
			free(raw_data[i]);
		free(raw_data);
	}
	else
		usage();
	return (EXIT_SUCCESS);
}
