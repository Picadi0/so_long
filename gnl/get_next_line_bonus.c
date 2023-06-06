/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:33:45 by maltun            #+#    #+#             */
/*   Updated: 2023/03/14 05:55:11 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	until_next_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	check_errors(char **str, int buffer, char *strbuffer)
{
	if (buffer == -1 || !ft_strlen(*str))
	{
		if (*str)
			free(*str);
		free(strbuffer);
		*str = 0;
		return (1);
	}
	return (0);
}

char	*ft_read(int fd, char **str, char **tmp)
{
	int			buffer;
	char		*strbuffer;

	strbuffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!ft_strchr(*str, '\n'))
	{
		buffer = read(fd, strbuffer, BUFFER_SIZE);
		if (buffer <= 0)
			break ;
		strbuffer[buffer] = 0;
		*str = ft_strjoin(*str, strbuffer);
	}
	if (check_errors(&*str, buffer, strbuffer))
		return (NULL);
	if (ft_strlen(strbuffer) != (size_t)buffer)
	{
		*tmp = ft_substr(*str, 0, ft_strlen(*str) - (size_t)buffer);
		free(*str);
		*str = *tmp;
	}
	free(strbuffer);
	return (ft_substr(*str, 0, until_next_line(*str) + 1));
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*tmp;
	int			until;

	tmp = NULL;
	if (fd < 0)
		return (NULL);
	if (!str[fd])
	{
		str[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		*str[fd] = 0;
	}
	until = ft_strlen(str[fd]) - until_next_line(str[fd]);
	tmp = ft_substr(str[fd], until_next_line(str[fd]) + 1, until);
	free(str[fd]);
	str[fd] = tmp;
	return (ft_read(fd, &str[fd], &tmp));
}
