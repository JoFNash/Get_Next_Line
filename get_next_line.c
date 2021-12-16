/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsybassi <hsybassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:22:07 by hsybassi          #+#    #+#             */
/*   Updated: 2021/12/16 21:41:04 by hsybassi         ###   ########.fr       */
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
	char		*result_string = NULL;
	static char *remains;
	char 		buff[BUFFER_SIZE + 1];
	//size_t		place;
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
			// temp = remains;
			// remains = ft_strjoin(remains, buff);
			// free(temp);
			temp = ft_strjoin(remains, buff);
			free(remains);
			remains = temp;
		}
		
		if ((ft_strchr(remains, '\n')) != NULL || read_symbols == 0) // если наткнулись на '\n'
		{
			break ;
			// result_string = get_result(remains); 
			// remains = get_remains(&remains);
			// return (result_string);
		}
	}
	result_string = get_result(remains); 
			remains = get_remains(&remains);
	return (result_string);
}

// printf("remains = %s", remains);