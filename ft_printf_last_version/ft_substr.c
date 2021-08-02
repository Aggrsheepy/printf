/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edomino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:50:33 by edomino           #+#    #+#             */
/*   Updated: 2021/08/02 20:50:36 by edomino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	k;
	char	*res;

	if (!s)
		return (NULL);
	res = (char *)malloc(sizeof(*s) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		if (i >= start && k < len)
		{
			res[k] = s[i];
			k++;
		}
		i++;
	}
	res[k] = 0;
	return (res);
}
