/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:39:39 by guroux            #+#    #+#             */
/*   Updated: 2018/11/28 16:42:20 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		check_line(char **str, char **line)
{
	int				i;
	char			*tmp;

	i  = 0;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == '\n')
		{
			if (!(*line = ft_strsub(*str, 0, i)))
				return (-1);
			tmp = ft_strsub(*str, (i + 1), ft_strlen(*str));
			ft_strdel(str);
			*str = tmp;
			return (1);
		}
		i++;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static char		*str;
	int				ret;

	if (!str)
		str = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
		check_line(&str, line);
		return (1);
	}	
	return (1);
}
