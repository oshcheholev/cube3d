#include "../include/cub3d.h"

int init_mlx(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	if (!game->mlx.mlx_ptr)
		return (0);
	game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr, game->map.width, game->map.height, "Cub3D");
	if (!game->mlx.win_ptr)
		return (0);
	game->mlx.img.img_ptr = mlx_new_image(game->mlx.mlx_ptr, game->map.width, game->map.height);
	if (!game->mlx.img.img_ptr)
		return (0);
	game->mlx.img.data = (int *)mlx_get_data_addr(game->mlx.img.img_ptr, &game->mlx.img.bpp, &game->mlx.img.size_line, &game->mlx.img.endian);
	if (!game->mlx.img.data)
		return (0);
	return (1);
}