/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:14:56 by fpeixoto          #+#    #+#             */
/*   Updated: 2022/07/13 23:12:34 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char *ft_line_c(char *str, int fd, int pos)
{
  char *buff;
  char *temp;
  int i;
  int count;
  count = 0;
  i = pos;
  buff = (char *)malloc(sizeof(char));
  temp = (char *)malloc(sizeof(char));
  read(fd, buff, BUFFER_SIZE);
  while(buff[i] && buff[i] != '\n')
  {
    temp[count] = buff[i];
    i++;
    count++;
  }
  temp[count++]='\0';
  str = temp;
  free(temp);
  return str;
}

int ft_get_pos(int pos, char *str)
{
  
  pos += ft_strlen(str)+1;
  return pos;
}
char *get_next_line(int fd)
{
  char *buff;
  char *temp;
  static char *str;
  static int pos = 0;  
  
  str = ft_line_c(str, fd, pos);
  pos = ft_get_pos(pos, str);
  printf("%d\n",pos);
  return str; 
}

int main()
{
    int fd;
    char *str;
  
    fd =  open("test.txt",O_RDONLY);

  printf("%s\n", get_next_line(fd));
  printf("%s\n", get_next_line(fd));
  printf("%s\n", get_next_line(fd));  
   
}
