#include "get_next_line.h" 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	int fd1;

	//printf("0\n");

	fd = open("test.txt", O_RDONLY);

	printf("RESULT = -%s-\n", get_next_line(fd));
	printf("RESULT = -%s-\n", get_next_line(fd));	

	return (0);
}