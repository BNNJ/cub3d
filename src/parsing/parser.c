#include "cub3d.h"
#include "ft_printf.h"
#include "minilib.h"

int		parse_data(t_data *data, char **raw_data, int options)
{
	(void)data;
	while (*raw_data)
	{
		ft_printf("%s\n", *raw_data);
		++raw_data;
	}
	ft_printf("options: %d\n", options);
	return (0);
}
