/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:48:23 by msumon            #+#    #+#             */
/*   Updated: 2023/10/17 14:06:50 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strdup(char *line)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(line) + 1;
	str = (char *)malloc(len * sizeof(*str));
	if (!str)
		return (NULL);
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(char *line, char c)
{
	char	*str;
	int		i;

	i = 0;
	if (!line)
		return (NULL);
	if (c == 0)
		return (&line[ft_strlen(line)]);
	str = line;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == c)
		return (&str[i]);
	if (!c && str[i] == '\0')
		return (&str[i]);
	return (NULL);
}

char	*ft_strjoin(char *line, char *buffer)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!line)
		return (ft_strdup(buffer));
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(buffer)
				+ 1));
	if (!str)
		return (NULL);
	while (line[i])
		str[j++] = line[i++];
	i = 0;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(line);
	line = NULL;
	return (str);
}
