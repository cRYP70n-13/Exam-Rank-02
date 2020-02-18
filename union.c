#include <unistd.h>

#define SIZE 500

int		main(int argc, char **argv)
{
	int tab[SIZE];
	if (argc == 3)
	{
		for (int i = 0; i < SIZE; i++)
			tab[i] = 0;
		for (int i = 1; i < 3; i++)
			for (int j = 0; argv[i][j]; j++)
				if (!tab[(int)argv[i][j]])
					(tab[(int)argv[i][j]] = 1) && (write(1, &argv[i][j], 1));
	}
	write(1, "\n", 1);
	return (0);
}
