/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:55:16 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/10 19:43:37 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *heystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (!*needle)
		return ((char *)heystack);
	while (i < len && heystack[i])
	{
		j = 0;
		while (heystack[i] == needle[j]&& i < len)
		{
			if (j == ft_strlen(needle) - 1)
				return ((char *)&(heystack[i - j]));
			if (!heystack[i])
				return (NULL);
			i++;
			j++;
		}
		i =  i - j + 1;
	}
	return (NULL);
}
// #include <stdio.h>
// int main(void)
// {
// 	char s1[30] = "aaabcabcd";
// 	char s2[10] = "cd";
// 	size_t max = 8;
// 	char *i1 = strnstr(s1, s2, max);
// 	char *i2 = ft_strnstr(s1, s2, max);

// 	printf("strnstr |%s|\n",i1);
// 	printf("ft_strnstr |%s|\n",i2);
// }