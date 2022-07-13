/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:14:56 by fpeixoto          #+#    #+#             */
/*   Updated: 2022/07/13 18:37:24 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char *ft_fn(int fd, char *str)
{
  char *buff;
  int i = 0;
  str = (char *)malloc(BUFFER_SIZE + 1);
  buff =(char *)malloc (BUFFER_SIZE + 1); 
  read(fd,str, BUFFER_SIZE);
  while(str[i] && str[i] != '\n')
{
  if(str[i] == '\\')
  {
    i++;
    if(str[i] == 'n')
      exit;
  }
  buff[i] = str[i];
  i++;
}
return buff; 
}
char *get_next_line(int fd)
{
  static char *v;
  
v = ft_fn(fd, v);
  return v;
}



int main()
{
    int fd;
    char *buffer;

    fd =  open("test.txt",O_RDONLY);
    
    //read(fd, buffer, 5);
    printf("%s\n",get_next_line(fd));
    printf("%s\n",get_next_line(fd));
   
}
