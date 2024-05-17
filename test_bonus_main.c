/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 04:42:02 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/17 11:24:20 by tamatsuu         ###   ########.fr       */
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

int	main(void)
{
	test_ft_lst_new();
	test_ft_lstadd_front();
}