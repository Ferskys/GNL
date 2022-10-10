/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 20:08:17 by fsuomins          #+#    #+#             */
/*   Updated: 2022/10/10 23:51:28 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *catch_line(char    *str)
{
    int        i;
    char    *ssave;
    
    i = 0;
    if (!str[i])
        return (NULL);
    while (str[i] && str[i] != '\n')
        i++;
    ssave = (char *)malloc(sizeof(char) * (i + 1));
    if (!ssave)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
    {
        ssave[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
    {
        ssave[i] = str[i];
        i++;
    }
    ssave[i] = '\0';
    free (str);
    return (ssave);
}

char    *save_more_letters(char *str)
{
    int        i;
    int        j;
    char    *ssave;
    
    i = 0;
    j = 0;
    if (!str[i])
    {
        free(str);
        return (NULL);
    }
    while (str[i] && str[i] != '\n')
        i++;
    ssave = (char *)malloc(sizeof(char) * (ft_strlen(ssave) - i + 1));
    if (!ssave)
        return (NULL);
    i++
    while (str[i])
        ssave[j++] = str[i++];
    ssave[j] = '\0';
    free(str);
    return (ssave);    
}

char	*ft_read_and_save(int fd, char *save)
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

char    *get_next_line(int fd)
{
    char        *line;
    static char    *save;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    save = ft_read_and_save(fd, save);
    if (!save)
        return (NULL);
    line = ft_get_line(save);
    save = ft_save(save);
    return (line);
}
