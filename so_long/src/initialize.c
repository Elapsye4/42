#include "../so_long.h"

static void	free_exit(t_game *game)
{
	free_all(game);
	exit(1);
}

static void	*secure_map(t_game *game, char *ber)
{
	void	*map;

	map = get_map(ber);
	if (map == NULL)
		free_exit(game);
	return (map);
}

static void	secure_window_mlx(t_game *game, char *title)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		free_exit(game);
	game->window = mlx_new_window(game->mlx, game->size_map.width,
			game->size_map.height, title);
	if (game->window == NULL)
		free_exit(game);
}

static void	*secure_img(t_game *game, char *path, t_img *image)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, path, &image->width, &image->height);
	if (img == NULL)
		free_exit(game);
	return (img);
}

void	initialize(t_game *game, char *ber)
{
	game->player_direction = RIGHT;
	game->steps = 0;
	game->map = secure_map(game, ber);
	get_info(game);
	secure_window_mlx(game, "so_long");
	game->element.exit.img = secure_img(game, "img/exit.xpm", &game->element.exit);
	game->element.gold.img = secure_img(game, "img/gold.xpm",
			&game->element.gold);
	game->element.ground.img = secure_img(game, "img/ground.xpm",
			&game->element.ground);
	game->element.player_left.img = secure_img(game, "img/player_left.xpm",
			&game->element.player_left);
	game->element.player_right.img = secure_img(game, "img/player_right.xpm",
			&game->element.player_right);
	game->element.police_left.img = secure_img(game, "img/police_left.xpm",
			&game->element.police_left);
	game->element.police_right.img = secure_img(game, "img/police_right.xpm",
			&game->element.police_right);
	game->element.counter.img = secure_img(game, "img/counter.xpm",
			&game->element.counter);
	game->element.wall.img = secure_img(game, "img/wall.xpm",
			&game->element.wall);
}
