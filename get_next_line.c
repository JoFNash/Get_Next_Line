#include "get_next_line.h" 

char	*get_next_line(int fd)
{
	char		*string;
	static char *buf; 	

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	while (read(fd, buf, BUFFER_SIZE) != EOF) 
	{
    	printf("%s", buf);
	}
	string = NULL;
	return (string);
}
