/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edomino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:45:53 by edomino           #+#    #+#             */
/*   Updated: 2021/08/02 20:46:09 by edomino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_atoi(const char *str)
{
	unsigned int	nom;
	int				i;
	int				k;

	k = 1;
	i = 0;
	nom = 0;
	while (*str == ' ' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == '\n')
		str++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			k = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nom = nom * 10 + (str[i] - '0');
		i++;
	}
	if (nom > 2147483647 && k == 1)
		return (-1);
	if (nom > 2147483648 && k == -1)
		return (0);
	return ((int)(k * nom));
}
