/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 05:21:42 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/06 23:43:57 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	long	i;

	i = 0;
	while (i < (long)size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

#include <stdio.h>
int	main(void)
{
	// 1 src < dst < dstsize
	// 2 src < dstsize < dst
	// 3 dst < src < dstsize
	// 4 dst < dstsize < src
	// 5 dstsize < dst < src
	// 6 dstsize < src < dst
	// 7 dstsize = 0
	// 8 srcsize = 0
	// 9 dstsize = 0
	// 10 src = NULL
	// 11 dst = NULL
	// 12 dstsize -> 0, src NULL
	// 13 dstsize -> 0, dst NULL

	char dst1[50] = {"Hello\0"};
	char dst2[200] = {"abcde2\0"};
	char dst3[200] = {"hello\0"};
	char dst4[50] = {"Hello\0"};
	char dst5[200] = {"abcde2\0"};
	char dst6[200] = {"hello !!The world is funtastic!! world\0"};
	char dst7[0];
	char dst8[200] = {"abcde2\0"};
	char dst9[200] = {"hello\0"};
	char dst10[200] = {"hello !!The world is funtastic!! world\0"};
	char *dst11 = NULL;
	char dst12[200] = {"abcde2\0"};
	char *dst13 = NULL;
	char src1[] = {"test\0"};
	char src2[] = {"test\0"};
	char src3[] = {"Hello world\0"};
	char src4[] = {"testabcdef"};
	char src5[] = {"testabcdef!!The world is funtastic!!"};
	char src6[] = {"testabcdef!!The world is funtastic!!"};
	char src7[] = {"hello\0"};
	char src8[0];
	char src9[] = {"hello\0"};
	char *src10 = NULL;
	char src11[]= {"test\0"};
	char *src12 = NULL;
	char src13[100] = {"test\0"};

	char ft_dst1[50] = {"Hello\0"};
	char ft_dst2[200] = {"abcde2\0"};
	char ft_dst3[200] = {"hello\0"};
	char ft_dst4[50] = {"Hello\0"};
	char ft_dst5[200] = {"abcde2\0"};
	char ft_dst6[200] = {"hello !!The world is funtastic!! world\0"};
	char ft_dst7[0];
	char ft_dst8[200] = {"abcde2\0"};
	char ft_dst9[200] = {"hello\0"};
	char ft_dst10[200] = {"hello !!The world is funtastic!! world\0"};
	char *ft_dst11 = NULL;
	char ft_dst12[200] = {"abcde2\0"};
	char *ft_dst13 = NULL;
	char ft_src1[] = {"test\0"};
	char ft_src2[] = {"test\0"};
	char ft_src3[] = {"Hello world\0"};
	char ft_src4[] = {"testabcdef"};
	char ft_src5[] = {"testabcdef!!The world is funtastic!!"};
	char ft_src6[] = {"testabcdef!!The world is funtastic!!"};
	char ft_src7[] = {"hello\0"};
	char ft_src8[0];
	char ft_src9[] = {"hello\0"};
	char *ft_src10 = NULL;
	char ft_src11[]= {"test\0"};
	char *ft_src12 = NULL;
	char ft_src13[100] = {"test\0"};

	// printf("result of return%ld\n", strlcpy(dst1, src1, 10));
	// printf("result %s\n", dst1);
	// printf("result of return%ld\n", strlcpy(dst2, src2, 5));
	// printf("result %s\n", dst2);
	// printf("result of return%ld\n", strlcpy(dst3, src3, 15));
	// printf("result %s\n", dst3);
	// printf("result of return%ld\n", strlcpy(dst4, src4, 8));
	// printf("result %s\n", dst4);
	// printf("result of return%ld\n", strlcpy(dst5, src5, 1));
	// printf("result %s\n", dst5);
	// printf("result of return%ld\n", strlcpy(dst6, src6, 5));
	// printf("result %s\n", dst6);
	// printf("result of return%ld\n", strlcpy(dst7, src7, 15));
	// printf("result %s\n", dst7);
	// printf("result of return%ld\n", strlcpy(dst8, src8, 8));
	// printf("result %s\n", dst8);
	printf("result of return%ld\n", strlcpy(dst9, src9, 0));
	printf("result %s\n", dst9);
	// printf("result of return%ld\n", strlcpy(dst10, src10, 5));
	// printf("result %s\n", dst10);
	// printf("result of return%ld\n", strlcpy(dst11, src11, 15));
	// printf("result %s\n", dst11);
	// printf("result of return%ld\n", strlcpy(dst12, src12, 0));
	// printf("result %s\n", dst12);
	printf("result of return%ld\n", strlcpy(dst13, src13, 0));
	printf("result %s\n", dst13);
	printf("\n");

	// printf("result of return%ld\n", ft_strlcpy(ft_dst1, ft_src1, 10));
	// printf("result %s\n", ft_dst1);
	// printf("result of return%ld\n", ft_strlcpy(ft_dst2, ft_src2, 5));
	// printf("result %s\n", ft_dst2);
	// printf("result of return%ld\n", ft_strlcpy(ft_dst3, ft_src3, 15));
	// printf("result %s\n", ft_dst3);
	// printf("result of return%ld\n", ft_strlcpy(ft_dst4, ft_src4, 8));
	// printf("result %s\n", ft_dst4);
	// printf("result of return%ld\n", ft_strlcpy(ft_dst5, ft_src5, 1));
	// printf("result %s\n", ft_dst5);
	// printf("result of return%ld\n", ft_strlcpy(ft_dst6, ft_src6, 5));
	// printf("result %s\n", ft_dst6);
	// printf("result of return%ld\n", ft_strlcpy(ft_dst7, ft_src7, 15));
	// printf("result %s\n", ft_dst7);
	// printf("result of return%ld\n", ft_strlcpy(ft_dst8, ft_src8, 8));
	// printf("result %s\n", ft_dst8);
	printf("result of return%ld\n", ft_strlcpy(ft_dst9, ft_src9, 0));
	printf("result %s\n", ft_dst9);
	// printf("result of return%ld\n", ft_strlcpy(ft_dst10, ft_src10, 5));
	// printf("result %s\n", ft_dst10);
	// printf("result of return%ld\n", ft_strlcpy(ft_dst11, ft_src11, 15));
	// printf("result %s\n", ft_dst11);
	// printf("result of return%ld\n", ft_strlcpy(ft_dst12, ft_src12, 0));
	// printf("result %s\n", ft_dst12);
	printf("ftresult of return%ld\n", ft_strlcpy(ft_dst13, ft_src13, 0));
	printf("ftresult %s\n", ft_dst13);
}
