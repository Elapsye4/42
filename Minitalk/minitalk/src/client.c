#include "minitalk.h"

static void	send_signal(pid_t id, char *message)
{
	int		i;
	int		j;
	char	result;

	i = 0;
	while (message[i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			result = (message[i] >> j) & 1;
			if (result == 1)
				kill(id, SIGUSR1);
			else if (result == 0)
				kill(id, SIGUSR2);
			usleep(100);
			j--;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_id;

	if (argc == 3)
	{
		server_id = ft_atoi(argv[1]);
		send_signal(server_id, argv[2]);
	}
	else
		write(1, "Le nombre d'arguments renseignés est incorrect.", 47);
	return (0);
}
