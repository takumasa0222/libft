/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:49:19 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/03 13:16:32 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "libft.h"
#include <string.h>
#include <strings.h>
 #include <stdlib.h>


void	is_x_test(int (*origin)(int c), int (*ft_func)(int c), int *test, char *funcname)
{
	int	origin_res, ft_func_res;
	printf("%s\n", funcname);
	while (*test != 5555)
	{
		printf("test value is %c\n", *test);
		origin_res = origin(*test);
		ft_func_res = ft_func(*test);
		if (origin_res == ft_func_res)
			printf("result is same origin: %d, ft_func: %d\n", origin_res, ft_func_res);
		else
			printf("\x1b[31mtest result is not same origin: %d, ft_func: %d\n\x1b[39m", origin_res, ft_func_res);
		test++;
	}
	printf("\x1b[34mtest is completed\n\n\x1b[39m");
}

void	test_strlen(size_t (*origin)(const char *s), size_t (*ft_func)(const char *s), const char **test, char *funcname)
{
	size_t	origin_res, ft_func_res;
	printf("%s\n", funcname);
	while (*test)
	{
		printf("test value is %s\n", *test);
		origin_res = origin(*test);
		ft_func_res = ft_func(*test);
		if (origin_res == ft_func_res)
			printf("result is same origin: %ld, ft_func: %ld\n", origin_res, ft_func_res);
		else
			printf("\x1b[31mtest result is not same origin: %ld, ft_func: %ld\n\x1b[39m", origin_res, ft_func_res);
		test++;
	}
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

void	test_bzero(void (*origin)(void *ptr, size_t num), void (*ft_func)(void *ptr, size_t num), void *test, void *test2, char *funcname, size_t num )
{
	int		i;

	i = 0;
	printf("%s\n", funcname);
	origin(test,  num);
	ft_func(test2, num);
	while (i < (int)num/sizeof (int))
	{
		if (((char *)test)[i] == ((char *)test2)[i])
			printf("result is same origin: %d, ft_func: %d\n", ((char *)test)[i],  ((char *)test2)[i]);
		else
			printf("\x1b[31mtest result is not same origin: %d, ft_func: %d\n\x1b[39m", ((char *)test)[i],  ((char *)test2)[i]);
		i++;
	}
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

void	tryal()
{
	char testbal[12];
	int i = 0;
	memset(&testbal,255,sizeof(testbal));
	while (i < 12)
	{
		printf("testbal value is %d\n",testbal[i]);
		i++;
	}

}

int	main(void)
{
	int	testval[] = {'1','f','#','r','0','P','\177', '\0',130, 256, 5555};
	is_x_test(isdigit,ft_isdigit, testval, "ft_isdigit");
	is_x_test(isalpha, ft_isalpha, testval, "ft_isalpha");
	is_x_test(isalnum, ft_isalnum, testval, "ft_isalnum");
	is_x_test(isascii, ft_isascii, testval, "ft_isascii");
	is_x_test(isprint, ft_isprint, testval, "ft_isprint");

	const char	**teststr;
	malloc
	teststr[0] = "Hello";
	// teststr[1] = "1234";
	// teststr[2] = "";
	// teststr[3] = NULL;
	// teststr[4] = "End";
	test_strlen(strlen, ft_strlen, teststr, "ft_strlen");

	int		testdata_memset[3];
	int		testdata_memset2[3];

	test_memset(memset, ft_memset, &testdata_memset,"memset",sizeof (testdata_memset),&testdata_memset2);
	test_bzero(bzero, ft_bzero,&testdata_memset,&testdata_memset2,"bzero",sizeof (testdata_memset));

	char	dest[100], dest2[100];
	char	src[] = "memcpytest123\127", src2[] = "memcpytest123\127";
	test_memcpy(memcpy, ft_memcpy, dest, src, dest2, src2, "memcpy",15);
	//tryal();

	int	test[] = {'a','t','z','A','Z', 0, 127, 255, -1, 2147483647, -2147483648, 256, 55555};
	test_to_x(toupper, ft_toupper, test, "ft_toupper");
	test_to_x(tolower, ft_tolower, test, "ft_tolower");

}
