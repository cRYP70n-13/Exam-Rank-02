#include <unistd.h>

int		main(int argc, char **argv)
{
	int		tab[256];
	int i = -1;
	int j;

	if (argc == 3)
	{
		while (i++ < 256)
			tab[i] = 0;
		i = 1;
		while (argv[2][j]) {
			tab[(unsigned int)argv[2][j]] = 1;
			j++;
		}
		j = 0;
		while (argv[1][j]) {
			if (tab[(unsigned int)argv[1][j]]) {
				write(1, &argv[1][j], 1);
				tab[(unsigned int)argv[i][j]] = 0;
			}
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
