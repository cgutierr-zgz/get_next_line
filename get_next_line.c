/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:33:19 by cgutierr          #+#    #+#             */
/*   Updated: 2021/02/09 17:15:52 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_end(int fd, char **text)
{
	char *aux;

	if (!ft_strchr(text[fd], '\n'))
	{
		free(text[fd]);
		text[fd] = NULL;
		return (0);
	}
	aux = ft_strdup(ft_strchr(text[fd], '\n') + 1);
	free(text[fd]);
	text[fd] = aux;
	return (1);
}

static char	*ft_getstringuntiljumporend(char **text, int fd)
{
	char	*aux;
	int		i;
	int		x;

	i = 0;
	x = -1;
	while (text[fd][i] != '\n' && text[fd][i])
		i++;
	if (!(aux = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (++x < i)
		aux[x] = text[fd][x];
	aux[x] = '\0';
	return (aux);
}

static void	ft_text(char *buff, int fd, char **text)
{
	char *aux;

	if (!text[fd])
		text[fd] = ft_strdup(buff);
	else
	{
		aux = ft_strjoin(text[fd], buff);
		free(text[fd]);
		text[fd] = aux;
	}
}

int			get_next_line(int fd, char **line)
{
	static char	*text[MAX_FD];
	char		buff[BUFFER_SIZE + 1];
	int			n;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((n = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[n] = '\0';
		ft_text(buff, fd, text);
		if (ft_strchr(text[fd], '\n'))
			break ;
	}
	if (n < 0 || (n == 0 && !text[fd]))
	{
		if (n < 0)
			return (-1);
		*line = ft_strdup("");
		return (0);
	}
	if (!(*line = ft_getstringuntiljumporend(text, fd)))
		return (-1);
	return (ft_end(fd, text));
}
