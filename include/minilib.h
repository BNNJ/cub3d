#ifndef _MINILIB_H_
#define _MINILIB_H_

#include <stddef.h>
#include <stdint.h>

#define BUFF_SIZE 64

int		get_options(char **argv, int *opt, char *optstr, char **opttab);
int		get_line(int fd, char **line);
int		find_char(char c, char const *str);

/*
** strings utils
*/

size_t	ft_strlen(char *str);
char	*ft_strdup(const char *s1);
char	*ft_strnew(size_t size);
void	ft_strdel(char **str);
int		ft_strcmp(char const *s1, char const *s2);
char	*ft_strjoin(char *s1, char *s2, uint8_t opt);
char	*ft_substr(char *s, unsigned int start, size_t len, int opt);
int		ft_startswith(char const *s, char const *a);


#endif