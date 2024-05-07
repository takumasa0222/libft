/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 05:19:36 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/07 19:39:58 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	if (!s1 || !s2)
		return (0);
	i = 0;
	while ((i < n && s1[i]) || (i < n && s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	char s1[50] = {"Hello\0"};
	char s2[200] = {"\0"};
	char *s3 = NULL;
	char s4[50] = {"\200World\0"};
	char s5[200] = {"abcdef\0"};
	char s6[200] = {"\200\0"};
	char s7[200] = {"abcdef\0"};
	char *s8 = "abcdef";
	char t1[] = {"Hello\0"};
	char t2[] = {"\0"};
	char *t3 = NULL;
	char t4[] = {"Hello\0"};
	char t5[] = {"abgggg"};
	char t6[] = {"\0"};
	char *t7 = NULL;
	char *t8 = "abcdefghijklmnop";


	printf("result of return%d\n", strncmp(s1, s1, 0));
	printf("test num %d\n", 1);
	printf("result of return%d\n", strncmp(s1, t1, 3));
	printf("test num %d\n", 2);
	printf("result of return%d\n", strncmp(s1, t1, 10));
	printf("test num %d\n", 3);
	printf("result of return%d\n", strncmp(s2, t2, 0));
	printf("test num %d\n", 4);
	printf("result of return%d\n", strncmp(s2, t2, 3));
	printf("test num %d\n", 5);
	printf("result of return%d\n", strncmp(s2, t2, 10));
	printf("test num %d\n", 6);
	printf("result of return%d\n", strncmp(s3, t3, 0));
	printf("test num %d\n", 7);
	printf("result of return%d\n", strncmp(s4, t4, 3));
	printf("test num %d\n", 10);
	printf("result of return%d\n", strncmp(s4, t4, 10));
	printf("test num %d\n", 11);
	printf("result of return%d\n", strncmp(s5, t5, 0));
	printf("test num %d\n", 12);
	printf("result of return%d\n", strncmp(s5, t5, 3));
	printf("test num %d\n", 13);
	printf("result of return%d\n", strncmp(s5, t5, 10));
	printf("test num %d\n", 14);
	printf("result of return%d\n", strncmp(s6, t6, 0));
	printf("test num %d\n", 15);
	printf("result of return%d\n", strncmp(s6, t6, 3));
	printf("test num %d\n", 16);
	printf("result of return%d\n", strncmp(s6, t6, 10));
	printf("test num %d\n", 17);
	printf("result of return%d\n", strncmp(s7, t7, 0));
	printf("test num %d\n", 18);
	printf("result of return%d\n", strncmp(s8, t8, 6));
	printf("test num %d\n", 19);
	printf("\n");

	printf("result of return%d\n", ft_strncmp(s1, s1, 0));
	printf("test num %d\n", 1);
	printf("result of return%d\n", ft_strncmp(s1, t1, 3));
	printf("test num %d\n", 2);
	printf("result of return%d\n", ft_strncmp(s1, t1, 10));
	printf("test num %d\n", 3);
	printf("result of return%d\n", ft_strncmp(s2, t2, 0));
	printf("test num %d\n", 4);
	printf("result of return%d\n", ft_strncmp(s2, t2, 3));
	printf("test num %d\n", 5);
	printf("result of return%d\n", ft_strncmp(s2, t2, 10));
	printf("test num %d\n", 6);
	printf("result of return%d\n", ft_strncmp(s3, t3, 0));
	printf("test num %d\n", 7);
	printf("result of return%d\n", ft_strncmp(s4, t4, 3));
	printf("test num %d\n", 10);
	printf("result of return%d\n", ft_strncmp(s4, t4, 10));
	printf("test num %d\n", 11);
	printf("result of return%d\n", ft_strncmp(s5, t5, 0));
	printf("test num %d\n", 12);
	printf("result of return%d\n", ft_strncmp(s5, t5, 3));
	printf("test num %d\n", 13);
	printf("result of return%d\n", ft_strncmp(s5, t5, 10));
	printf("test num %d\n", 14);
	printf("result of return%d\n", ft_strncmp(s6, t6, 0));
	printf("test num %d\n", 15);
	printf("result of return%d\n", ft_strncmp(s6, t6, 3));
	printf("test num %d\n", 16);
	printf("result of return%d\n", ft_strncmp(s6, t6, 10));
	printf("test num %d\n", 17);
	printf("result of return%d\n", ft_strncmp(s7, t7, 0));
	printf("test num %d\n", 18);
	printf("result of return%d\n", ft_strncmp(s8, t8, 6));
	printf("test num %d\n", 19);
}

*/