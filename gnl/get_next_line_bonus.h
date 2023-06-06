/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:34:17 by maltun            #+#    #+#             */
/*   Updated: 2023/03/14 04:46:31 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include "unistd.h"
# include "fcntl.h"
# include "stdlib.h"

char	*get_next_line(int fd);
char	*ft_strjoin(char *str, char *str2);
size_t	ft_strlen(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *str);
char	*ft_strchr(char *str, int c);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
#endif
