/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:09:47 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/07 20:09:45 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*arry;
	size_t			i;

	i = 0;
	arry = (unsigned char *)malloc(size * count);
	if (!arry)
		return (NULL);
	while (i < size * count)
	{
		arry[i] = 0;
		i++;
	}
	return (arry);
}
