#ifndef _CUB3D_H_
#define _CUB3D_H_

# define OPTS ("s")
# define OPTT ((char*[2]){	\
	"save",					\
	NULL					\
})


typedef struct	s_data
{
	int	opt;
}				t_data;

char			**read_file(char *file);
int				parse_data(t_data *data, char **raw_data, int options);

#endif