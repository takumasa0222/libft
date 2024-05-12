/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_part2_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:49:19 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/12 21:20:01 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <assert.h>

void	succuss()
{
	printf("OK ");
}

void	fail()
{
	printf("\x1b[31mNG x1b[39m\n");
}

void	test_substr()
{
	printf("substr\n");
	char *s = ft_substr(NULL, 0, 10);
	if (s == NULL)
		succuss();
	else
		fail();
	s = ft_substr("HelloWorld", 0, 10);
	if (!strcmp(s,"HelloWorld"))
		succuss();
	else
		fail();
	s = ft_substr("HelloWorld", 4, 10);
	if (!strcmp(s,"oWorld"))
		succuss();
	else
		fail();
	s = ft_substr("HelloWorld", 300, 10);
	if (!strcmp(s,""))
		succuss();
	else
		fail();
	s = ft_substr("HelloWorld", 0, 1000000);
	if (!strcmp(s,"HelloWorld"))
		succuss();
	else
		fail();
	s = ft_substr("HelloWorld", 3, SIZE_MAX);
	if (!strcmp(s,"loWorld"))
		succuss();
	else
		fail();
}

void	test_strjoin()
{
	t1 char
}

int	main(void)
{
	test_substr();
	test_strjoin()
}