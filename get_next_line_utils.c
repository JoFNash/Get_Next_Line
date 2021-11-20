/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsybassi <hsybassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:16:43 by hsybassi          #+#    #+#             */
/*   Updated: 2021/11/18 21:38:27 by hsybassi         ###   ########.fr       */
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
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			(*place) = (int)i;
			return ((char *)(&s[i + 1])); // вернула типа указатель на следующий за \n (i + 1)
		}
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

char	*get_lost(char *result_string, char buff[], int place)
{
	size_t	i;
	size_t	j;

	printf("1.I am in get_los()\n");
	printf("1.buff = %s\n", buff);
	printf("1.result_string = %s\n", result_string);

	i = 0;
	j = ft_strlen(result_string);
	while (i < place)
	{
		result_string[j] = buff[i];
		j++;
		i++;
	}
	//result_string[j] = '\n';
	printf("2.buff = %s\n", buff);
	printf("2.result_string = %s\n", result_string);
	return (result_string);
}

// buff[BUFFER_SIZE] = "hell'\n'os"
// size = BUFFER_SIZE
// result_string = "Wow, 12345 r"
// remains = 

// int check_buff_(char buf[], int size, char *result_string, char *remains)
// {
// 	char	*remain;
// 	char	*end_result_string;
// 	size_t	place;
// 	size_t	i;
// 	size_t	j;

// 	if ((remain = ft_strchr_modified(buf, '\n', &place)))
// 	{
// 		remains = ft_strjoin(remains, remain);
// 		if (place != 0)
// 		{
// 			i = 0;
// 			j = ft_strlen(result_string);
// 			while (i < place)
// 			{
// 				result_string[j] = remain[i];
// 				j++;
// 				i++;
// 			}
// 			result_string[j] = '\0';
// 		}
// 		return (1);
// 	}
// 	return (0);
// }




