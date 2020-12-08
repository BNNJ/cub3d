#ifndef _MINILIB_H_
#define _MINILIB_H_

#include <stddef.h>
#include <stdint.h>

#define BUFF_SIZE 64

/*
** big stuff
*/
char	**add_line(char **data, char *line, int *len, int *cap);
int		get_options(char **argv, int *opt, char *optstr, char **opttab);
int		get_line(int fd, char **line);

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

/*
** indexof
** and some compare functions to pass to indexof
** TODO: remove if not used
*/

int		indexof(void *s, void **table, int len, int (*cmp)(void*, void*));
int		str_eq(void *s1, void *s2);
int		str_startswith(void *str, void *start);

/*
** misc
*/

int		find_char(char c, char const *str);
int		ft_strtoi(char **str);
void	*ft_memcopy(void *src, void *dest, int len);

#endif