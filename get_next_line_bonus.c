/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:14:56 by fpeixoto          #+#    #+#             */
/*   Updated: 2022/07/19 20:32:31 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

char	*ft_get_new_line(char *str)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	temp = malloc((ft_strlen(str) - i) + 1);
	while (str[i])
		temp[j++] = str[i++];
	temp[j] = '\0';
	free(str);
	return (temp);
}

char	*ft_get_line(char *str)
{
	char	*temp;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	temp = malloc (i + 2);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		temp[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		temp[i++] = '\n';
	temp[i] = '\0';
	return (temp);
}

char	*ft_read_line(int fd, char *str, char *buff)
{
	int	rd;

	rd = 1;
	while (rd != 0)
	{
		rd = read (fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd] = '\0';
		if (!str)
		{
			str = malloc(1);
			str[0] = '\0';
		}
		str = ft_strjoin (str, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, 0, 0) < 0)
		return (NULL);
	buff = malloc (BUFFER_SIZE + 1);
	str[fd] = ft_read_line(fd, str[fd], buff);
	free(buff);
	line = ft_get_line (str[fd]);
	str[fd] = ft_get_new_line (str[fd]);
	return (line);
}
/*
int main()
{
	int fd;
	int rd;
	fd = open("test.txt",O_RDONLY);

	rd = read(fd, 0, 0);
	printf("%d\n", rd);

}*/
