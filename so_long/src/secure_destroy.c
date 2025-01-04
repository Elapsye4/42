#include "../so_long.h"

static void	secure_destroy_img(void *mlx, void *img)
{
	if (img != NULL)
		mlx_destroy_image(mlx, img);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		if (map[i] != NULL)
			free(map[i]);
		i++;
	}
	if (map != NULL)
		free(map);
}

static void	secure_destroy_window_display(void *mlx, void *window)
{
	if (window != NULL)
		mlx_destroy_window(mlx, window);
	if (mlx != NULL)
	{
		mlx_destroy_display(mlx);
		free(mlx);
	}
}

void	free_all(t_game *game)
{
	secure_destroy_img(game->mlx, game->element.exit.img);
	secure_destroy_img(game->mlx, game->element.gold.img);
	secure_destroy_img(game->mlx, game->element.ground.img);
	secure_destroy_img(game->mlx, game->element.player_left.img);
	secure_destroy_img(game->mlx, game->element.player_right.img);
	secure_destroy_img(game->mlx, game->element.police_left.img);
	secure_destroy_img(game->mlx, game->element.police_right.img);
	secure_destroy_img(game->mlx, game->element.counter.img);
	secure_destroy_img(game->mlx, game->element.wall.img);
	free_map(game->map);
	secure_destroy_window_display(game->mlx, game->window);
}
