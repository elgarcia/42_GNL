/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:58:20 by eliagarc          #+#    #+#             */
/*   Updated: 2023/12/14 04:09:11 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*free_null(char **s)
{
	free(*s);
	*s = NULL;
	return (NULL);
}

char	*ft_strjoin(char **s1, char *s2, int size)
{
	char	*aux;
	int		size_s1;

	if (!(*s1))
	{
		*s1 = (char *)ft_calloc(1, 1);
		if (!(*s1))
			return (NULL);
	}
	size_s1 = ft_strlen(*s1);
	aux = (char *)ft_calloc(size_s1 + size + 1, 1);
	if (!aux)
		return (free_null(s1));
	if (!s2)
		return (free(aux), free_null(s1));
	else
	{
		ft_memcpy(aux, *s1, size_s1 + 1);
		ft_strlcat(aux, s2, size_s1 + size + 1);
	}
	free_null(s1);
	return (aux);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	total_len;
	size_t	dst_len;

	i = 0;
	dst_len = ft_strlen(dst);
	total_len = ft_strlen(src);
	if (dstsize != 0 && (dstsize > dst_len))
	{
		while (i < (dstsize - dst_len - 1) && src[i])
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = 0;
		return (total_len + dst_len);
	}
	while (i < dstsize)
		i++;
	total_len += i;
	return (total_len);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
