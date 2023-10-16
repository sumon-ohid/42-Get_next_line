/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumon <sumon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:21:56 by sumon             #+#    #+#             */
/*   Updated: 2023/10/16 11:55:48 by sumon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
	return (NULL);
}

int	ft_strchr(char *line, char c)
{
	int	i;

	if (!line)
		return (-1);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == c)
			return (i);
		i++;
	}
	if (c == '\0')
		return (i);
	return (-1);
}

char	*ft_strjoin(char *line, char *buffer)
{
	char	*temp;
	int		i;
	int		j;

	temp = (char *)malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(buffer)
				+ 1));
	if (!temp)
		return (NULL);
    if (!line)
        return (ft_strjoin("", ""));
	i = 0;
	while (line[i] != '\0')
	{
		temp[i] = line[i];
		i++;
	}
	j = 0;
	while (buffer[j] != '\0')
	{
		temp[i + j] = buffer[j];
		j++;
	}
	temp[i + j] = '\0';
	return (temp);
}

int	ft_strlen(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i] != '\0')
		i++;
	return (i);
}

char	*get_line(char *line)
{
	int		i;
	char	*temp;
	char	*remain_line;

	i = 0;
    line = ft_strjoin(line, "");
    if (!line)
        return (NULL);
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
	{
		temp = (char *)malloc(sizeof(char) * (i + 1));
		if (!temp)
			return (ft_free(line));
		remain_line = (char *)malloc(sizeof(char) * (ft_strlen(line) - i));
		if (!remain_line)
		{
			free(temp);
			free(line);
			return (NULL);
		}
		i = 0;
		while (line[i] != '\n')
		{
			temp[i] = line[i];
			i++;
		}
		temp[i] = '\0';
		i++;
		remain_line[0] = '\0';
		remain_line = ft_strjoin(remain_line, &line[i]);
		free(line);
		line = remain_line;
		return (temp);
	}
	else
	{
		temp = (char *)malloc(sizeof(char) * (i + 1));
		if (!temp)
			return (ft_free(line));
		i = 0;
		while (line[i] != '\0')
		{
			temp[i] = line[i];
			i++;
		}
		temp[i] = '\0';
		free(line);
		return (temp);
	}
}
