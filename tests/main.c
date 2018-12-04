/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:41:49 by guroux            #+#    #+#             */
/*   Updated: 2018/12/03 20:12:16 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		ret;

	line = NULL;
	if (ac == 2 )
	{
		fd = open(av[1], O_RDONLY);
		while ((ret = get_next_line(fd, &line)))
		{
			printf("ret: %d\n", ret);
			printf("%s\n", line);
			ft_strdel(&line);
			printf("-------------\n");
		}
	}

	return (0);
}