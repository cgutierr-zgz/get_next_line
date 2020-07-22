/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:29:54 by cgutierr          #+#    #+#             */
/*   Updated: 2020/07/22 12:27:36 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Devuelve una línea leída desde un file descriptor, sin salto de linea
**
** ·Se debe comilar con el flag:
**		-D BUFFER_SIZE=xx
**
** ·Compilación:
**		-gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c
**
** ·Se debe utilizar el BUFFER_SIZE para leer desde un archivo o desde la stdin
**
** ·En get_next_line.h debe al menos tener el prototipo de la función
**
** !) Si el valor de BUFFER_SIZE es 9999 sigue funcionando?
**		o si vale 1?
**		o 10000000?
**		¿Sabe por qué?
** !) Funciones autorizadas:
**		read
**		malloc
**		free
**
** VALORES DE RETORNO:
** 1	->	Se ha leido la línea
** 0	->	Se ha terminado la lectura
** -1	->	Ha ocurrido un error
**
** !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
** fd	->	El file descriptor desde el que vamos a leer
** line	->	El valor de lo que se ha leído
**
** !) SOLO PODEMOS LEER EL FILE DESCRIPTOR UNA VEZ
**
** EXTRA!
** Completar get_next_line con 1 variable estática
** No entiendo exactamente lo que se pide jaj :)
*/

// fd 	-> 0 = standard input(typing 4 ex)
//		-> 1 = standard output(shell)
//		-> 2 = error output(shell)

int get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	int ret;
	static int i = 0;
	if (fd < 0 || !*line || !line)
		return (-1);

	while (ret = read(fd, buf, BUFFER_SIZE))
	{
		buf[ret] = '\0';
		line[i] = buf;

		i++;
		printf("%s", buf);
		
	}
	return (0);
}
