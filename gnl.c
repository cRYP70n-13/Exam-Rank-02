#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return len;
}

char	*ft_strjoin(char *str, char buff)
{
	int len;
	char *res;
	int i;

	len = ft_strlen(str);
	i = 0;
	if (!(res = malloc(sizeof(char) * (len + 2))))
		return 0;
	while (str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = buff;
	res[i + 1] = '\0';
	free(str);
	str = NULL;
	return (res);
}

int		get_next_line(char **line)
{
	int read_ret;
	char buff;
	int len;

	len = 0;
	buff = -1;
	if (!(*line = malloc(sizeof(char) * 1)))
		return -1;
	*line[0] = '\0';
	while ((read_ret = read(0, &buff, 1) > 0) && buff != '\n')
	{
		*line = ft_strjoin(*line, buff);
		len++;
	}
	if (len > 0 && buff != '\n')
		return -1;
	if (read_ret == 0 && !buff)
		return 0;
	return 1;
}

int		main()
{
	char *line;

	while (get_next_line(&line) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s\n", line);
	free(line);
	line = NULL;
	return (0);
}
