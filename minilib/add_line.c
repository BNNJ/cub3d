#include <stdlib.h>
#include "minilib.h"

char	**add_line(char **data, char *line, int *len, int *cap)
{
	char	**new;

	if (*len >= *cap - 1)
	{
		*cap += 32;
		if (!(new = malloc(sizeof(void*) * *cap)))
		{
			free(data);
			return (NULL);
		}
		ft_memcopy(data, new, sizeof(void*) * *len);
		free(data);
		data = new;
	}
	data[*len] = line;
	data[*len + 1] = NULL;
	++*len;
	return (data);
}
