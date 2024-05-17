/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_part2_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:49:19 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/17 04:39:14 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <assert.h>
#include <fcntl.h>

void	success()
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
		success();
	else
		fail();
	s = ft_substr("HelloWorld", 0, 10);
	if (!strcmp(s,"HelloWorld"))
		success();
	else
		fail();
	s = ft_substr("HelloWorld", 4, 10);
	if (!strcmp(s,"oWorld"))
		success();
	else
		fail();
	s = ft_substr("HelloWorld", 300, 10);
	if (!strcmp(s,""))
		success();
	else
		fail();
	s = ft_substr("HelloWorld", 0, 1000000);
	if (!strcmp(s,"HelloWorld"))
		success();
	else
		fail();
	s = ft_substr("HelloWorld", 3, SIZE_MAX);
	if (!strcmp(s,"loWorld"))
		success();
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
		success();
	else
		fail();
	t3 = ft_strjoin(t1, NULL);
	if (strlen(t3) == 5 && !strcmp(t3, "Hello"))
		success();
	else
		fail();
	t3 = ft_strjoin(NULL, t2);
	if (strlen(t3) == 5 && !strcmp(t3, "World"))
		success();
	else
		fail();
	t3 = ft_strjoin("", "");
	if (strlen(t3) == 0 && !strcmp(t3, ""))
		success();
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
		success();
	else
		fail();

	ret = ft_strtrim("aaBbcchelloworldccbbaa", "abc");
	if (!strcmp(ret, "Bbcchelloworld"))
		success();
	else
		fail();
	ret = ft_strtrim("aabbcchelloworldccbbaa", "abc");
	if (!strcmp(ret, "helloworld"))
		success();
	else
		fail();
	ret = ft_strtrim("aabbcchelloworldccDbaa", "abc");
	if (!strcmp(ret, "helloworldccD"))
		success();
	else
		fail();
	ret = ft_strtrim("aabbcchelloworldccbbaa", "");
	if (!strcmp(ret, "aabbcchelloworldccbbaa"))
		success();
	else
		fail();
	ret = ft_strtrim("", "abc");
	if (!strcmp(ret, ""))
		success();
	else
		fail();
	ret = ft_strtrim(NULL, "abc");
	if (ret == NULL)
		success();
	else
		fail();
	ret = ft_strtrim("hello", NULL);
	if (ret == NULL)
		success();
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
		success();
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
		success();

	char	*test2[5] = {NULL};
	i = 0;
	ret = ft_split(NULL, 'l');
	if (i == 0 && ret == NULL)
		success();

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
		success();

	char	*test4[5] = {NULL};
	i = 0;
	ret = ft_split("\0HelloWord", '\0');
	if (i == 0 && ret[i] == NULL)
		success();
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
		success();
	else
		fail();
	printf("\n");
}

void	test_itoa()
{
	printf("itoa\n");
	if (!strcmp(ft_itoa(0),"0"))
		success();
	else
		fail();
	if (!strcmp(ft_itoa(-0),"0"))
		success();
	else
		fail();
	if (!strcmp(ft_itoa(2147483647),"2147483647"))
		success();
	else
		fail();
	if (!strcmp(ft_itoa(-2147483648),"-2147483648"))
		success();
	else
		fail();
	if (!strcmp(ft_itoa(+123),"123"))
		success();
	else
		fail();
	printf("\n");
}

char addUnsignedIntAndChar(unsigned int a, char b)
{
	return a + (unsigned int)b;
}

void	test_strmapi()
{
	printf("strmapi\n");
	if (!strcmp(ft_strmapi("helloworld",addUnsignedIntAndChar), "hfnos|uytm"))
		success();
	else
		fail();

	if (ft_strmapi(NULL,addUnsignedIntAndChar)==NULL)
		success();
	else
		fail();
	if (ft_strmapi("helloworld",NULL)==NULL)
		success();
	else
		fail();
	printf("\n");
}

void	to_uppera(unsigned int index, char *c)
{
	if (c != NULL)
	{
		*c = toupper(*c);
	}
}

void	test_striteri()
{
	printf("strmapi\n");
	char	s[] = "helloworld\0";
	ft_striteri(s,to_uppera);
	if (!strcmp(s, "HELLOWORLD"))
		success();
	else
		fail();
	ft_striteri(NULL,to_uppera);
	ft_striteri(s,NULL);
	printf("\n");
}

void	test_putchar_fd()
{
	printf("putchar_fd\n");
	int	fd;
	char	buffer[2];
	fd = open("testfile.txt", O_CREAT | O_RDWR, 644);
	if (fd == -1)
	 {
		perror("open");
		return ;
	}
	// ファイルに 'A' を書き込む
	ft_putchar_fd('A', fd);
	// ファイルポインタを先頭に戻す
	lseek(fd, 0, SEEK_SET);
	// ファイルから読み込む
	read(fd, buffer, 1);
	buffer[1] = '\0'; // NULL 終端
	// 結果を検証
	if (buffer[0] == 'A')
		success();
	else
		fail();
	// ファイルを閉じる
	close(fd);
	// テストファイルを削除
	remove("testfile.txt");
	printf("\n");
}
void	test_putstr_fd()
{
	printf("putstr_fd\n");
	int	fd;
	char	buffer[11];
	fd = open("testfile.txt", O_CREAT | O_RDWR, 644);
	if (fd == -1)
	 {
		perror("open");
		return ;
	}
	// ファイルに 'A' を書き込む
	ft_putstr_fd("Helloworld", fd);
	// ファイルポインタを先頭に戻す
	lseek(fd, 0, SEEK_SET);
	// ファイルから読み込む
	read(fd, buffer, 11);
	buffer[11] = '\0'; // NULL 終端
	// 結果を検証
	if (!strcmp(buffer,"Helloworld"))
		success();
	else
		fail();
	// ファイルを閉じる
	close(fd);
	// テストファイルを削除
	remove("testfile.txt");
	printf("\n");
}

void	test_putendl_fd()
{
	printf("putendl_fd\n");
	int	fd;
	char	buffer[12];
	fd = open("testfile.txt", O_CREAT|O_RDWR,644);
	if (fd == -1)
	{
		perror("open");
		return ;
	}
	ft_putendl_fd("Helloworld",fd);
	lseek(fd, 0, SEEK_SET);
	read(fd, buffer, 12);
	buffer[12] = '\0'; 
	if (!strcmp(buffer,"Helloworld\n"))
		success();
	else
		fail();
	// ファイルを閉じる
	close(fd);
	// テストファイルを削除
	remove("testfile.txt");
	printf("\n");
}

void	test_putnbr_fd()
{
	printf("putnbr_fd\n");
	int	fd;
	char	buffer[12]; 
	fd = open("testfile.txt", O_CREAT| O_RDWR, 644);
	if (fd == -1)
	{
		perror("open");
		return ;
	}
	ft_putnbr_fd(-2147483648,fd);
	lseek(fd, 0, SEEK_SET);
	read(fd, buffer, 12);
	buffer[11] = '\0'; 
	if (!strcmp(buffer,"-2147483648"))
		success();
	else
		fail();
	lseek(fd, 0, SEEK_SET);
	ft_putnbr_fd(2147483647,fd);
	lseek(fd, 0, SEEK_SET);
	read(fd, buffer, 11);
	if (!strcmp(buffer,"2147483647"))
		success();
	else
		fail();
	close(fd);
	// テストファイルを削除
	remove("testfile.txt");
	printf("\n");
}

int	main(void)
{
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_itoa();
	test_strmapi();
	test_striteri();
	test_putchar_fd();
	test_putstr_fd();
	test_putendl_fd();
	test_putnbr_fd();
}
