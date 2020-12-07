#include "cub3d.h"
#include "ft_printf.h"
#include "minilib.h"
#include "error.h"

static int	get_param(char const *line)
{
	char const	*params[NB_PARAMS] = {
		"R ",
		"NO ",
		"SO ",
		"WE ",
		"EA ",
		"S ",
		"F ",
		"C "
	};
	int			i;

	i = 0;
	while (i < NB_PARAMS)
	{
		if (ft_startswith(line, params[i]))
			return (1 << i);
		++i;
	}
	set_error(EINVAL, "Invalid configuration", line);
	return (-1);
}

int			parse_data(t_data *data, char **raw_data, int options)
{
	(void)options;
	int	param;

	while (*raw_data)
	{
		if ((param = get_param(*raw_data)) > 0
			&& config(&data->cfg, param, *raw_data))
			return (-1);
		else if (**raw_data != 0)
			break;
		++raw_data;
	}
	while (*raw_data)
	{
		//parse map
		++raw_data;
	}
	return (0);
}
