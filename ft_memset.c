/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 05:03:16 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/04/22 05:59:18 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*orign_ptr;

	i = 0;
	orign_ptr = (unsigned char *)ptr;
	if (!ptr)
		return (ptr);
	while (i < num)
	{
		*orign_ptr = (unsigned char)value;
		i++;
		orign_ptr++;
	}
	return (ptr);
}
