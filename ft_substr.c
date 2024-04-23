/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:08:04 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/04/23 20:48:17 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	size_t			src_len;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (i != start && i < (unsigned int)ft_strlen(s))
		i++;
	while (j < len)
	{
		ret[j] = s[i];
		j++;
	}
	ret[j] = '\0';
	return (ret);
}
