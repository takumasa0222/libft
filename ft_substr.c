/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:08:04 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/17 17:18:22 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;
	unsigned int	j;
	size_t			size;

	if (!s || len > SIZE_MAX)
		return (NULL);
	size = ft_strlen(s);
	if (size < len)
		len = size;
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (i != start && i < (unsigned int)ft_strlen(s))
		i++;
	while (j < len && s[i])
	{
		ret[j] = s[i];
		j++;
		i++;
	}
	ret[j] = '\0';
	return (ret);
}

// int	main(void)
// {
// 	char * str = strdup("1");
// 	char *s = ft_substr(str, 42, 42000000);
// }
