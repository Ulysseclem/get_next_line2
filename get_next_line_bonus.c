/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulysse <ulysse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:38:59 by uclement          #+#    #+#             */
/*   Updated: 2023/04/08 19:13:27 by ulysse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"


char	*to_line(char *stock, char *line)
{
	int		i;
	int		j;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL) ;
	j = 0;
	while (j < i)
	{
		line[j] = stock[j];
		j++;
	}
	line[j] = '\0';
	// free(stock);
	return(line);
}

char	*free_stock(char *stock)
{
	char	*temp;
	int		len;
	int		i;
	int		j;

	i = 0;
	len = ft_strlen(stock);
	while (stock[i] != '\n' && stock[i])
		i++;
	j = 0;
	temp = malloc(sizeof(char) * (len - i) + 1);
	if (!temp)
		return (NULL);
	while (i < len)
		temp[j++] = stock[++i];
	temp[j] = '\0';
	free(stock);
	return(temp);
}

char	*read_stock(char *stock, int fd)
{
	char		*buf;
	int			size;
	int			c;

	c = 0;
	buf = NULL;
	size = 1;
	while (c != 1 && size != 0)
	{	
		buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		size = read(fd, buf, BUFFER_SIZE);
		buf[size] = '\0';
		stock = ft_strjoin(stock, buf);
		c = check_newline(buf);
		free (buf);
	}
	return (stock) ;
}

char	*get_next_line(int fd)
{
	static char	*stock[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	stock[fd] = read_stock(stock[fd], fd);
	line = to_line(stock[fd], line);
	stock[fd] = free_stock(stock[fd]);
	if (line[0] == '\0')
	{
		free (stock[fd]);
		stock[fd] = NULL;
		free (line);
		return (NULL);
	}
	return (line);
}

// #include <stdio.h>

// int main()
// {
// 	int fd1;
// 	int fd2;
// 	char *line;
// 	int i;

// 	fd1 = open("foo1.txt", O_RDONLY);
// 	fd2 = open("foo2.txt", O_RDONLY);

// 	i = 0;
// 	while(1)
// 	{
// 		line = get_next_line(fd1);
// 		printf("%s",line);
// 			if (line == NULL)
// 			{	
// 				free(line);
// 				break;
// 			}
// 		free(line);
// 		i++;
// 	}

// 		line = get_next_line(fd2);
// 		printf("%s",line);
// 		free(line);

// 		close(fd1);
// 		close(fd2);

// 	return(0);
// }