/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsybassi <hsybassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:16:43 by hsybassi          #+#    #+#             */
/*   Updated: 2021/12/16 21:15:31 by hsybassi         ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i++;
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start > size)
		len = 0;
	else if (start + len > size)
		len = size - start;
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	i = 0;
	while (i < len)
	{
		string[i] = s[i + start];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*get_remains(char **remains)
{
	size_t	i;
	char	*new_remain;
	size_t len;

	len = 0;
	i = 0;
	while((*remains)[i] && ((*remains)[i] != '\n' && (*remains)[i] != '\0'))
	{
		len++;
		i++;
	}
	new_remain = ft_substr(*remains, len + 1, ft_strlen((*remains)) - len);
	if (!new_remain)
		return (NULL);
	free(*remains);
	return (new_remain);
}

char	*get_result(char *remains)
{
	char	*result_string;
	size_t	i;
	size_t len;

	len = 0;
	i = 0;
	while(remains[i] && (remains[i] != '\n' && remains[i] != '\0'))
	{
		len++;
		i++;
	}
	result_string = ft_substr(remains, 0, len + 1);
	if (!result_string)
		return (NULL);
	if (ft_strlen(result_string) == 0)
	{
		free(result_string);
		if (remains != NULL)
			free(remains);
		return (NULL);
	}
	return (result_string);
}
