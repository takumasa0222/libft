/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:55:16 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/07 20:05:52 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *heystack, const char *needle, size_t len)
{
	int		i;
	int		j;

	i = 0;
	if (!*needle)
		return ((char *)heystack);
	while (i < (int)len && heystack[i])
	{
		j = 0;
		while (heystack[i] == needle[j])
		{
			if (j == (int)ft_strlen(needle) - 1)
				return ((char *)&(heystack[i - j]));
			if (!heystack[i])
				return (NULL);
			i++;
			j++;
		}
		i++;
	}
	return (NULL);
}
// #include <stdio.h>
// int main(void)
// {
// 	char *s1 = "see FF your FF return FF now FF";
// 	char *s2 = "FF";
// 	size_t max = strlen(s1);
// 	char *i1 = strnstr(s1, s2, max);
// 	char *i2 = ft_strnstr(s1, s2, max);

// 	printf("strlen |%s|\n",i1);
// 	printf("ft_strlen |%s|\n",i2);
// }