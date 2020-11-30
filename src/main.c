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

t_data	parse_data(char **data, int options)
{
	t_data	d;

	d = (t_data){options};
	for (int i = 0; data[i] != NULL; ++i)
	{
		ft_printf("%s\n", data[i]);
	}
	return (d);
}

int		main(int argc, char **argv)
{
	t_data	data;
	int		nb_opt;
	char	**raw_data;
	int		options;

	if (argc > 1)
	{
		nb_opt = get_options(argv, &options, "s", (char*[2]){"save", NULL});
		if (nb_opt < 0)
			return (exit_failure());
		(void)nb_opt;
		if (!(raw_data = read_file(argv[nb_opt])))
			return (exit_failure());
		data = parse_data(raw_data, options);
		(void)data;
	}
	else
		usage();
	return (EXIT_SUCCESS);
}
