/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:42:49 by cgutierr          #+#    #+#             */
/*   Updated: 2021/02/08 16:44:16 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_text(char *buffer, char *text)
{
	char	*aux;

	if (!text)
		text = ft_strdup(buffer);
	else
	{
		aux = ft_strjoin(text, buffer);
		free(text);
		text = ft_strdup(aux);
		free(aux);
	}
	return (text);
}

char	*ft_getstringuntiljump(char *text, char character)
{
	char	*aux;
	int		i;
	int		x;

	i = 0;
	x = -1;
	while (text[i] != character)
		i++;
	if (!(aux = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (++x < i)
		aux[x] = text[x];
	aux[x] = '\0';
	return (aux);
}

int		ft_lastline(int n_bytes, char *text, char **line)
{
	if (n_bytes == 0 && text && !ft_strchr(text, '\n'))
	{
		*line = ft_strdup(text);
		text[0] = '\0';
		return (0);
	}
	if (n_bytes == 0 && !text)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*text[256];
	char		buff[BUFFER_SIZE + 1];
	int			n_bytes;
	char		*temp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (-1);
	while ((n_bytes = read(fd, buff, BUFFER_SIZE)))
	{
		if (n_bytes == -1)
			return (-1);
		buff[n_bytes] = '\0';
		text[fd] = ft_text(buff, text[fd]);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (!ft_lastline(n_bytes, text[fd], line))
		return (0);
	*line = ft_getstringuntiljump(text[fd], '\n');
	temp = ft_strdup(ft_strchr(text[fd], '\n'));
	free(text[fd]);
	text[fd] = NULL;
	text[fd] = ft_strdup(temp + 1);
	free(temp);
	return (1);
}
