/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:58:34 by eliagarc          #+#    #+#             */
/*   Updated: 2023/10/22 20:11:24 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define B_READED_FAIL -1
# define B_READED_NULL 0

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char **s1, char *s2, int size);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *c);
void	*free_null(char **s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif
