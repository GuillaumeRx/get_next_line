/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroux <guroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:41:49 by guroux            #+#    #+#             */
/*   Updated: 2018/11/28 18:12:30 by guroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	line = NULL;
	if (ac == 2 )
	{
		fd = open(av[1], O_RDONLY);
		printf("--- Start ---\n");
		while (i++ < 7)
		{
			get_next_line(fd, &line);
			printf("%s\n", line);
			printf("------\n");
		}
	}
	else if (ac < 2)
		printf("No arguments\n");
	else
		printf("Too many arguments");
	return (0);
}