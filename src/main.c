#include <stdlib.h>
#include "ft_printf.h"
#include "cub3d.h"
#include "minilib.h"
#include "error.h"

int		exit_failure()
{
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

void	parse_data(char **data)
{
	for (int i = 0; data[i] != NULL; ++i)
	{
		ft_printf("%s\n", data[i]);
	}
}

int		main(int argc, char **argv)
{
	t_data	data;
	int		nb_opt;
	char	**raw_data;

	data = (t_data){0};
	if (argc > 1)
	{
		nb_opt = get_options(argv, &data.opt, "s", (char*[2]){"save", NULL});
		if (errno != 0)
			return (exit_failure());
		(void)nb_opt;
		if (!(raw_data = read_file(argv[nb_opt])))
			return (exit_failure());
		parse_data(raw_data);
	}
	else
		usage();
	return (EXIT_SUCCESS);
}
