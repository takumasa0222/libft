/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 05:21:42 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/04/22 20:33:44 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

int	main(void)
{
	char dst1[50];
	char dst2[200];
	char dst3[200];
	char dst4[200];
	char src1[] = {"testabcdef"};
	char src2[] = {"testabcdef!!The world is funtastic!!"};
	char src3[] = {"testabcdef"};
	char src4[] = {"testabcdef"};
	char *src5;
	src5 = NULL;


	printf("result of return%ld\n", strlcpy(dst1, src1, 10));
	printf("result %s\n", dst1);

	printf("result of return%ld\n", strlcpy(dst2, src2, 15));
	printf("result %s\n", dst1);

	printf("result of return%ld\n", strlcpy(dst3, src3, 3));
	printf("result %s\n", dst2);

	printf("result of return%ld\n", strlcpy(dst4, src4, 15));
	printf("result %s\n", dst1);

}
