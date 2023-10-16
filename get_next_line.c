#include "get_next_line.h"

char	*get_next_line(int fd)
{
    static char	*line = NULL;
    char		*buffer;
    char		*temp;
    int			read_bytes;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    read_bytes = 1;
    while (!ft_strchr(line, '\n') && read_bytes != 0)
    {
        read_bytes = read(fd, buffer, BUFFER_SIZE);
        if (read_bytes == -1)
        {
            ft_free(buffer);
        }
        buffer[read_bytes] = '\0';
        temp = ft_strjoin(line, buffer);
        free(line);
        line = temp;
    }
    free(buffer);
    return (get_line(line));
}
