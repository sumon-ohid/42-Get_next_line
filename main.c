/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumon <sumon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:09:34 by sumon             #+#    #+#             */
/*   Updated: 2023/10/16 09:05:08 by sumon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
    int		fd;
    char	*line;

    fd = open("file.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    line = get_next_line(fd);
    while (line != NULL)
    {
        printf("%s\n", line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (0);
}

