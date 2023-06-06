/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:34:03 by maltun            #+#    #+#             */
/*   Updated: 2023/03/14 05:31:05 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	char	*ret;
	size_t	i;

	i = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		*s1 = 0;
	}
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (0);
	ret = result;
	while (s1[i])
		*(result++) = s1[i++];
	i = 0;
	while (s2[i])
		*(result++) = s2[i++];
	*result = '\0';
	if (s1)
		free(s1);
	return (ret);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!s)
		return ("");
	if (ft_strlen(s) <= start)
		len = 0;
	else if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (i < len && s[start + i])
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strchr(char *s, int c)
{
	while (*s != (unsigned char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}
