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
	char		*remain;
	int			read_symbols;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result_string = NULL;
	while ((read_symbols = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		printf("%d\n", read_symbols);
		if ((remain = ft_strchr_modified(buff, '\n', &place)) == NULL && read_symbols == BUFFER_SIZE) // если '\n' не нашлось
		{
			if (!result_string)
				result_string = ft_strdup(buff);
			else
				result_string = ft_strjoin(result_string, buff);
		}
		else
		{
			printf("I am here\n"); // на следующей строке segfault за счет перехода на следующий символ (хотя конец файла)
			remains = ft_strdup(&(buff[place]));
			printf("%s\n", remains);
			result_string = get_lost(result_string, buff, place);
			return (result_string);
		}
	}
	return (result_string);
}
