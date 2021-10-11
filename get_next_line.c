
#include "get_next_line.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static	int	ft_search_ch(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static	int	ft_getline(int index, char *reste, char **line)
{
	int	len;

	*line = ft_substr(reste, 0, index);
	index++;
	len = ft_strlen(reste + index) + 1;
	reste = ft_memmove(reste, reste + index, len);
	return (1);
}

static	void	ft_clean(char **reste, char **line)
{
	if (reste)
	{
		*line = ft_strdup(*reste);
		free (*reste);
		*reste = NULL;
	}
	else
		*line = ft_strdup("");
}

int	get_next_line(int fd, char **line)
{
	static char	*reste = NULL;
	char		buf[BUFFER_SIZE + 1];
	int			lu;
	int			index;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	lu = 1;
	if (reste && ft_search_ch(reste, '\n') != -1)
	{
		index = ft_search_ch(reste, '\n');
		return (ft_getline(index, reste, line));
	}
	while (lu > 0)
	{
		lu = read(fd, buf, BUFFER_SIZE);
		buf[lu] = '\0';
		reste = ft_joinfree(reste, buf);
		index = ft_search_ch(reste, '\n');
		if (index != -1)
			return (ft_getline(index, reste, line));
	}
	ft_clean(&reste, line);
	return (0);
}
