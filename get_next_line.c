/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:29:54 by cgutierr          #+#    #+#             */
/*   Updated: 2020/08/11 13:20:30 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
**
** fd 	-> 0 = standard input(typing 4 ex)
**		-> 1 = standard output(shell)
**		-> 2 = error output(shell)
*/

int ft_checkifhasnewline(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

size_t ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char *ft_strdup(const char *s1)
{
	int len;
	char *str;
	int i;

	len = ft_strlen(s1) + 1;
	if (!(str = ((char *)malloc(sizeof(char) * len))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
char *ft_strjoin(char *s1, char *s2)
{
	char *str;
	size_t i;

	//	if (!s1 || !s2)
	//		return (NULL);
	if (!(str = (char *)malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
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

int get_next_line(int fd, char **line)
{
/*
** 1	->	Se ha leido la línea
** 0	->	Se ha terminado la lectura [EOF]
** -1	->	Ha ocurrido un error
*/
	static char *str;
	char *aux;
	int bytes_readed;
	char buf[BUFFER_SIZE + 1];

	//Si hay un error con el fd -> Error (-1)
	if (fd == -1)
		return (-1);
	//Esto lee hasta EOF y guarda en bytes_readed el numero de bytes y en buf lo leido
	while ((bytes_readed = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		//Añadimos el '\0' para el final de string
		buf[bytes_readed] = '\0';
		//	str = ft_strjoin(str, buf);
		printf("\n************************->\n%s", buf);
		if (!(ft_checkifhasnewline(buf)))
		{ //Si no tiene salto de linea, lo almacenamos en str
			if (str == NULL)
				str = "";
			str = ft_strjoin(str, buf);
		}
		else
		{ //Si tiene salto de linea lo devolvemos antes de este
		
		}
	}

	return (0);
}
