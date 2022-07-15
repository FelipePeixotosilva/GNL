/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:47:41 by fpeixoto          #+#    #+#             */
/*   Updated: 2022/07/15 10:36:12 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	s;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	s = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	ptr = malloc(sizeof(char) * s);
	if (ptr == 0)
	{
		return (NULL);
	}
	ft_strlcpy (ptr, s1, s);
	ft_strlcat (ptr, s2, s);
	free(s1);
	return (ptr);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	j;
	size_t	limit;

	dst_len = ft_strlen(dst);
	if (size <= dst_len)
	{
		return (size + ft_strlen(src));
	}
	limit = size - dst_len - 1;
	j = 0;
	while (src[j] && j < limit)
	{
		dst[dst_len + j] = src[j];
		j++;
	}
	dst[dst_len + j] = '\0';
	return (dst_len + ft_strlen(src));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	if (ft_strlen(src) + 1 < size)
	{
		ft_memmove(dst, src, ft_strlen(src) + 1);
		dst[size - 1] = '\0';
	}
	else if (size != 0)
	{
		ft_memmove(dst, src, size - 1);
		dst[size - 1] = '\0';
	}	
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest > src)
	{
		while (n > 0)
		{
			n--;
			((char *)dest)[n] = ((char *)src)[n];
		}
	}
	else
	{
		while (n > 0)
		{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
		n--;
		}
	}
	return (dest);
}
