/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:04:04 by agarcia2          #+#    #+#             */
/*   Updated: 2025/11/20 16:20:00 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	const char	*p;

	if (!s)
		return (0);
	p = s;
	while (*p)
		p++;
	return ((size_t)(p - s));
}

char	*ft_strchr_gnl(const char *s, int c)
{
	unsigned char	ch;

	if (!s)
		return (NULL);
	ch = (unsigned char)c;
	while (*s)
	{
		if ((unsigned char)*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}

static char	*gnl_realloc_bytes(char *bytes, size_t *cap,
		size_t need, size_t len1)
{
	char	*new_bytes;
	char	*dst;
	char	*src;

	if (*cap >= need)
		return (bytes);
	if (*cap == 0)
		*cap = need;
	while (*cap < need)
		*cap *= 2;
	new_bytes = (char *)malloc(*cap);
	if (!new_bytes)
	{
		free(bytes);
		return (NULL);
	}
	dst = new_bytes;
	src = bytes;
	while (len1--)
		*dst++ = *src++;
	free(bytes);
	return (new_bytes);
}

char	*ft_bytes_join(char *bytes, const char *buf, size_t *cap)
{
	size_t		len1;
	size_t		need;
	char		*dst;
	const char	*src;

	len1 = ft_strlen_gnl(bytes);
	need = len1 + ft_strlen_gnl(buf) + 1;
	bytes = gnl_realloc_bytes(bytes, cap, need, len1);
	if (!bytes)
		return (NULL);
	dst = bytes + len1;
	src = buf;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (bytes);
}
