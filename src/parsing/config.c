#include <string.h>
#include "minilib.h"
#include "cub3d.h"
#include "error.h"

static int	set_resolution(t_config *cfg, int param, char *s)
{
	(void)param;
	cfg->win_width = ft_strtoi(&s);
	if (cfg->win_width < MIN_WIN_W || cfg->win_width > MAX_WIN_W)
		cfg->win_width = DEF_WIN_W;
	cfg->win_height = ft_strtoi(&s);
	if (cfg->win_height < MIN_WIN_H || cfg->win_height > MAX_WIN_H)
		cfg->win_height = DEF_WIN_H;
	return (0);
}

/*
** TODO : change path storing to actual texture thing
*/
static int	set_texture(t_config *cfg, int param, char *s)
{
	while (*s != ' ')
		++s;
	while (*s == ' ')
		++s;
	if (!(cfg->textures[param - 1] = ft_strdup(s)))
	{
		set_error(errno, strerror(errno), NULL);
		return (-1);
	}
	return (0);
}

/*
** TODO: fix error arg
*/
static int	set_color(t_config *cfg, int param, char *s)
{
	int	r;
	int	g;
	int	b;

	++s;
	if ((r = ft_strtoi(&s)) > 255 || r < 0)
	{
		set_error(EINVAL, "invalid r color value", s);
		return (-1);
	}
	if ((g = ft_strtoi(&s)) > 255 || r < 0)
	{
		set_error(EINVAL, "invalid g color value", s);
		return (-1);
	}
	if ((b = ft_strtoi(&s)) > 255 || r < 0)
	{
		set_error(EINVAL, "invalid b color value", s);
		return (-1);
	}
	cfg->colors[param - 6] = ((r << 16) + (g << 8) + b);
	return (0);
}

int			config(t_config *cfg, int param, char *s)
{
	t_cfg_func	table[NB_PARAMS] = {
		set_resolution,
		set_texture,
		set_texture,
		set_texture,
		set_texture,
		set_texture,
		set_color,
		set_color
	};

	return (table[param](cfg, param, s));
}

/*
** Keeping it there in case new version fails
** can't send data as error arg because it gets freed before use
** TODO: fix that
*/
/*
char**		parse_config(t_config *cfg, char **data)
{
	t_cfg_func	table[NB_PARAMS] = {
		set_resolution,
		set_texture,
		set_texture,
		set_texture,
		set_texture,
		set_texture,
		set_color,
		set_color
	};
	int			param;

	while (*data)
	{
		if ((param = indexof(*data, 
			(void*)PARAMS, NB_PARAMS, str_startswith)) > 0)
		{
			set_error(EINVAL, "Invalid configuration", NULL);
			return (NULL);
		}
		if (table[param](cfg, param, *data) < 0)
			return (NULL);
		else if (**data != 0)
			return (data);
		++data;
	}
	return (data);
}
*/
