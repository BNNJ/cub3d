#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "minilib.h"
#include "error.h"
#include "minilib.h"

/*
** meta is len and cap
** why ?
** because norme, that's why
*/
char		**read_file(char *file)
{
	int 	fd;
	char	*line;
	char	**data;
	int		ret;
	int		meta[2] = {0, 0};

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		set_error(errno, strerror(errno), file);
		return (NULL);
	}
	data = NULL;
	while ((ret = get_line(fd, &line)) > 0)
	{
		if (!(data = add_line(data, line, &meta[0], &meta[1])))
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
