/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 22:51:02 by cgutierr          #+#    #+#             */
/*   Updated: 2020/08/11 13:22:13 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** get_next_line nos permitirá leer la totalidad de un texto en un file
** descriptor, linea a linea, hasta finalizar el archivo
**
** Cada función contiene una explicación del proceso y de no ser obvio,
** esta explicación se ve acompañada de un pequeño ejemplo
**
** Librerias externas:
**
** <stdlib.h>
**	·malloc	| Asignación de memoria dinámica
**	·free	| Liberación de memoria dinámica
**
** <unistd.h>
**	·read	| Lectura a un file descriptor
*/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

int	get_next_line(int fd, char **line);

#endif
