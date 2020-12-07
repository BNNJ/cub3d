#include <string.h>
#include "minilib.h"
#include "cub3d.h"
#include "error.h"

static int	ft_strtoi(char **str)
{
	short				sign;
	unsigned long long	result;

	result = 0;
	while (**str == ',' || **str == ' ')
		++*str;
	sign = (**str == '-' || **str == '+') ? -(*(*str)++ - 44) : 1;
	while (**str && **str >= '0' && **str <= '9')
		result = result * 10 + (*(*str)++ - '0');
	return (result * sign);
}

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

static int	set_color(t_config *cfg, int param, char *s)
{
	int	r;
	int	g;
	int	b;

	if ((r = ft_strtoi(&s)) > 255 || r < 0)
	{
		set_error(EINVAL, "invalid r color value", "r");
		return (-1);
	}
	if ((g = ft_strtoi(&s)) > 255 || r < 0)
	{
		set_error(EINVAL, "invalid g color value", "g");
		return (-1);
	}
	if ((b = ft_strtoi(&s)) > 255 || r < 0)
	{
		set_error(EINVAL, "invalid b color value", "b");
		return (-1);
	}
	cfg->colors[param - 5] = ((r << 16) + (g << 8) + b);
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