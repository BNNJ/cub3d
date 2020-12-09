#include "minilib.h"
#include "cub3d.h"
#include "error.h"

static int	check_walls(char *line, int i)
{
	if ((i > 0 && line[i - 1] == '0') || line[i + 1] == '0')
	{
		set_error(EINVAL, "Map is not walled off", NULL);	
		return (-1);
	}
	return (0);
}

int		parse_line(char *line, int top_or_bottom)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (line[i])
	{
		if (line[i] == MAP_CHARS[0] && check_walls(line, i))
			return (-1);
		else if (top_or_bottom && line[i] == '0')
		{
			set_error(EINVAL, "Map is not walled off", NULL);
			return (-1);
		}
		else if (find_char(line[i], MAP_CHARS) < 0)
		{
			set_error(EINVAL, "Invalid character in map", &line[i]);
			return (-1);
		}
		else if (find_char(line[i], "NSEW") >= 0)
			x = i;
		++i;
	}
	return (x);
}
