/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:10:00 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/04/22 23:06:50 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	minus_flag;
	int	result;

	minus_flag = 1;
	result = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' \
	|| *str == '\f' || *str == '\r' || *str == ' ')
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus_flag = -1;
		str++;
	}
	while (ft_isdigit(*str) && *str)
	{
		result = result * 10;
		result = result + (*str - 48);
		str++;
	}
	return (minus_flag * result);
}
