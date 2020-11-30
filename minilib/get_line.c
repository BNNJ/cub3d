#include <stdlib.h>
#include <unistd.h>
#include "minilib.h"
#include "ft_printf.h"

/*
** Basic version of gnl
** Doesn't support multiple fd
** Call with line == NULL to reset it
*/

int			get_line(int fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	static char	*saved = NULL;
	int			endline_pos;
	int			len;

	if (fd < 0)
		return (-1);

	if (line == NULL)
	{
		free(saved);
		saved = NULL;
		return (0);
	}

	if ((endline_pos = find_char('\n', saved)) >= 0)
	{
		*line = ft_substr(saved, 0, endline_pos, 0);
		saved = ft_substr(saved, endline_pos + 1, -1, 1);
	}

	while (endline_pos < 0)
	{
		if ((len = read(fd, buffer, BUFF_SIZE)) < 0)
			return (-1);
		if (len == 0)
			return (0);
		buffer[len] = 0;
		if ((endline_pos = find_char('\n', buffer)) >= 0
			|| (len < BUFF_SIZE && (endline_pos = len)))
		{
			*line = ft_strjoin(saved, ft_substr(buffer, 0, endline_pos, 0), 1);
			saved = ft_substr(buffer, endline_pos + 1, BUFF_SIZE, 0);
		}
		else
			saved = ft_strjoin(saved, buffer, 1);
	}
	return (1);
}
