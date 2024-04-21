/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 05:45:27 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/04/22 05:54:33 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_cpy;

	if (!s)
		return (NULL);
	s_cpy = s;
	while (n--)
	{
		if (*s_cpy == (unsigned char)c)
			return (s_cpy);
		s_cpy++;
	}
	return (NULL);
}
