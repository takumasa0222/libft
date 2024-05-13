/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_part2_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:49:19 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/13 23:25:58 by tamatsuu         ###   ########.fr       */
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
	printf("\x1b[31mNG \x1b[39m");
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
	printf("\n");
}

void	test_strjoin()
{
	printf("strjoin\n");
	char	*t1 = "Hello";
	char	*t2 = "World";
	char	*t3;

	t3 = ft_strjoin(t1, t2);
	if (strlen(t3) == 10 && !strcmp(t3, "HelloWorld"))
		succuss();
	else
		fail();
	t3 = ft_strjoin(t1, NULL);
	if (strlen(t3) == 5 && !strcmp(t3, "Hello"))
		succuss();
	else
		fail();
	t3 = ft_strjoin(NULL, t2);
	if (strlen(t3) == 5 && !strcmp(t3, "World"))
		succuss();
	else
		fail();
	t3 = ft_strjoin("", "");
	if (strlen(t3) == 0 && !strcmp(t3, ""))
		succuss();
	else
		fail();
	printf("\n");
}
void	test_strtrim()
{
	char *ret;
	printf("strtrim\n");
	ret = ft_strtrim("aabbcchelloworldccbbaa", "abc");
	if (!strcmp(ret, "helloworld"))
		succuss();
	else
		fail();

	ret = ft_strtrim("aaBbcchelloworldccbbaa", "abc");
	if (!strcmp(ret, "Bbcchelloworld"))
		succuss();
	else
		fail();
	ret = ft_strtrim("aabbcchelloworldccbbaa", "abc");
	if (!strcmp(ret, "helloworld"))
		succuss();
	else
		fail();
	ret = ft_strtrim("aabbcchelloworldccDbaa", "abc");
	if (!strcmp(ret, "helloworldccD"))
		succuss();
	else
		fail();
	ret = ft_strtrim("aabbcchelloworldccbbaa", "");
	if (!strcmp(ret, "aabbcchelloworldccbbaa"))
		succuss();
	else
		fail();
	ret = ft_strtrim("", "abc");
	if (!strcmp(ret, ""))
		succuss();
	else
		fail();
	ret = ft_strtrim(NULL, "abc");
	if (ret == NULL)
		succuss();
	else
		fail();
	ret = ft_strtrim("hello", NULL);
	if (ret == NULL)
		succuss();
	else
		fail();
	printf("\n");
}

void	test_split()
{
	printf("split\n");
	char	**ret;
	char	*test[5] = {"He", "owor", "d", NULL};
	int		i = 0;
	ret = ft_split("Helloworld", 'l');
	while (ret[i] != NULL)
	{
		if (strcmp(ret[i], test[i]))
			fail();
		i++;
	}
	if (i == 3)
		succuss();
	char	*test1[5] = {"HeWord", NULL};
	i = 0;
	ret = ft_split("HeWord", 'l');
	while (ret[i] != NULL)
	{
		if (strcmp(ret[i], test1[i]))
			fail();
		i++;
	}
	if (i == 1)
		succuss();

	char	*test2[5] = {NULL};
	i = 0;
	ret = ft_split(NULL, 'l');
	if (i == 0 && ret == NULL)
		succuss();

	char	*test3[5] = {"HelloWord", NULL};
	i = 0;
	ret = ft_split("HelloWord", '\0');
	while (ret[i] != NULL)
	{
		if (strcmp(ret[i], test3[i]))
			fail();
		i++;
	}
	if (i == 1)
		succuss();

	char	*test4[5] = {NULL};
	i = 0;
	ret = ft_split("\0HelloWord", '\0');
	if (i == 0 && ret[i] == NULL)
		succuss();
	else
		fail();

	char	*test5[30] = {"He","ll","o","W","o","r","d","  "," ","   ", NULL};
	i = 0;
	ret = ft_split("aaHeaallaaoaWaoaradaaa  a aa   aa", 'a');
	while (ret[i] != NULL)
	{
		if (strcmp(ret[i], test5[i]))
			fail();
		i++;
	}
	if (i == 10 )
		succuss();
}

int	main(void)
{
	// test_substr();
	// test_strjoin();
	// test_strtrim();
	test_split();
}