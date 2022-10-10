/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 20:09:08 by fsuomins          #+#    #+#             */
/*   Updated: 2022/10/10 21:08:14 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*catch_line(char    *str);
char	*save_more_letters(char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_read_and_save(int fd, char *save);
char	*ft_strjoin(char const *s1, char const *s2);

#endif