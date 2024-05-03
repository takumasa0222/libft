/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:55:16 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/03 14:00:56 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *heystack, const char *needle, size_t len)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	if (!*needle)
		return ((char *)heystack);
	while (i < len && heystack[i])
	{
		j = 0;
		while (heystack[i] == needle[j])
		{
			if (j == (unsigned int) ft_strlen(needle) - 1)
				return ((char *)heystack + i);
			if (!heystack[i])
				return (NULL);
			i++;
			j++;
		}
	}
	return (NULL);
}
