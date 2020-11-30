#include <stdlib.h>
#include <stdint.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dest;

	len = 0;
	while (s1[len])
		++len;
	if (!(dest = (char*)malloc(len + 1)))
		return (NULL);
	while (*s1)
		*dest++ = *s1++;
	*dest = '\0';
	return (dest - len);
}

char	*ft_strnew(size_t size)
{
	char	*str;

	str = malloc(sizeof(char) * size + 1);
	str[size] = 0;
	return (str);
}

void	ft_strdel(char **str)
{
	if (str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

int		ft_strcmp(char const *s1, char const *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char	*ft_strjoin(char *s1, char *s2, uint8_t opt)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1 && !s2)
		return (NULL);
	else if (s1 && !s2)
		return (opt & 1 ? s1 : ft_strdup(s1));
	else if (!s1 && s2)
		return (opt & 2 ? s2 : ft_strdup(s2));
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	if (opt & 1)
		ft_strdel(&s1);
	if (opt & 2)
		ft_strdel(&s2);
	return (str);
}

char	*ft_substr(char *s, unsigned int start, int len, int opt)
{
	char	*substr;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (len < 0)
	{
		len = ft_strlen(s) - start;
	}
	if (!(substr = malloc(len + 1)))
		return (NULL);
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		++i;
	}
	substr[i] = '\0';
	if (opt == 1)
		ft_strdel(&s);
	return (substr);
}
