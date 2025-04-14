
#ifndef CUB3D_H
# define CUB3D_H
# include "../utils/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <fcntl.h>
# include <stddef.h>


typedef struct s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
}				t_img;

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
}				t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		dir_x;
	int		dir_y;
}				t_player;

typedef struct s_ray
{
	int		x;
	int		y;
	int		dir_x;
	int		dir_y;
}				t_ray;

typedef struct s_texture
{
	int		width;
	int		height;
	int		*data;
}				t_texture;

typedef struct s_key
{
	int		up;
	int		down;
	int		left;
	int		right;
}				t_key;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}				t_mlx;
typedef struct s_game
{
	t_mlx		mlx;
	t_map		map;
	t_player	player;
	t_ray		ray;
	t_texture	texture[5];
	t_key		key;
}				t_game;


// typedef struct s_data
// {
// }				t_data;

char	*get_next_line(int fd);
int init_map(t_game *game, char *map_path);

void ft_putstr_fd(char *s, int fd);
char *ft_strcpy(char *src);




#endif
