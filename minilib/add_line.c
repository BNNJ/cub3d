#include <stdlib.h>

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

char		**add_line(char **data, char *line, int *len, int *cap)
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
