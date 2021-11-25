/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsybassi <hsybassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:22:07 by hsybassi          #+#    #+#             */
/*   Updated: 2021/11/25 21:06:29 by hsybassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

// все strjoin надо проверить на NULL!

void	get_condition_res_str(char *result_string, char buff[])
{
	if (!result_string)
		result_string = ft_strdup(buff);
	else
		result_string = ft_strjoin(result_string, buff);
}

char	*get_next_line(int fd)
{
	char		*result_string;
	static char *remains;
	char 		buff[BUFFER_SIZE + 1];
	size_t		place;
	char		*temp;
	int			read_symbols;

	result_string = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	read_symbols = 1;
	while (read_symbols > 0)
	{
		read_symbols = read(fd, buff, BUFFER_SIZE);
		if (read_symbols < 0)
			return (NULL);
		buff[read_symbols] = '\0';
		if (!remains)
			remains = ft_strdup(buff);
		else
		{
			temp = remains;
			remains = ft_strjoin(remains, buff);
			free(temp);
		}
		if ((ft_strchr_modified(remains, '\n', &place)) != NULL || read_symbols == 0) //  если наткнулись на '\n'
		{
			//printf("place = %ld\n", place);
			result_string = get_result(remains, place);
			remains = get_remains(&remains, place);
			return (result_string);
		}
	}
	
	return (result_string);
}


		// else if (read_symbols == 0)
		// {
		// 	//printf("\n1\n");
		// 	result_string = get_result(remains, place);
		// 	//printf("result_string = \"%s\"\n", result_string);
		// 	free(remains);
		// 	if (result_string)
		// 		remains = NULL;
		// 	//printf("remains = \"%s\"\n", remains);
		// 	return (result_string);
		// }



	// if(....)
	// 	return (NULL);
	// read_symbols = 1;
	// while (read_symbols > 0)
	// {
	// 	read_symbols = read(fd, buff, BUFFER_SIZE)
	// 	if (read_symbols < 0)
	// 		return (NULL);
	// 	buff[read_symbols] = '\0'
	// 	if (!remains)
	// 		remains = ft_strdup(buff);
	// 	else
	// 		remains = ft_strjoin(remains, buff);
	// 	if (ft_strchr(remains, '\n') != NULL)
	// 	{
	// 		result = get_result(remains);
	// 		remains = get_remains(posPtr);
	// 	}
	// }
	// return str;


