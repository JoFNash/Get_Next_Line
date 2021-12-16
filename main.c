#include "get_next_line.h" 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	int fd1;

	fd = open("test.txt", O_RDONLY);
	char *str = get_next_line(fd);

	printf("RESULT = %s", str);
	// if (strcmp(str, "0123456789012345678901234567890123456789\n") == 0)
	// 	printf("+");
	// else
	// 	printf("-");

	str = get_next_line(fd);
	printf("RESULT = %s", str);

	str = get_next_line(fd);
	printf("RESULT = %s", str);

	//str = get_next_line(fd);
	//printf("RESULT = %s", str);

	//str = get_next_line(fd);
	//printf("RESULT = %s", str);

	//str = get_next_line(fd);
	//printf("RESULT = %s", str);

	free(str);

	return (0);
}