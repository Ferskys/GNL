/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:33:16 by fsuomins          #+#    #+#             */
/*   Updated: 2022/10/14 00:06:31 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *save)
{
	int		i;
	char	*j;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	j = (char *)malloc(sizeof(char) * (i + 2));
	if (!j)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		j[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		j[i] = save[i];
		i++;
	}
	j[i] = '\0';
	return (j);
}

char	*save_line(char *save)
{
	int		i;
	int		c;
	char	*j;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	j = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!j)
		return (NULL);
	i++;
	c = 0;
	while (save[i])
		j[c++] = save[i++];
	j[c] = '\0';
	free(save);
	return (j);
}

char	*read_save(int fd, char *save)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = read_save(fd, save);
	if (!save)
		return (NULL);
	line = get_line(save);
	save = save_line(save);
	return (line);
}
