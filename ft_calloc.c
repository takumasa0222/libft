/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:09:47 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/07/27 04:43:42 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*arry;
	size_t			i;

	i = 0;
	if ((count && size > SIZE_MAX / count) || (size && count > SIZE_MAX / size))
		return (NULL);
	arry = (void *)malloc(size * count);
	if (!arry)
		return (NULL);
	while (i < size * count)
	{
		arry[i] = 0;
		i++;
	}
	return (arry);
}
