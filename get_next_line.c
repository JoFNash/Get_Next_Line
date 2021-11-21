/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsybassi <hsybassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:22:07 by hsybassi          #+#    #+#             */
/*   Updated: 2021/11/21 18:01:30 by hsybassi         ###   ########.fr       */
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
	int			read_symbols;

	result_string = NULL;
	read_symbols = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	read_symbols = 1;
	while (read_symbols > 0)
	{
		read_symbols = read(fd, buff, BUFFER_SIZE);
		if (read_symbols <= 0)
			return (NULL);
		buff[read_symbols] = '\0'; 
		if ((ft_strchr_modified(buff, '\n', &place)) == NULL) // если '\n' не нашлось
		{
			if (!result_string)
				result_string = ft_strdup(buff);
			else
				result_string = ft_strjoin(result_string, buff);
		}
		else
		{
			remains = ft_strdup(&(buff[place]));
			free(remains); // типа нашла применение remains
			result_string = get_lost(result_string, buff, place);
			return (ft_strjoin(result_string, "\n"));
		}
		
	}
	return (ft_strjoin(result_string, "\n"));
}






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


