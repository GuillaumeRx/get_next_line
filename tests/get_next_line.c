/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:43:36 by guroux            #+#    #+#             */
/*   Updated: 2018/12/03 20:08:06 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_list	*select_node(t_list **file, int fd)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", 1);
	tmp->content_size = fd;
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

//Is reading bytes after the end of file wtf -_-,
char	*readfile(const int fd, char *str)
{
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;
	int				i;

	i = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret < 1)
			return (NULL);
		buff[ret] = '\0';
		printf("buff: %s\n", buff);
		if (!(tmp = ft_strjoin(str, buff)))
			return (NULL);
		ft_strdel(&str);
		str = tmp;
		while (buff[i] != '\0')
			if (buff[i++] == '\n')
				return (str);
		i = 0;
	}
	printf("str: %s\n", str);
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
	static t_list		*file;
	t_list				*curr;
	char				*str;

	if (fd < 0 || line == NULL)
		return (-1);
	curr = select_node(&file, fd);
	if (!(curr->content = readfile(fd, curr->content)))
		return (-1);
	str = curr->content;
	printf("str :%s\n", str);
	if (str[0] != '\0')
		return (cpy_line(line, (char **)&(curr->content)));
	else
		ft_strdel((char **)&(curr->content));
		return (0);
}
