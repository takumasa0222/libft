/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:55:18 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/04/23 22:45:11 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s_len;
	size_t	st_len;
	size_t	d_len;
	char	*ret;
	size_t	rem_size;

	if (!s1 || !set)
		return (NULL);
	s_len = ft_strlen(s1);
	st_len = ft_strlen(set);
	d_len = s_len - st_len;
	rem_size = 0;
	if (!ft_strncmp(s1, set, st_len) || !ft_strncmp((s1 + d_len), set, st_len))
		rem_size = st_len;
	if (!ft_strncmp(s1, set, st_len) && !ft_strncmp((s1 + d_len), set, st_len))
		rem_size = st_len * 2;
	ret = malloc((s_len - rem_size + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (*s1)
}
