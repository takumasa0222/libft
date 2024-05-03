/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:55:18 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/03 12:40:20 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s_len;
	size_t	st_len;
	size_t	d_len;
	char	*ret;

	if (!s1 || !set)
		return (NULL);
	s_len = ft_strlen(s1);
	st_len = ft_strlen(set);
	d_len = s_len - st_len;
	if (!ft_strncmp(s1, set, st_len) && !ft_strncmp((s1 + d_len), set, st_len))
		ret = ft_substr(s1, st_len, (d_len - st_len));
	else if (!ft_strncmp(s1, set, st_len))
		ret = ft_substr(s1, st_len, d_len);
	else if (!ft_strncmp((s1 + d_len), set, st_len))
		ret = ft_substr(s1, 0, d_len);
	else
	{
		ret = malloc((s_len + 1) * sizeof(char));
		if (!ret)
			return (NULL);
		ft_strlcpy(ret, s1, s_len);
	}
	return (ret);
}
