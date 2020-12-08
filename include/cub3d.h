#ifndef _CUB3D_H_
#define _CUB3D_H_

# define OPTS		("s")
# define NB_OPTS	1
# define OPTT		((char*[NB_OPTS + 1]){	\
						"save",						\
						NULL						\
					})

# define MIN_WIN_H	0
# define MAX_WIN_H	1080
# define DEF_WIN_H	(MAX_WIN_H / 2)
# define MIN_WIN_W	0
# define MAX_WIN_W	1920
# define DEF_WIN_W	(MAX_WIN_W / 2)


# define NB_PARAMS	8
# define PARAMS		((char*[NB_PARAMS + 1]){	\
						"R ",						\
						"NO ",						\
						"SO ",						\
						"WE ",						\
						"EA ",						\
						"S ",						\
						"F ",						\
						"C ",						\
						NULL						\
					})

# define print(s)	ft_printf("%s\n", s)

typedef struct	s_config
{
	int			win_height;
	int			win_width;
	char		*textures[5];
	int			colors[2];
}				t_config;

typedef struct	s_map
{
	char		**grid;
	int			lines;
}				t_map;

typedef struct	s_data
{
	int			opt;
	t_config	cfg;
	t_map		map;
}				t_data;

typedef int		(*t_cfg_func)(t_config*, int, char*);

char			**read_file(char *file);
int				parse_data(t_data *data, char **raw_data, int options);
int				config(t_config *cfg, int param, char *s);
int				parse_line(t_map *map, char *line);


/*
** don't think so
*/
//char**			parse_config(t_config *cfg, char **data);

#endif