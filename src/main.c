#include <stdlib.h>
#include "ft_printf.h"
#include "cub3d.h"
#include "minilib.h"
#include "error.h"

int	exit_failure()
{
	print_error("cub3d");
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		nb_opt;

	data = (t_data){0};
	if (argc > 1)
	{
		nb_opt = get_options(argv, &data.opt, "s", (char*[2]){"save", NULL});
		if (errno != 0)
			return (exit_failure());
		(void)nb_opt;
//		read_file(argv[1 + nb_opt]);
//		parse_data();
//		run();
	}
//	else
//		usage();
	return (EXIT_SUCCESS);
}
