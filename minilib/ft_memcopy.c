
void	*ft_memcopy(void *src, void *dest, int len)
{
	char	*s;
	char	*d;

	s = (char*)src;
	d = (char*)dest;
	while (--len >= 0)
		d[len] = s[len];
	return (d);
}
