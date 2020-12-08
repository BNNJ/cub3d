int	str_startswith(void *str, void *start)
{
	char const	*s = (char*)str;
	char const	*a = (char*)start;
	if (!a || !s)
		return (0);
	while (*a)
	{
		if (*a != *s)
			return (0);
		++a;
		++s;
	}
	return (1);
}

int	str_eq(void *s1, void *s2)
{
	char const	*a = (char*)s1;
	char const	*b = (char*)s2;

	while (*a == *b)
	{
		++a;
		++b;
	}
	return (*a == *b);
}

int	indexof(void *s, void **table, int len, int (*cmp)(void*, void*))
{
	int			i;

	i = 0;
	while (i < len)
	{
		if (cmp(s, table[i]))
			return (i);
		++i;
	}
	return (-1);
}
