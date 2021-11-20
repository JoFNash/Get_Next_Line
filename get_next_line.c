/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsybassi <hsybassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:22:07 by hsybassi          #+#    #+#             */
/*   Updated: 2021/11/18 20:22:07 by hsybassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

// все strjoin надо проверить на NULL!

char	*get_next_line(int fd)
{
	char		*result_string;
	static char *remains;
	char 		buff[BUFFER_SIZE];
	size_t		place;
	int			read_symbols;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while ((read_symbols = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		if (read_symbols != BUFFER_SIZE)
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
