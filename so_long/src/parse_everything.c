#include "../so_long.h"

static void	check_extension(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
        {
                if (argv[i] == '.' && argv[i + 1] != 'b' && argv[i + 2] != 'e' && argv[i + 3] != 'r')
                {
                        ft_printf("Error\n");
                        exit(1);
                }
                i++;
        }
}

void	free_error_exit(char **map)
{
	free_map(map);
	ft_printf("Error\n");
	exit(1);
}

static void	check_shape(char **map)
{
	t_position	index;
	int			len_map;

	index.y = 0;
	index.x = 0;
	len_map = ft_strlen(map[0]);
	while (map[index.y] != NULL)
	{
		while (map[index.y][index.x] != '\0')
			index.x++;
		if (index.x != len_map)
			free_error_exit(map);
		index.x = 0;
		index.y++;
	}
}

static void	check_everything(char **map)
{
	check_shape(map);
	check_walls(map);
	check_elements(map);
	check_player(map);
	check_exit(map);
	check_collectibles(map);
	get_size(map);
	check_path(map);
}

void	parse_everything(char **argv)
{
	int		fd;
	char	**map;

	check_extension(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n");
		exit(1);
	}
	map = get_content(fd);
	if (map == NULL)
	{
		ft_printf("Error\n");
		close(fd);
		exit(1);
	}
	check_everything(map);
	free_map(map);
	close(fd);
}
