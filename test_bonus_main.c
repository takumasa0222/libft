/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 04:42:02 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/17 13:42:20 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	delete_test(void *s);
void	success()
{
	printf("OK ");
}

void	fail()
{
	printf("\x1b[31mNG \x1b[39m");
}
void	test_ft_lst_new()
{
	printf("ft_lst_new\n");
	char	*s = "Helloworld";
	t_list	*l, *l1;

	l = ft_lstnew(s);
	if (!strcmp(l->content, s) && l->next == NULL)
		success();
	else
		fail();
	free(l);
	l1 = ft_lstnew(NULL);
	if (l1->content == NULL && l1->next == NULL)
		success();
	else
		fail();
	free(l1);
	printf("\n");
}
void	test_ft_lstadd_front()
{
	printf("ft_lstadd_front\n");
	t_list	*l, *l1, *l2, *l3;
	char	*s = "Helloworld";
	int		is_success;

	is_success = 0;
	l = ft_lstnew(s);
	l1 = ft_lstnew(NULL);
	if (!l && !l1)
		return ;
	printf("l1 address: %p, l = %p\n", (void *)l1, (void *)l);

	printf("Before adding: l1->next = %p, l = %p\n", (void *)l1->next, (void *)l);
	ft_lstadd_front(&l, l1);
	printf("After adding: l1->next = %p, l = %p\n", (void *)l1->next, (void *)l);
	// && l1 ->content == NULL && l->next == NULL && !strcmp(l->content, "Helloworld")
	printf("l1 address: %p, l = %p\n", (void *)l1, (void *)l);
	if (l == l1 && !strcmp(l1->next->content, "Helloworld") && l1->next->next == NULL)
		success();
	else
		fail();
	ft_lstclear(&l1,delete_test);
	printf("\n");
}

void	delete_test(void *s)
{
	unsigned char	*t = s;
	t = NULL;
}

void	test_ft_lstsize()
{
	printf("ft_lstsize\n");
	t_list	*t1, *t2, *t3;

	t1 = ft_lstnew(NULL);
	t2 = ft_lstnew(NULL);
	t3 = ft_lstnew(NULL);

	if (ft_lstsize(t1) == 1)
		success();
	else
		fail();
	ft_lstadd_front(&t2,t1);
	ft_lstadd_front(&t2,t3);
	if (ft_lstsize(t2) == 3)
		success();
	else
		fail();

	ft_lstclear(&t2,delete_test);
	printf("\n");
}

void	test_ft_lstlast()
{
	printf("ft_lstlast\n");
	t_list	*t1, *t2, *t3;

	t1 = ft_lstnew(NULL);
	t2 = ft_lstnew(NULL);
	t3 = ft_lstnew(NULL);

	if (ft_lstlast(t1) == t1)
		success();
	else
		fail();
	ft_lstadd_front(&t2,t1);
	ft_lstadd_front(&t2,t3);
	if (ft_lstlast(t2) == t2->next->next)
		success();
	else
		fail();
	ft_lstclear(&t2,delete_test);
	printf("\n");
}

void	test_ft_lstadd_back()
{
	printf("ft_lstadd_back\n");
	t_list	*l, *l1, *l2, *l3;
	char	*s = "Helloworld";
	int		is_success;

	is_success = 0;
	l = ft_lstnew(s);
	l1 = ft_lstnew(NULL);
	if (!l && !l1)
		return ;

	ft_lstadd_back(&l, l1);
	if (l->next == l1&& !strcmp(l->content, "Helloworld") && l->next->next == NULL)
		success();
	else
		fail();
	ft_lstclear(&l,delete_test);
	printf("\n");
}

void	sample_toupper(void *t)
{
	char	*s = (char *)t;
	if (!s)
		return ;
	while (*s)
	{
		*s = toupper(*s);
		s++;
	}
}

void	*sample_toupper2(void *t)
{
	char	*s = (char *)t;
	int		i;
	char	*s1;

	i = 0;
	if (!s)
		return (NULL);
	s1 = ft_strdup(s);
	if (!s1)
		return (NULL);
	while (s1[i])
	{
		s1[i] = toupper(s1[i]);
		i++;
	}
	return (s1);
}

void	test_ft_lstiter()
{
	printf("ft_lstiter\n");
	t_list	*t1, *t2, *t3;
	char	s1[20] = "helloworld";
	char	s2[20] = "abc";

	t1 = ft_lstnew(s1);
	t2 = ft_lstnew(s2);
	t3 = ft_lstnew(NULL);

	ft_lstadd_back(&t1,t2);
	ft_lstadd_back(&t2,t3);
	ft_lstiter(t1, sample_toupper);
	if (!strcmp(t1->content, "HELLOWORLD")&&!strcmp(t1->next->content, "ABC")&& t1->next->next->content == NULL)
		success();
	else
		fail();
	ft_lstclear(&t1,delete_test);
	printf("\n");
}

void	test_ft_lstmap()
{
	printf("test_ft_lstmap\n");
	t_list	*t1, *t2, *t3, *t4 ;
	char	s1[20] = "helloworld";
	char	s2[20] = "abc";

	t1 = ft_lstnew(s1);
	t2 = ft_lstnew(s2);
	t3 = ft_lstnew(NULL);


	ft_lstadd_back(&t1,t2);
	ft_lstadd_back(&t2,t3);
	t4 = ft_lstmap(t1, sample_toupper2,delete_test);
	if (!t4)
	{
		printf("map cannot allocate memory");
		return;
	}
	if (!strcmp(t1->content, "helloworld")&&!strcmp(t1->next->content, "abc")&& t1->next->next->content == NULL)
	{
		if (!strcmp(t4->content, "HELLOWORLD") && !strcmp(t4->next->content, "ABC")&& t4->next->next->content == NULL)
			success();
		else
			fail();
	}
	else
		fail();
	ft_lstclear(&t1,delete_test);
	ft_lstclear(&t4,delete_test);
	printf("\n");
}

int	main(void)
{
	test_ft_lst_new();
	test_ft_lstadd_front();
	test_ft_lstsize();
	test_ft_lstlast();
	test_ft_lstadd_back();
	test_ft_lstiter();
	test_ft_lstmap();

}