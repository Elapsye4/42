#include "../so_long.h"

static void	put_image_bonus(t_game *game, char character, t_position pos)
{
	if (character == E_LEFT)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->element.police_left.img,
			pos.x * 48, pos.y * 48);
	}
	else if (character == E_RIGHT)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->element.police_right.img,
			pos.x * 48, pos.y * 48);
	}
	else if (character == WALL && pos.x == 2 && pos.y == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->element.counter.img, pos.x * 48, pos.y * 48);
}

void	put_image(t_game *game, char character, t_position pos)
{
	if (character == EMPTY)
		mlx_put_image_to_window(game->mlx, game->window,
			game->element.ground.img, pos.x * 48, pos.y * 48);
	else if (character == WALL)
		mlx_put_image_to_window(game->mlx, game->window, game->element.wall.img,
			pos.x * 48, pos.y * 48);
	else if (character == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->window,
			game->element.gold.img, pos.x * 48, pos.y * 48);
	else if (character == EXIT)
		mlx_put_image_to_window(game->mlx, game->window, game->element.exit.img,
			pos.x * 48, pos.y * 48);
	else if (character == PLAYER)
	{
		if (game->player_direction == RIGHT)
			mlx_put_image_to_window(game->mlx, game->window,
				game->element.player_right.img, pos.x * 48,
				pos.y * 48);
		else
			mlx_put_image_to_window(game->mlx, game->window,
				game->element.player_left.img, pos.x * 48,
				pos.y * 48);
	}
	put_image_bonus(game, character, pos);
}

int	display_map(t_game *game)
{
	t_position	pos;

	pos.y = 0;
	while (game->map[pos.y] != NULL)
	{
		pos.x = 0;
		while (game->map[pos.y][pos.x] != '\0')
		{
			put_image(game, game->map[pos.y][pos.x], pos);
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}
