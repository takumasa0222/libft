/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 05:21:42 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/04/21 05:55:42 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t strlcpy(char *dst, const char *src, size_t size);
// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	if()
// }

int	main(void)
{
	char dst1[20];
	char dst2[20];
	char dst3[20];
	char dst4[20];
	char src1[] = {"Helloworld"};
	char src2[] = {"Helloworld!!The world is funtastic!!"};
	char src3[] = {"Helloworld"};
	char src4[] = {"Helloworld"};

	printf("result of return%ld\n", strlcpy(dst1, src1, 10));
	printf("result of return %s\n", dst1);

	printf("result of return%ld\n", strlcpy(dst2, src2, 10));
	printf("result of return %s\n", dst1);

	printf("result of return%ld\n", strlcpy(dst3, src3, 3));
	printf("result of return %s\n", dst2);

	printf("result of return%ld\n", strlcpy(dst4, src4, 0));
	printf("result of return %s\n", dst1);


}