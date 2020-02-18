#include <unistd.h>

int	main(int ac, char **av)
{
	int		i, j;
	char	used[255];
	if (ac != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	i = -1;
	while (++i < 255)
		used[i] = 0;
	i = 2;
	while (i > 0)
	{
		j = 0;
		while (av[i][j])
		{
			if (i == 2 && !used[(unsigned char)av[i][j]])
				used[(unsigned char)av[i][j]] = 1;
			else if (i == 1 && used[(unsigned char)av[i][j]] == 1)
			{
				used[(unsigned char)av[i][j]] = 2;
				write(1, &av[i][j], 1);
			}
			j++;
		}
		i--;
	}
	write(1, "\n", 1);
	return (0);
}
