/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:37:31 by msumon            #+#    #+#             */
/*   Updated: 2023/10/17 14:22:58 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line_until_newline(char *line)
{
	char	*str;
	int		i;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_the_rest_after_newline(char *line)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!line)
		return (NULL);
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		buf[BUFFER_SIZE + 1];
	char		*result;
	int			b;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	b = 1;
	while (!ft_strchr(line, '\n') && b > 0)
	{
		b = read(fd, buf, BUFFER_SIZE);
		if (b == -1)
			return (free(line), NULL);
		if (b == 0)
			break ;
		buf[b] = '\0';
		line = ft_strjoin(line, buf);
	}
	if (b == 0 && !line)
		return (NULL);
	result = get_line_until_newline(line);
	line = get_the_rest_after_newline(line);
	return (result);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while (i < 6)
	{
		line = get_next_line(fd);
		printf("line %d = {%s}\n", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
