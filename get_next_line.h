/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:46:19 by uclement          #+#    #+#             */
/*   Updated: 2023/04/07 12:27:49 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		check_newline(char *buf);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
void	to_line(char *stock, char **line);
void	read_stock(char **stock, int fd);
void	free_stock(char **stock);
char	*ft_strdup(const char *s);

#endif