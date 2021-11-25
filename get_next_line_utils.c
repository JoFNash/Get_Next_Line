/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsybassi <hsybassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:16:43 by hsybassi          #+#    #+#             */
/*   Updated: 2021/11/25 21:04:32 by hsybassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_modified(const char *s, int c, size_t *place)
{
	size_t	i;

	i = 0;
	*place = 0;
	while (s[i] != '\0')
	{
		*place = i;
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i++;
		if (s[i] == '\0')
			*place = i;
	}
	if (c == '\0')
		return ((char *)(&s[i]));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i] != '\0')
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*get_remains(char **remains, size_t place)
{
	size_t	i;
	size_t	j;
	char	*new_remain;
	
	new_remain = (char *)malloc(sizeof(char) * (ft_strlen(*remains) - place + 1));
	if (!new_remain)
		return (NULL);
	i = place + 1;
	j = 0;
	while ((*remains)[i] != '\0')
	{
		new_remain[j] = (*remains)[i];
		i++;
		j++;
	}
	free(*remains);
	return (new_remain);
}

char	*get_result(char *remains, size_t place)
{
	char	*result_string;
	size_t	i;

	i = 0;
	result_string = (char *)malloc(sizeof(char) * (place + 1));
	if (!result_string)
		return (NULL);
	while (i < place)
	{
		result_string[i] = remains[i];
		i++;
	}
	if (result_string[0] && place <= ft_strlen(remains) - 1)
		result_string[i] = '\n';                       // странно(!)
		// 0000000
	return (result_string);
}
