#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc > 2 || !argv[1])
	{
		ft_printf("Error\n");
		exit(1);
	}
	parse_everything(argv);
	initialize(&game, argv[1]);
	display_map(&game);
	mlx_key_hook(game.window, handle_input, &game);
	mlx_hook(game.window, 17, 0, mlx_loop_end, game.mlx);
	mlx_loop(game.mlx);
	free_all(&game);
	return (0);
}
