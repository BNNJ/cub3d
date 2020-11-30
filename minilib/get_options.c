#include "error.h"
#include "minilib.h"
#include "ft_printf.h"

static int	match_short_opt(char *arg, char *opts)
{
	int	opt;
	int	c;

	opt = 0;
	while (*arg)
	{
		if ((c = find_char(*arg, opts)) >= 0)
			opt |= (1 << c);
		else
		{
			set_error(EINVAL, "invalid option", arg);
			return (0);
		}
		++arg;
	}
	return (opt);
}

static int	match_long_opt(char *arg, char **opts)
{
	int	i;

	i = 0;
	while (opts[i])
	{
		if (ft_strcmp(arg, opts[i]) == 0)
			return (1 << i);
		++i;
	}
	set_error(EINVAL, "invalid option", arg);
	return (0);
}

int			get_options(char **argv, int *opt, char *optstr, char **opttab)
{
	int		nb_arg;
	char	*arg;

	*opt = 0;
	nb_arg = 0;
	while ((arg = argv[++nb_arg]) && *arg == '-')
	{
		if (arg[1] == '-' && arg[2] == '\0')
			break;
		if (arg[1] == '-' && opttab)
			*opt |= match_long_opt(arg + 2, opttab);
		else if (optstr)
			*opt |= match_short_opt(arg + 1, optstr);
		if (errno != 0)
			break;
	}
	return (nb_arg);
}
