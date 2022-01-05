/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsybassi <hsybassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 20:14:10 by hsybassi          #+#    #+#             */
/*   Updated: 2022/01/05 18:50:13 by hsybassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h" 

char	*get_remains(char **remains)
{
	size_t	i;
	char	*new_remain;

	if (!remains || !*remains)
		return (NULL);
	i = 0;
	while ((*remains)[i] && ((*remains)[i] != '\n'))
		i++;
	new_remain = ft_substr(*remains, i + 1, ft_strlen(*(remains) + i + 1));
	if (!new_remain)
		return (NULL);
	free(*remains);
	return (new_remain);
}

char	*get_result(char *remains)
{
	char	*result_string;
	size_t	i;

	if (!remains || !*remains)
		return (NULL);
	i = 0;
	result_string = NULL;
	while (remains[i] && remains[i] != '\n')
		i++;
	if (i == ft_strlen(remains))
	{
		result_string = ft_strdup(remains);
		if (!result_string)
			return (NULL);
	}
	else if (i < ft_strlen(remains))
	{
		result_string = ft_substr(remains, 0, i + 1);
		if (!result_string)
			return (NULL);
	}
	return (result_string);
}

char	*get_res_and_remain(char **remains)
{
	char		*result_string;

	result_string = get_result(*remains);
	*remains = get_remains(&(*remains));
	if (result_string == NULL)
	{
		free(*remains);
		*remains = NULL;
	}
	return (result_string);
}

int	get_temp_and_free_remains(char **temp, char *buff, char **remains)
{
	*temp = ft_strjoin(*remains, buff);
	if (!(*temp))
		return (0);
	free(*remains);
	*remains = *temp;
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*remains[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	char		*temp;
	int			read_symbols;

	if (fd < 0 || BUFFER_SIZE <= 0
		|| BUFFER_SIZE > 1000000 || read(fd, 0, 0) < 0)
		return (NULL);
	read_symbols = 1;
	while (read_symbols > 0)
	{
		read_symbols = read(fd, buff, BUFFER_SIZE);
		buff[read_symbols] = '\0';
		if (!remains[fd])
		{
			remains[fd] = ft_strdup(buff);
			if (!remains[fd])
				return (NULL);
		}
		else if (get_temp_and_free_remains(&temp, buff, &remains[fd]) == 0)
			return (NULL);
		if (ft_strchr(remains[fd], '\n'))
			break ;
	}
	return (get_res_and_remain(&remains[fd]));
}
