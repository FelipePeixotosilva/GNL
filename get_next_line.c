/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:14:56 by fpeixoto          #+#    #+#             */
/*   Updated: 2022/07/11 19:40:48 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
  char *buffer;
  static char *str;
  int i ;
  
  buffer = malloc(BUFFER_SIZE + 1);
  i = 0;
  
  read(fd, buffer, BUFFER_SIZE);
  str = ft_strchr(buffer, '\n');
  str[BUFFER_SIZE+1] = '\0';
  
  return str;
}

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char *buffer;

    fd =  open("test.txt",O_RDONLY);
    
    //read(fd, buffer, 5);
    
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    
}
