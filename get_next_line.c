#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

size_t	ft_strlen(const char *str)
{
	size_t i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int i = 0;
	char *str;

	str = malloc(ft_strlen(s) + 1);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return (char *)s;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*p;
	unsigned int		i;

	i = 0;
	if (ft_strlen(s) < start)
		len = 0;
	p = malloc(len + 1);
	while (len--)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (char *)(p);
}

char	*ft_strjoin(char *s1, char *s2)
{

	int i = 0;
	int j = 0;
	char *str;

	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int get_next_line(char **line)
{
	static char *rest;
	char buffer[127];

	if (!rest)
		rest = ft_strdup("");
	char *tmp;
	while (!ft_strchr(rest, '\n'))
	{
		int ret = read(0 , buffer, 126);
		buffer[ret] = '\0';
		tmp = rest;
		rest =  ft_strjoin(rest, buffer);
		free(tmp);
		if (ret == 0)
			break ;
	}
	if (ft_strchr (rest, '\n'))
	{
		char *f = ft_strchr(rest, '\n');
		int len = f - rest;

		*line =  ft_substr(rest, 0, len);
		tmp = rest;
		rest = ft_strdup(f + 1);
		free(tmp);
		return 1;
	}
	else
	{
		*line = ft_strdup(rest);
		free(rest);
		rest = NULL;
		return 0;
	}
}

int main(void)
{

	char *line;
	while (get_next_line(&line))
	{
		printf("%s\n", line);
	}
	return (0);
}
