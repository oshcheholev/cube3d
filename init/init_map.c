#include "../include/cub3d.h"

t_map ft_realloc(t_map map, size_t new_size, char *new_line, int index)
{
    char **new_map;
    int i;

    new_map = malloc(sizeof(char *) * new_size);
    if (!new_map)
        return (map);
    i = 0;
    while (i < map.height)
    {
        new_map[i] = map.map[i];
        i++;
    }
    new_map[index] = new_line;
    while (++i < (int)new_size)
        new_map[i] = NULL;
    free(map.map);
    map.map = new_map;
    return (map);
}


int ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

char **add_line(char **map, char *line, int index)
{
	char **new_map;
	int i;

	new_map = malloc(sizeof(char *) * (index + 2));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < index)
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[i] = line;
	new_map[i + 1] = NULL;
	free(map);
	return (new_map);
}

char **remove_line(char **map, int index)
{
	char **new_map;
	int i;
	int j;

	int size;
	size = 0;
	while (map[size])
		size++;
	new_map = malloc(sizeof(char *) * (size));
	if (!new_map)
		return (NULL);
	i = 0;
	j = 0;
	while (map[i])
	{
		if (i != index)
		{
			new_map[j] = map[i];
			j++;
		}
		i++;
	}
	new_map[j] = NULL;
	// free(map[index]);
	// free(map);
	return (new_map);
}

int init_map(t_game *game, char *map_path)
{
    int     fd;
    char    *line;
    int     i;

    fd = open(map_path, O_RDONLY);
    if (fd < 0)
        return (0);
    game->map.map = NULL;
    game->map.width = 0;
    game->map.height = 0;
    i = 0;
	while ((line = get_next_line(fd)))
	{
		game->map.map = add_line(game->map.map, line, i);
		if (!game->map.map)
		{
			free(line);
			close(fd);
			return (0);
		}
		game->map.width = ft_max(game->map.width, ft_strlen(line));
//		printf("Line %d: %s", i, line);
		i++;
	}
		game->map.height = i;
    close(fd);
	game->map.map = remove_line(game->map.map, 0);
    // Debug print the entire map
    // printf("Map width: %d\n", game->map.width);
    // printf("Map height: %d\n", game->map.height);
    // for (int j = 0; j < game->map.height; j++)
    //     printf("Map line %d: %s", j, game->map.map[j]);

    return (1);
}