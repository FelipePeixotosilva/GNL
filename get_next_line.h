/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 08:39:26 by fpeixoto          #+#    #+#             */
/*   Updated: 2022/07/11 19:34:16 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 15

size_t	ft_strlen(const char *s);
char *get_next_line(int fd);
char	*ft_strchr(const char *s, int c);

#endif
