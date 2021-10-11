

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
void	*ft_calloc(size_t type, size_t size);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strdup(char *s);
char	*joinfree(char *s1, char *s2);
void	*ft_memmove(void *dest, const void *src, size_t n);
#endif
