
int	find_char(char c, char const *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (c == str[i])
			return (i);
		++i;
	}
	return (-1);
}
