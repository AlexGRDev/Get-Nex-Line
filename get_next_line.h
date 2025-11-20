/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:04:16 by agarcia2          #+#    #+#             */
/*   Updated: 2025/11/20 10:04:16 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

size_t	ft_strlen_gnl(const char *s);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_bytes_join(char *bytes, const char *buf, size_t *cap);

#endif
