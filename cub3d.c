#include "include/cub3d.h"

int main(int argc, char **argv)
{
	t_game	game;
	int i = 0;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./cub3d <map.cub>\n", 2);
		return (1);
	}
	if (!init_map(&game, argv[1]))
	{
		ft_putstr_fd("Error: Failed to load map\n", 2);
		return (1);
	}
	// if (!init_mlx(&game))
	// {
	// 	ft_putstr_fd("Error: Failed to initialize mlx\n", 2);
	// 	return (1);
	// }
	// if (!init_player(&game))
	// {
	// 	ft_putstr_fd("Error: Failed to initialize player\n", 2);
	// 	return (1);
	// }
	// if (!init_textures(&game))
	// {
	// 	ft_putstr_fd("Error: Failed to load textures\n", 2);
	// 	return (1);
	// }
	// render(&game);
	printf("Map width: %d\n", game.map.width);
	printf("Map height: %d\n", game.map.height);
	while (game.map.map[i])
	{
		printf("line11111: %s", game.map.map[i]);
		i++;
	}
	return (0);
}