/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:14:56 by fpeixoto          #+#    #+#             */
/*   Updated: 2022/07/15 11:24:20 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	sch_limit(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		return (0);
	}
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*get_new_line(char *str)
{
	size_t	i;
	size_t	j;
	char	*temp;

	if (!str)
		return (NULL);
	j = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	temp = malloc ((ft_strlen(str) - i) + 1);
	if (!temp)
		return (NULL);
	while (str[i])
	{
		temp[j] = str[i];
		i++;
		j++;
	}
	return (temp);
}

char	*get_line(char *str)
{
	char	*temp;
	size_t	i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	temp = malloc (i + 2);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		temp[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		temp[i] = '\n';
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*str;
	int			rd;

	rd = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, 0, 0) < 0)
		return (NULL);
	buff = malloc (BUFFER_SIZE + 1);
	while (rd != 0 && !sch_limit(str, '\n'))
	{
		rd = read (fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd] = '\0';
		str = ft_strjoin (str, buff);
	}
	free(buff);
	line = get_line (str);
	str = get_new_line (str);
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>
int main()
{
    int fd;
    char *str;
  
    fd =  open("test.txt",O_RDONLY);
    
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
}
*/
