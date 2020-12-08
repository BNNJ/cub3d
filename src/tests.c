#include "cub3d.h"
#include "ft_printf.h"

static void print_config(t_config *cfg)
{
	ft_printf("textures:\n\tNO: %s\n\tSO: %s\n\tEA: %s\n\tWE: %s\n\tS:  %s\n\n",
		cfg->textures[0],
		cfg->textures[1],
		cfg->textures[2],
		cfg->textures[3],
		cfg->textures[4]
	);

	ft_printf("colors:\n\tground:\t%hhu,%hhu,%hhu\n\tsky:\t%hhu,%hhu,%hhu\n\n",
		(unsigned char)(cfg->colors[0] >> 16),
		(unsigned char)(cfg->colors[0] >> 8),
		(unsigned char)(cfg->colors[0] >> 0),
		(unsigned char)(cfg->colors[1] >> 16),
		(unsigned char)(cfg->colors[1] >> 8),
		(unsigned char)(cfg->colors[1] >> 0)
	);
}

static void	print_map(t_map *map)
{
	while (*(map->grid))
	{
		ft_printf("%s\n", *(map->grid));
		++(map->grid);
	}
}

void		test(t_data *data)
{
	print_config(&data->cfg);
	print_map(&data->map);
}
