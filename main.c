#include "get_next_line.h" 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd  = open("test.txt", O_RDONLY);
	printf("RESULT = %s", get_next_line(fd));
	return (0);
}