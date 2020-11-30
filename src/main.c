#include <stdlib.h>
#include "ft_printf.h"
#include "cub3d.h"
#include "minilib.h"
#include "error.h"

#include <fcntl.h>

int		exit_failure()
{
	print_error("cub3d");
	return (EXIT_FAILURE);
}

void	read_file(char *file)
{
	int 	fd;
	char	*line;

	int		ret;
	int		i = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
	{
		ft_printf("DEBUG: %d\n%s\n%s\n", fd, strerror(errno), file);
		return;
	}
	while ((ret = get_line(fd, &line)) > 0)
	{

		ft_printf("%d: %s\n", i, line);
		++i;
	}
	if (ret < 0)
	get_line(0, NULL);
	close(fd);
}

int		main(int argc, char **argv)
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
		read_file(argv[nb_opt]);
//		parse_data();
//		run();
	}
//	else
//		usage();
	return (EXIT_SUCCESS);
}
