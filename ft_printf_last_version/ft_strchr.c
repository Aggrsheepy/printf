/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edomino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:50:08 by edomino           #+#    #+#             */
/*   Updated: 2021/08/02 20:50:14 by edomino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	simvol;

	ptr = (char *)s;
	simvol = (char)c;
	while (*ptr && !(*ptr == simvol))
		ptr++;
	if (*ptr == simvol)
		return (ptr);
	else
		return (NULL);
}
