/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 09:39:57 by cgutierr          #+#    #+#             */
/*   Updated: 2020/08/11 11:20:40 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 20

int fun()
{
	static int count = 0;
	count += 1;
	return count;
}

int main()
{
	/** Static Check 
	int x;
	x = 0;
	while (x != 10)
	{
		printf("[%d]", fun());
		x++;
	}
	**/
	/** Read check **/
	int fd;
	char buf[BUFFER_SIZE + 1];
	ssize_t nr_bytesread;
	fd = open("/Users/cgutierr/Documents/Cursus/get_next_line/get_next_line/fd", O_RDONLY);
	if (fd == -1)
	{
		printf("Error al abrir fd\n");
		return (1);
	}

	while ((nr_bytesread = read(fd, buf, BUFFER_SIZE)))
	{
		buf[nr_bytesread] = '\0';
		printf("%s\n\n", buf); //[%zd]\n, nr_bytesread,
	}
	close(fd);

	if (nr_bytesread == 0)
		printf("\nArchivo vacio? o yata:)\n\n");

	return 0;
}
