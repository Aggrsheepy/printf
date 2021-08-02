/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_mod.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edomino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:46:52 by edomino           #+#    #+#             */
/*   Updated: 2021/08/02 20:46:57 by edomino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*itoa_base_mod(unsigned long long value, unsigned long long base,
					   char reg)
{
	unsigned long long		tmp;
	size_t					len;
	char					*stroka;

	len = 1;
	tmp = value;
	while ((tmp /= base) >= 1)
		len++;
	stroka = (char *)malloc(sizeof(char) * (len + 1));
	if (!stroka)
		return (NULL);
	stroka[len] = '\0';
	while (len--)
	{
		if ((value % base) < 10)
			stroka[len] = ((value % base) + '0');
		else
			stroka[len] = ((value % base) + reg - 10);
		value /= base;
	}
	return (stroka);
}
