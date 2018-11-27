/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:41:49 by guroux            #+#    #+#             */
/*   Updated: 2018/11/27 17:07:53 by guroux           ###   ########.fr       */
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
		printf("%d\n", get_next_line(fd, &line));
		printf("%s\n", line);
	}
	else if (ac < 2)
		printf("No arguments\n");
	else
		printf("Too many arguments");
	return (0);
}