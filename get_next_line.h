#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 5

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*get_lost(char *result_string, char buff[], size_t place);
char	*get_result(char *remains);
char	*get_remains(char **remains);

#endif
