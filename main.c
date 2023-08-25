/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livieira <livieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 03:35:00 by livieira          #+#    #+#             */
/*   Updated: 2023/08/25 03:35:37 by livieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*retrn;
	char	input[100];
	char	*keyword = "exit\n";

	fd = open(argv[1], O_RDONLY);
	(void)argc;
	retrn = "";
	while (1)
	{
		printf("\nENTER -> Get next line or type exit to quit.\n\n");
		fgets(input, sizeof(input), stdin);
		if (strcmp(input, keyword) == 0)
		{
			printf("\nBye");
			break ;
		}
		if (retrn != NULL)
		{
			retrn = get_next_line(fd);
			printf("%s", retrn);
			free(retrn);
		}
		else
		{
			printf("\nBye");
			break ;
		}
	}
	close(fd);
	return (0);
}
