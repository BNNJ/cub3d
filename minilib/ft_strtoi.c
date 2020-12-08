/*
** skips spaces and commas,
** advances pointer forward until end of number
*/
int	ft_strtoi(char **str)
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
