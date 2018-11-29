/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:43:36 by guroux            #+#    #+#             */
/*   Updated: 2018/11/29 23:20:30 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*readfile(const int fd, char *str)
{
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;
	int				i;
	int				stop;

	i = 0;
	stop = 1;
	while ((ret = read(fd, buff, BUFF_SIZE)) && stop)
	{
		if (ret < 1)
			return (NULL);
		buff[ret] = '\0';
		while (buff[i] && buff[i] != '\n')
			if (buff[i++] == '\n')
				stop = 0;
		i = 0;
		if (!(tmp = ft_strjoin(str, buff)))
			return (NULL);
		ft_strdel(&str);
		str = tmp;
	}
	return (str);
}

int		cpy_line(char **line, char **str)
{
	char	*tmp;
	int		i;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if (i == 0)
	{
		if (!(*line = ft_strdup("")))
			return (-1);
	}
	else
	{
		if (!(*line = ft_strsub(*str, 0, i)))
			return (-1);
	}
	if (!(tmp = ft_strsub(*str, (i + 1), ft_strlen(*str))))
		return (-1);
	ft_strdel(str);
	*str = tmp;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*str;

	if (fd < 0 || line == NULL)
		return (-1);
	if (!str)
		if (!(str = ft_strdup("")))
			return (-1);
	if (!(str = readfile(fd, str)))
		return (-1);
	if (str[0])
		return (cpy_line(line, &str));
	else
		ft_strdel(&str);
		return (0);
}
