/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:33:51 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/03 13:52:02 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	while (*dst)
		dst++;
	if (dstsize <= src_len + dst_len)
	{
		while (i++ < dstsize - dst_len - 1)
			*dst++ = *src++;
	}
	else
	{
		while (*src)
			*dst++ = *src++;
	}
	*dst = '\0';
	if (dstsize > dst_len)
		return (dst_len + src_len);
	else
		return (src_len + dstsize);
}
