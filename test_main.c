/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:49:19 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/12 19:56:02 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "libft.h"
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <assert.h>


void	is_x_test(int (*origin)(int c), int (*ft_func)(int c), int *test, char *funcname)
{
	int	origin_res, ft_func_res;
	printf("%s\n", funcname);
	while (*test != 5555)
	{
		printf("test value is %c\n", *test);
		origin_res = origin(*test);
		ft_func_res = ft_func(*test);
		assert(origin_res == ft_func_res);
		if (origin_res == ft_func_res)
			printf("result is same origin: %d, ft_func: %d\n", origin_res, ft_func_res);
		else
			printf("\x1b[31mtest result is not same origin: %d, ft_func: %d\n\x1b[39m", origin_res, ft_func_res);
		test++;
	}
	printf("\x1b[34mtest is completed\n\n\x1b[39m");
}

void	test_strlen()
{
	printf("%s\n", "ft_strlen");
	if (strlen("Hello")==ft_strlen("Hello"))
		printf("result is same\n");
	else
		printf("\x1b[31mtest result is not same origin: %ld, ft_func: %ld\n\x1b[39m", strlen("Hello"),ft_strlen("Hello"));
	if (strlen("")==ft_strlen(""))
		printf("result is same\n");
	else
		printf("\x1b[31mtest result is not same origin: %ld, ft_func: %ld\n\x1b[39m", strlen(""),ft_strlen(""));
	if (strlen("\10\200\300")==ft_strlen("\10\200\300"))
		printf("result is same\n");
	else
		printf("\x1b[31mtest result is not same origin: %ld, ft_func: %ld\n\x1b[39m", strlen("\10\200\300"),ft_strlen("\10\200\300"));
	printf("\x1b[34mtest is completed\n\n\x1b[39m");
}

void	test_memset(void *(*origin)(void *ptr, int value, size_t num), void *(*ft_func)(void *ptr, int value, size_t num), void *test, char *funcname, size_t num, void *test2)
{
	int		i;

	i = 0;
	printf("%s\n", funcname);
	origin(test, 85, num);
	ft_func(test2,85, num);
	while (i < (int)num)
	{
		if (((char *)test)[i] == ((char *)test2)[i])
			printf("result is same origin: %d, ft_func: %d\n", ((char *)test)[i],  ((char *)test2)[i]);
		else
			printf("\x1b[31mtest result is not same origin: %c, ft_func: %c\n\x1b[39m", ((char *)test)[i],  ((char *)test2)[i]);
		i++;
	}
	printf("\x1b[34mtest is completed\n\n\x1b[39m");
}

void	test_bzero()
{
	printf("%s\n", "test_bzero");
	int		i;
	char r[20] = "helloworld!!";
	char f[20] = "helloworld!!";

	i = 0;
	bzero(r, 8);
	ft_bzero(f,8);

	while (f[i] == 0 && r[i] == 0 && i < 8)
		i++;
	if (!strcmp(r,f))
		printf("result is correct\n");
	else
		printf("result is wrong\n");
	printf("\x1b[34mtest is completed\n\n\x1b[39m");
}

void	test_memcpy(void *(*origin)(void *d_ptr, const void *s_ptr, size_t num), void *(*ft_func)(void *d_ptr,const void *s_ptr, size_t num), void *dest, void *src,void *dest2, void *src2, char *funcname, size_t num )
{
	int		i;

	i = 0;
	printf("%s\n", funcname);
	origin(dest, src, num);
	ft_func(dest2, src2, num);
	while (i < (int)num)
	{
		if (((char *)dest)[i] == ((char *)dest2)[i] && ((char *)dest2)[i] == ((char *)src2)[i])
			printf("result is same origin: %c, ft_func: %c, src: %c \n", ((char *)dest)[i], ((char *)dest2)[i], ((char *)src2)[i]);
		else
			printf("\x1b[31mtest result is not same origin: %c, ft_func: %c, src: %c \n\x1b[39m", ((char *)dest)[i], ((char *)dest2)[i], ((char *)src2)[i]);
		i++;
	}
	printf("\x1b[34mtest is completed\n\n\x1b[39m");
}

void	test_memmove()
{
	printf("%s\n", "ft_memmove");
	char src[20] = "abcdef";
	char ftsrc[20] = "abcdef";
	char src1[20] = "xyzabc";
	char ftsrc1[20] = "xyzabc";
	char src2[20] = "abcdef";
	char ftsrc2[20] = "abcdef";
	printf("result of origin %s: result of your function %s:\n", memmove(src,src + 2,3),ft_memmove(ftsrc,ftsrc + 2,3));
	printf("result of origin %s: result of your function %s:\n", memmove(src1,src1 + 5, 6),ft_memmove(ftsrc1,ftsrc1 + 5, 6));
	printf("result of origin %s: result of your function %s:\n", memmove(src2,src2 + 3, 0),ft_memmove(ftsrc2,ftsrc2 + 3, 0));
	printf("\x1b[34mtest is completed\n\n\x1b[39m");
}


void	test_to_x(int (*origin)(int c),int (*ft_func)(int c), int *testval, char *funcname )
{
	int	origin_rt, ft_func_rt;

	printf("%s\n", funcname);
	while (*testval != 55555)
	{
		origin_rt = origin(*testval);
		ft_func_rt = ft_func(*testval);
		if (origin_rt == ft_func_rt)
			printf("result is same origin: %c, ft_func: %c\n", origin_rt, ft_func_rt);
		else
			printf("\x1b[31mtest result is not same origin: %c, ft_func: %c\n\x1b[39m", origin_rt, ft_func_rt);
		testval++;
	}
	printf("\x1b[34mtest is completed\n\n\x1b[39m");

}
void	test_strlcpy()
{
	printf("%s\n", "ft_strlcpy");
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
	char dst8[200] = {"abcde2\0"};
	char dst9[200] = {"test\0"};
	char *dst13 = NULL;
	char src1[] = {"test\0"};
	char src2[] = {"test\0"};
	char src3[] = {"Hello world\0"};
	char src4[] = {"testabcdef"};
	char src5[] = {"testabcdef!!The world is funtastic!!"};
	char src6[] = {"testabcdef!!The world is funtastic!!"};
	char src8[0];
	char src9[] = {"hello\0"};
	char src13[100] = {"test\0"};

	char ft_dst1[50] = {"Hello\0"};
	char ft_dst2[200] = {"abcde2\0"};
	char ft_dst3[200] = {"hello\0"};
	char ft_dst4[50] = {"Hello\0"};
	char ft_dst5[200] = {"abcde2\0"};
	char ft_dst6[200] = {"hello !!The world is funtastic!! world\0"};
	char ft_dst8[200] = {"abcde2\0"};
	char ft_dst9[200] = {"test\0"};
	char *ft_dst13 = NULL;
	char ft_src1[] = {"test\0"};
	char ft_src2[] = {"test\0"};
	char ft_src3[] = {"Hello world\0"};
	char ft_src4[] = {"testabcdef"};
	char ft_src5[] = {"testabcdef!!The world is funtastic!!"};
	char ft_src6[] = {"testabcdef!!The world is funtastic!!"};
	char ft_src8[0];
	char ft_src9[] = {"hello\0"};
	char ft_src13[100] = {"test\0"};

	printf("origin :%ld ft_func:%ld\n", strlcpy(dst1, src1, 10),ft_strlcpy(ft_dst1, ft_src1, 10));
	printf("origin result:%s ft_result:%s\n", dst1,ft_dst1);
	printf("origin :%ld ft_func:%ld\n", strlcpy(dst2, src2, 5),ft_strlcpy(ft_dst2, ft_src2, 5));
	printf("origin result:%s ft_result:%s\n", dst2,ft_dst2);
	printf("origin :%ld ft_func:%ld\n", strlcpy(dst3, src3, 15),ft_strlcpy(ft_dst3, ft_src3, 15));
	printf("origin result:%s ft_result:%s\n", dst3,ft_dst3);
	printf("origin :%ld ft_func:%ld\n", strlcpy(dst4, src4, 8),ft_strlcpy(ft_dst4, ft_src4, 8));
	printf("origin result:%s ft_result:%s\n", dst4,ft_dst4);
	printf("origin :%ld ft_func:%ld\n", strlcpy(dst5, src5, 1),ft_strlcpy(ft_dst5, ft_src5, 1));
	printf("origin result:%s ft_result:%s\n", dst5,ft_dst5);
	printf("origin :%ld ft_func:%ld\n", strlcpy(dst6, src6, 5),ft_strlcpy(ft_dst6, ft_src6, 5));
	printf("origin result:%s ft_result:%s\n", dst6,ft_dst6);
	printf("origin :%ld ft_func:%ld\n", strlcpy(dst8, src8, 8),ft_strlcpy(ft_dst8, ft_src8, 8));
	printf("origin result:%s ft_result:%s\n", dst8,ft_dst8);
	printf("origin :%ld ft_func:%ld\n", strlcpy(dst9, src9, 0),ft_strlcpy(ft_dst9, ft_src9, 0));
	printf("origin result:%s ft_result:%s\n", dst9,ft_dst9);
	printf("origin :%ld ft_func:%ld\n", strlcpy(dst13, src13, 0),ft_strlcpy(ft_dst13, ft_src13, 0));
	printf("origin result:%s ft_result:%s\n", dst13,ft_dst13);
	printf("\x1b[34mtest is completed\n\n\x1b[39m");
}

void	test_strlcat(void)
{
	printf("%s\n", "ft_strlcat");
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
	char dst8[200] = {"abcde2\0"};
	char dst9[200] = {"test\0"};
	char *dst13 = NULL;
	char src1[] = {"test\0"};
	char src2[] = {"test\0"};
	char src3[] = {"Hello world\0"};
	char src4[] = {"testabcdef"};
	char src5[] = {"testabcdef!!The world is funtastic!!"};
	char src6[] = {"testabcdef!!The world is funtastic!!"};
	char src8[0];
	char src9[] = {"hello\0"};
	char src13[100] = {"test\0"};

	char ft_dst1[50] = {"Hello\0"};
	char ft_dst2[200] = {"abcde2\0"};
	char ft_dst3[200] = {"hello\0"};
	char ft_dst4[50] = {"Hello\0"};
	char ft_dst5[200] = {"abcde2\0"};
	char ft_dst6[200] = {"hello !!The world is funtastic!! world\0"};
	char ft_dst8[200] = {"abcde2\0"};
	char ft_dst9[200] = {"test\0"};
	char *ft_dst13 = NULL;
	char ft_src1[] = {"test\0"};
	char ft_src2[] = {"test\0"};
	char ft_src3[] = {"Hello world\0"};
	char ft_src4[] = {"testabcdef"};
	char ft_src5[] = {"testabcdef!!The world is funtastic!!"};
	char ft_src6[] = {"testabcdef!!The world is funtastic!!"};
	char ft_src8[0];
	char ft_src9[] = {"hello\0"};
	char ft_src13[100] = {"test\0"};

	printf("origin :%ld ft_func:%ld\n", strlcat(dst1, src1, 10),ft_strlcat(ft_dst1, ft_src1, 10));
	printf("origin result:%s ft_result:%s\n", dst1,ft_dst1);
	printf("origin :%ld ft_func:%ld\n", strlcat(dst2, src2, 5),ft_strlcat(ft_dst2, ft_src2, 5));
	printf("origin result:%s ft_result:%s\n", dst2,ft_dst2);
	printf("origin :%ld ft_func:%ld\n", strlcat(dst3, src3, 15),ft_strlcat(ft_dst3, ft_src3, 15));
	printf("origin result:%s ft_result:%s\n", dst3,ft_dst3);
	printf("origin :%ld ft_func:%ld\n", strlcat(dst4, src4, 8),ft_strlcat(ft_dst4, ft_src4, 8));
	printf("origin result:%s ft_result:%s\n", dst4,ft_dst4);
	printf("origin :%ld ft_func:%ld\n", strlcat(dst5, src5, 1),ft_strlcat(ft_dst5, ft_src5, 1));
	printf("origin result:%s ft_result:%s\n", dst5,ft_dst5);
	printf("origin :%ld ft_func:%ld\n", strlcat(dst6, src6, 5),ft_strlcat(ft_dst6, ft_src6, 5));
	printf("origin result:%s ft_result:%s\n", dst6,ft_dst6);
	printf("origin :%ld ft_func:%ld\n", strlcat(dst8, src8, 8),ft_strlcat(ft_dst8, ft_src8, 8));
	printf("origin result:%s ft_result:%s\n", dst8,ft_dst8);
	printf("origin :%ld ft_func:%ld\n", strlcat(dst9, src9, 0),ft_strlcat(ft_dst9, ft_src9, 0));
	printf("origin result:%s ft_result:%s\n", dst9,ft_dst9);
	printf("origin :%ld ft_func:%ld\n", strlcat(dst13, src13, 0),ft_strlcat(ft_dst13, ft_src13, 0));
	printf("origin result:%s ft_result:%s\n", dst13,ft_dst13);
	printf("\x1b[34mtest is completed\n\n\x1b[39m");
}

void	test_strchr()
{
	printf("%s\n", "ft_strchr");
	char	s[20] = "abcdefg";
	char	c[20] = "ag01\200";
	int		i;

	i = 0;
	while (c[i])
	{
		if (strchr(s, c[i]) == ft_strchr(s, c[i]))
			printf("result is same\n");
		else
		{
			printf("\x1b[31mresult is different original: %p,ft_func: %p\n",strchr(s, c[i]),ft_strchr(s, c[i]));
		}
		i++;
	}
	printf("\x1b[34mtest is completed\n\n\x1b[39m");
}

void	test_strrchr()
{
	printf("%s\n", "ft_strrchr");
	char	s[20] = "abcdefg";
	char	c[20] = "ag01\200";
	int		i;

	i = 0;
	while (c[i])
	{
		if (strrchr(s, c[i]) == ft_strrchr(s, c[i]))
			printf("result is same\n");
		else
		{
			printf("\x1b[31mresult is different original: %p,ft_func: %p\n",strrchr(s, c[i]),ft_strrchr(s, c[i]));
		}
		i++;
	}
	printf("\x1b[34mtest is completed\n\n\x1b[39m");
}

void	test_strncmp()
{
	printf("%s\n", "ft_strncmp");
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

	printf("origin :%d ft_func:%d\n", strncmp(s1, s1, 0), ft_strncmp(s1, s1, 0));
	printf("origin :%d ft_func:%d\n", strncmp(s1, t1, 3), ft_strncmp(s1, t1, 3));
	printf("origin :%d ft_func:%d\n", strncmp(s1, t1, 10), ft_strncmp(s1, t1, 10));
	printf("origin :%d ft_func:%d\n", strncmp(s2, t2, 0),ft_strncmp(s2, t2, 0));
	printf("origin :%d ft_func:%d\n", strncmp(s2, t2, 3),ft_strncmp(s2, t2, 3));
	printf("origin :%d ft_func:%d\n", strncmp(s2, t2, 10),ft_strncmp(s2, t2, 10));
	printf("origin :%d ft_func:%d\n", strncmp(s3, t3, 0),ft_strncmp(s3, t3, 0));
	printf("origin :%d ft_func:%d\n", strncmp(s4, t4, 3), ft_strncmp(s4, t4, 3));
	printf("origin :%d ft_func:%d\n", strncmp(s4, t4, 10), ft_strncmp(s4, t4, 10));
	printf("origin :%d ft_func:%d\n", strncmp(s5, t5, 0),ft_strncmp(s5, t5, 0));
	printf("origin :%d ft_func:%d\n", strncmp(s5, t5, 3), ft_strncmp(s5, t5, 3));
	printf("origin :%d ft_func:%d\n", strncmp(s5, t5, 10),ft_strncmp(s5, t5, 10));
	printf("origin :%d ft_func:%d\n", strncmp(s6, t6, 0), ft_strncmp(s6, t6, 0));
	printf("origin :%d ft_func:%d\n", strncmp(s6, t6, 3), ft_strncmp(s6, t6, 3));
	printf("origin :%d ft_func:%d\n", strncmp(s6, t6, 10), ft_strncmp(s6, t6, 10));
	printf("origin :%d ft_func:%d\n", strncmp(s7, t7, 0), ft_strncmp(s7, t7, 0));
	printf("origin :%d ft_func:%d\n", strncmp(s8, t8, 6), ft_strncmp(s8, t8, 6));
	printf("\x1b[34mtest is completed\n\n\x1b[39m");
}

void	test_memchr()
{
	printf("%s\n", "ft_memchr");
	char	s[20] = "abcdefg";
	char	c[20] = "ag01\200";
	int		i;

	i = 0;
	while (c[i])
	{
		if (memchr(s, c[i],6) == ft_memchr(s, c[i],6))
			printf("result is same\n");
		else
			printf("\x1b[31mresult is different original: %p,ft_func: %p\n",memchr(s, c[i],6),ft_memchr(s, c[i],6));
		i++;
	}
	printf("\x1b[34mtest is completed\n\n\x1b[39m");
}

void	test_memcmp()
{
	printf("%s\n", "ft_memcmp");
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
	unsigned long long ul = 18446744073709551615ULL;
	unsigned long long ul1 = 18446744073709551615ULL;

	printf("origin :%d ft_func:%d\n", memcmp(s1, s1, 0), ft_memcmp(s1, s1, 0));
	printf("origin :%d ft_func:%d\n", memcmp(s1, t1, 3), ft_memcmp(s1, t1, 3));
	printf("origin :%d ft_func:%d\n", memcmp(s1, t1, 10), ft_memcmp(s1, t1, 10));
	printf("origin :%d ft_func:%d\n", memcmp(s2, t2, 0),ft_memcmp(s2, t2, 0));
	printf("origin :%d ft_func:%d\n", memcmp(s2, t2, 3),ft_memcmp(s2, t2, 3));
	printf("origin :%d ft_func:%d\n", memcmp(s2, t2, 10),ft_memcmp(s2, t2, 10));
	printf("origin :%d ft_func:%d\n", memcmp(s3, t3, 0),ft_memcmp(s3, t3, 0));
	printf("origin :%d ft_func:%d\n", memcmp(s4, t4, 3), ft_memcmp(s4, t4, 3));
	printf("origin :%d ft_func:%d\n", memcmp(s4, t4, 10), ft_memcmp(s4, t4, 10));
	printf("origin :%d ft_func:%d\n", memcmp(s5, t5, 0),ft_memcmp(s5, t5, 0));
	printf("origin :%d ft_func:%d\n", memcmp(s5, t5, 3), ft_memcmp(s5, t5, 3));
	printf("origin :%d ft_func:%d\n", memcmp(s5, t5, 10),ft_memcmp(s5, t5, 10));
	printf("origin :%d ft_func:%d\n", memcmp(s6, t6, 0), ft_memcmp(s6, t6, 0));
	printf("origin :%d ft_func:%d\n", memcmp(s6, t6, 3), ft_memcmp(s6, t6, 3));
	printf("origin :%d ft_func:%d\n", memcmp(s6, t6, 10), ft_memcmp(s6, t6, 10));
	printf("origin :%d ft_func:%d\n", memcmp(s7, t7, 0), ft_memcmp(s7, t7, 0));
	printf("origin :%d ft_func:%d\n", memcmp(s8, t8, 6), ft_memcmp(s8, t8, 6));
	printf("origin :%d ft_func:%d\n", memcmp(&ul, &ul1, 8), ft_memcmp(&ul, &ul1, 8));
	printf("\x1b[34mtest is completed\n\n\x1b[39m");
}

void	test_strnstr()
{
	printf("%s\n", "ft_strnstr");
	char s1[30] = "aaabcabcd";
	char s2[10] = "cd";
	char s3[30] = "aaabcabcd";
	char s4[10] = "cde";
	char s5[30] = "aaabcabcd";
	char s6[10] = "aab";
	char s7[30] = "aaabcabcd";
	char s8[10] = "";
	char s9[30] = "";
	char s10[10] = "cde";
	char s11[30] = "a";
	char s12[10] = "ca";
	char s13[30] = "aaabcabcd";
	char s14[10] = "cd";

	size_t max = strlen(s1);

	if (strcmp(strnstr(s1, s2, max),ft_strnstr(s1, s2, max)) == 0)
		printf("result is same\n");
	else
		printf("\x1b[31mresult is different original: %p,ft_func: %p\n",strnstr(s1, s2, max),ft_strnstr(s1, s2, max));
	if ((strnstr(s3, s4, max)== ft_strnstr(s3, s4, max)))
		printf("result is same\n");
	else
		printf("\x1b[31mresult is different original: %p,ft_func: %p\n",strnstr(s3, s4, max),ft_strnstr(s3, s4, max));
	if (strcmp(strnstr(s5, s6, max),ft_strnstr(s5, s6, max)) == 0)
		printf("result is same\n");
	else
		printf("\x1b[31mresult is different original: %p,ft_func: %p\n",strnstr(s5, s6, max),ft_strnstr(s5, s6, max));
	if (strcmp(strnstr(s7, s8, max),ft_strnstr(s7, s8, max)) == 0)
		printf("result is same\n");
	else
		printf("\x1b[31mresult is different original: %p,ft_func: %p\n",strnstr(s7, s8, max),ft_strnstr(s7, s8, max));
	if (strnstr(s9, s10, max)==ft_strnstr(s9, s10, max))
		printf("result is same\n");
	else
		printf("\x1b[31mresult is different original: %p,ft_func: %p\n",strnstr(s9, s10, max),ft_strnstr(s9, s10, max));
	if (strnstr(s11, s12, max)==ft_strnstr(s11, s12, max))
		printf("result is same\n");
	else
		printf("\x1b[31mresult is different original: %p,ft_func: %p\n",strnstr(s11, s12, max),ft_strnstr(s11, s12, max));
	if (strnstr(s13, s14, 4) == ft_strnstr(s13, s14, 4))
		printf("result is same\n");
	else
		printf("\x1b[31mresult is different original: %p,ft_func: %p\n",strnstr(s13, s14, 4),ft_strnstr(s13, s14, 4));
	printf("\x1b[34mtest is completed\n\n\x1b[39m");
}

void	test_atoi()
{
	printf("%s\n", "ft_atoi");
	char s1[30] = "-2147483648";
	char s2[30] = "2147483647";
	char s3[30] = "4294967295";
	char s4[30] = "18446744073709551615";
	char s5[30] = "0";
	char s6[30] = "+2147483648";
	char s7[30] = "-----2147483647";
	char s8[30] = "\t+123";
	char s9[30] = "\v-1234";
	char s10[30] = "\f-123456789";
	char s11[30] = "\r-1234";
	char s12[30] = " -123456789";
	char s13[30] = "\r-1234";
	char s14[30] = "\t\v\f\r -123456789";
	if ((atoi(s1)==ft_atoi(s1)))
		printf("result is same\n");
	else
		printf("\x1b[31mresult is different original: %d,ft_func: %d\n",atoi(s1),ft_atoi(s1));
	if ((atoi(s2)==ft_atoi(s2)))
		printf("result is same\n");
	else
		printf("\x1b[31mresult is different original: %d,ft_func: %d\n",atoi(s2),ft_atoi(s2));
	if ((atoi(s3)==ft_atoi(s3)))
		printf("result is same\n");
	else
		printf("\x1b[31mresult is different original: %d,ft_func: %d\n",atoi(s3),ft_atoi(s3));
	if ((atoi(s4)==ft_atoi(s4)))
		printf("result is same\n");
	else
		printf("\x1b[31mresult is different original: %d,ft_func: %d\n",atoi(s4),ft_atoi(s4));
	if ((atoi(s5)==ft_atoi(s5)))
		printf("result is same\n");
	else
		printf("\x1b[31mresult is different original: %d,ft_func: %d\n",atoi(s5),ft_atoi(s5));
	if ((atoi(s6)==ft_atoi(s6)))
		printf("result is same\n");
	else
		printf("\x1b[31mresult is different original: %d,ft_func: %d\n",atoi(s6),ft_atoi(s6));
	if ((atoi(s7)==ft_atoi(s7)))
		printf("result is same\n");
	else
		printf("\x1b[31mresult is different original: %d,ft_func: %d\n",atoi(s7),ft_atoi(s7));
	if ((atoi(s8)==ft_atoi(s8)))
		printf("result is same\n");
	else
		printf("\x1b[31mresult is different original: %d,ft_func: %d\n",atoi(s8),ft_atoi(s8));
	if ((atoi(s9)==ft_atoi(s9)))
		printf("result is same\n");
	else
		printf("\x1b[31mresult is different original: %d,ft_func: %d\n",atoi(s9),ft_atoi(s9));
	if ((atoi(s10)==ft_atoi(s10)))
		printf("result is same\n");
	else
		printf("\x1b[31mresult is different original: %d,ft_func: %d\n",atoi(s10),ft_atoi(s10));
	if ((atoi(s11)==ft_atoi(s11)))
		printf("result is same\n");
	else
		printf("\x1b[31mresult is different original: %d,ft_func: %d\n",atoi(s11),ft_atoi(s11));
	if ((atoi(s12)==ft_atoi(s12)))
		printf("result is same\n");
	else
		printf("\x1b[31mresult is different original: %d,ft_func: %d\n",atoi(s12),ft_atoi(s12));
	if ((atoi(s13)==ft_atoi(s13)))
		printf("result is same\n");
	else
		printf("\x1b[31mresult is different original: %d,ft_func: %d\n",atoi(s13),ft_atoi(s13));
	if ((atoi(s14)==ft_atoi(s14)))
		printf("result is same\n");
	else
		printf("\x1b[31mresult is different original: %d,ft_func: %d\n",atoi(s14),ft_atoi(s14));
	printf("\x1b[34mtest is completed\n\n\x1b[39m");
}

void	test_calloc()
{
	unsigned char *test;
	unsigned char *origin;
	unsigned long long int		i;
	i = 0;
	test = (unsigned char *)ft_calloc(SIZE_MAX,1);
	origin = (unsigned char *)calloc(SIZE_MAX,1);
	if (test == NULL && origin == NULL)
		printf("result is same\n");
	else
	{
		while(test[i] == 0)
			i++;
		if (i == SIZE_MAX)
			printf("result is correct\n");
		else
			printf("result is wrong");
	}
	test = (unsigned char *)ft_calloc(1,1);
	origin = (unsigned char *)calloc(1,1);
	i = 0;
	if (test == NULL && origin == NULL)
		printf("result is same\n");
	else
	{
		while(test[i] == origin[i] && i < 1)
			i++;
		if (i == 1)
			printf("result is correct\n");
		else
			printf("result is wrong\n");
	}
	i = 0;
	test = (unsigned char *)ft_calloc(0,1);
	origin = (unsigned char *)calloc(0,1);
	if (test == NULL && origin == NULL)
		printf("result is same\n");
	else
	{
		while(test[i] == origin[i] && i < 1)
			i++;
		if (i == 1)
			printf("result is correct\n");
		else
			printf("result is wrong\n");
	}
	printf("\x1b[34mtest is completed\n\n\x1b[39m");
}

void	test_strdup()
{
	printf("%s\n", "ft_strdup");
	char	*s1 = "Helloworld";
	char	*s2 = "";
	char	*s3 = "\200abc";

	if (strcmp(strdup(s1),ft_strdup(s1))== 0)
		printf("result is same\n");
	else
		printf("\x1b[31mresult is different original: %s,ft_func: %s\n",strdup(s1),ft_strdup(s1));
	if (strcmp(strdup(s2),ft_strdup(s2))== 0)
		printf("result is same\n");
	else
		printf("\x1b[31mresult is different original: %s,ft_func: %s\n",strdup(s2),ft_strdup(s2));
	if (strcmp(strdup(s3),ft_strdup(s3))== 0)
		printf("result is same\n");
	else
		printf("\x1b[31mresult is different original: %s,ft_func: %s\n",strdup(s3),ft_strdup(s3));
	printf("\x1b[34mtest is completed\n\n\x1b[39m");
}

int	main(void)
{
	int	testval[] = {'1','f','#','r','0','P','\177', '\0',130, 256, 5555};
	is_x_test(isdigit,ft_isdigit, testval, "ft_isdigit");
	is_x_test(isalpha, ft_isalpha, testval, "ft_isalpha");
	is_x_test(isalnum, ft_isalnum, testval, "ft_isalnum");
	is_x_test(isascii, ft_isascii, testval, "ft_isascii");
	is_x_test(isprint, ft_isprint, testval, "ft_isprint");

	test_strlen();

	int		testdata_memset[3];
	int		testdata_memset2[3];

	test_memset(memset, ft_memset, &testdata_memset,"memset",sizeof (testdata_memset),&testdata_memset2);
	test_bzero();

	char	dest[100], dest2[100];
	char	src[] = "memcpytest123\127", src2[] = "memcpytest123\127";
	test_memcpy(memcpy, ft_memcpy, dest, src, dest2, src2, "memcpy",15);
	int	test[] = {'a','t','z','A','Z', 0, 127, 255, -1, 2147483647, -2147483648, 256, 55555};
	test_to_x(toupper, ft_toupper, test, "ft_toupper");
	test_to_x(tolower, ft_tolower, test, "ft_tolower");
	test_memmove();
	test_strlcpy();
	test_strlcat();
	test_strchr();
	test_strrchr();
	test_strncmp();
	test_memchr();
	test_memcmp();
	test_strnstr();
	test_atoi();
	test_calloc();
	test_strdup();
}
