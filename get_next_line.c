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

//

char	*get_next_line(int fd)
{
	char		*result_string;
	static char *remains; 	
	char 		buff[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (read(fd, buff, BUFFER_SIZE) > 0)
	{
    	if (check_buff_(buff, BUFFER_SIZE, result_string) == 1)
		{
			//copy_buff_to_remains(buff, remains);
			return ("OK");
		}
		else
		{
			if (!(result_string = ft_strjoin(result_string, buff)))
				return (NULL);
		}
	}
	result_string = NULL;
	return (result_string);
}
