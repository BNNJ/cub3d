#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "cub3d.h"
#include "minilib.h"
#include "error.h"

static void	*ft_memcopy(void *src, void *dest, int len)
{
	char	*s;
	char	*d;

	s = (char*)src;
	d = (char*)dest;
	while (len)
	{
		d[len] = s[len];
		--len;
	}
	return (d);
}

static char	**add_line(char **data, char *line)
{
	static int	cap = 0;
	static int	len = 0;
	char		**new;

	if (len >= cap - 1)
	{
		cap += 32;
		if (!(new = malloc(sizeof(void*) * cap)))
		{
			free(data);
			return (NULL);
		}
		ft_memcopy(data, new, sizeof(void*) * len);
		free(data);
		data = new;
	}
	data[len] = line;
	data[len + 1] = NULL;
	++len;
	return (data);
}

char		**read_file(char *file)
{
	int 	fd;
	char	*line;
	char	**data;
	int		ret;

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		set_error(errno, strerror(errno), file);
		return (NULL);
	}
	data = NULL;
	while ((ret = get_line(fd, &line)) > 0)
	{
		if (!(data = add_line(data, line)))
		{
			set_error(errno, strerror(errno), NULL);
			return (NULL);
		}
	}
	if (ret < 0)
		set_error(errno, strerror(errno), NULL);
	get_line(0, NULL);
	close(fd);
	return (data);
}