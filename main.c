/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 14:31:16 by cgutierr          #+#    #+#             */
/*   Updated: 2021/02/07 19:02:20 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file is being used for testing purposes
**
** We check if the given fd passed as an argument is valid
** If it's valid, we test the get_next_line function printing each line
** followed by a '\n'
**
** Needed arguments: Executable followed by the required fd
** For debbugging purposes:
** 		gcc -g3 -fsanitize=address -D BUFFER_SIZE=6 get_next_line.c main.c && ./a.out fd
*/

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
int main(int argc, char **argv)
{
	int x;
	int fd;
	char *line;

	if (argc == 2 || argc == 3 || argc == 4)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			printf("Error: couldn't open fd \"%s\"\n", argv[1]);
			return (1);
		}
		else
		{
			x = 0;
			int j;
			printf("TEST WITH BUFFER_SIZE=%d\n________________________________\n\tSTART OF FILE\n________________________________\n", BUFFER_SIZE);
			while ((j = get_next_line(fd, &line)) == 1)
			{
				x++;
				if (argc == 4)
				{
					if (!strcmp(argv[3], "--lines"))
						printf("Line %d\t|%d|\t$>%s$\n", x, j, line);
					else
						printf("%s\n", line);
				}
				else
					printf("%s\n", line);
				free(line);
			}
			x++;
			if (argc == 4)
			{
				if (!strcmp(argv[3], "--lines"))
					printf("Line %d\t|%d|\t$>%s$\n", x, j, line);
				else
					printf("%s]n", line);
			}
			else
				printf("%s\n", line);
			printf("\n________________________________\n\tEND OF FILE\n________________________________\n");
			close(fd);
		}

		if (argc >= 3)
		{
			if (!strcmp(argv[2], "--leaks"))
			{
				printf("\nSYSTEM LEAKS OF [%s %s]\n\n", argv[0], argv[1]);
				system("leaks a.out");
			}
			else if (!strcmp(argv[2], "--noleaks"))
				;
			else
				printf("\nCOMMAND NOT FOUNT \"%s\"\n", argv[2]);
		}
		if (argc == 4)
		{
			if (!strcmp(argv[3], "--nolines"))
				;
			else if (strcmp(argv[3], "--lines"))
				printf("\nCOMMAND NOT FOUNT \"%s\"\n", argv[3]);
		}
	}
	else
	{
		if (argc > 2)
			printf("Error: too many arguments\n");
		else
			printf("Error: an fd is required\n");
		return (1);
	}
	return (0);
}
