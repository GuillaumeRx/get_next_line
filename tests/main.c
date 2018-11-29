/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:41:49 by guroux            #+#    #+#             */
/*   Updated: 2018/11/29 23:24:48 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd;

	line = NULL;
	if (ac == 2 )
	{
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &line))
			ft_strdel(&line);
	}

	return (0);
}