#include <errno.h>
#include "ft_printf.h"

static char	g_err[64];

void		set_error(int errnum, char const *msg, char const* arg)
{
	int	i;

	errno = errnum;
	i = 0;
	if (msg)
	{
		while (*msg && i < 64)
			g_err[i++] = *msg++;
	}
	if (arg && i < 62)
	{
		g_err[i++] = ':';
		g_err[i++] = ' ';
		while (*arg && i < 64)
			g_err[i++] = *arg++;
	}
}

void		print_error(char *proc_name)
{
	ft_dprintf(0, "%s: %s\n", proc_name, g_err);
}
