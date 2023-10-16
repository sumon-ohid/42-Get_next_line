#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_free(char *line);
int		ft_strchr(char *line, char c);
char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buffer);
int		ft_strlen(char *line);
char	*get_line(char *line);

#endif