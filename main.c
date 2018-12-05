/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:01:13 by guroux            #+#    #+#             */
/*   Updated: 2018/12/05 22:19:28 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		fd;
	char 	*line;

	if (ac)
	{
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &line))
		{
			ft_putstr(line);
			ft_putchar('\n');
			ft_putstr("---\n");
			ft_strdel(&line);
		}
	}
	return (0);
}
