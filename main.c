/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 14:31:16 by cgutierr          #+#    #+#             */
/*   Updated: 2020/08/11 13:16:47 by cgutierr         ###   ########.fr       */
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
*/

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

size_t	stringlength(const char *str)
{
	size_t len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*joinstrings(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(*str) *
		(stringlength(s1) + stringlength(s2) + 1))))
		return (NULL);
	i = 0;
	while (*s1)
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = '\0';
	return (str);
}

int		main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*line;

	if (argc == 2)
	{
		i = 0;
		fd = open(joinstrings("./", argv[1]), O_RDONLY);
		if (fd == -1)
		{
			printf("Error: couldn't open fd \"./%s\"\n", argv[1]);
			return (1);
		}
		else
		{
			while ((get_next_line(fd, &line)) == 1)
			{
				printf("%s\n", line);
			}
			close(fd);
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
