#include "cub3d.h"
#include "ft_printf.h"
#include "minilib.h"
#include "error.h"

static int		get_param(char const *line)
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
			return (i);
		++i;
	}
	set_error(EINVAL, "Invalid configuration", line);
	return (-1);
}

static char**	parse_config(t_config *cfg, char **data)
{
	int	param;
	int	i;

	i = 0;
	while (i < NB_PARAMS)
	{
		if (**data)
		{
			if ((param = get_param(*data)) < 0 || config(cfg, param, *data) < 0)
				return (NULL);
			++i;
		}
		++data;
	}
	while (**data == 0)
		++data;
	return (data);
}

static int		parse_map(t_map *map, char **data)
{
//	int	w;
	int	l;

	l = 0;
	while (data[l])
	{
		if (parse_line(map, data[l]) < 0)
			return (-1);
		++l;
	}
	if (!(map->grid = malloc(sizeof(char*) * l)))
	{
		set_error(errno, strerror(errno), NULL);
		return (-1);
	}
	ft_memcopy(data, map->grid, sizeof(char*) * l);
	map->lines = l;
	return (0);
}

int				parse_data(t_data *data, char **raw_data, int options)
{
	(void)options;

	if (!(raw_data = parse_config(&data->cfg, raw_data)))
		return (-1);
//	for (int i = 0; raw_data[i]; ++i)
//		print(raw_data[i]);
	if ((parse_map(&data->map, raw_data)) < 0)
		return (-1);
	return (0);
}
