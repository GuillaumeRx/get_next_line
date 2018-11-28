/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:43:36 by guroux            #+#    #+#             */
/*   Updated: 2018/11/28 18:22:48 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readfile(const int fd, char *str)
{
	while((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
	}
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	static char		*str;
	char			*tmp;
	int				i;
	char			buff[BUFF_SIZE + 1];
	int				ret;
	
	i = 0;
	if (str[i])
	{
		while (str[i] != '\n' && str[i])
			i++;
		if (i == 0)
			*line = ft_strnew(0);
		else
		{
			*line = ft_strsub(str, 0, i);
			tmp = ft_strsub(str, (i + 1), ft_strlen(str));
			ft_strdel(&str);
			str = tmp;
		}
			return (1);
	}
	else
		*line = ft_strnew(0);
	return (0);
}