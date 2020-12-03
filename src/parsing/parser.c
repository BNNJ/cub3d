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

static int	get_color(char *s)
{
	int	r;
	int	g;
	int	b;

	if ((r = ft_strtoi(&s)) > 255 || r < 0)
	{
		set_error(EINVAL, "invalid r color value", r);
		return -1;
	}
	if ((g = ft_strtoi(&s)) > 255 || r < 0)
	{
		set_error(EINVAL, "invalid g color value", r);
		return -1;
	}
	if ((b = ft_strtoi(&s)) > 255 || r < 0)
	{
		set_error(EINVAL, "invalid b color value", r);
		return -1;
	}
	return ((r << 16) + (g << 8) + b);
}

static char	first_char(char **line)
{
	while (**line == ' ')
		++*line;
	return (**line);
}

int			parse_truc(char *line)
{
	if (first_char(&line) == 'C')
		data->textures.ceiling = get_color(line + 1);
	else if (first_char(&line) == 'F')
		data->textures.floor = get_color(line + 1);
}
