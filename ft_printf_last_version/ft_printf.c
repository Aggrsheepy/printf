/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edomino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:49:44 by edomino           #+#    #+#             */
/*   Updated: 2021/08/02 20:49:47 by edomino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *chetam, ...)
{
	va_list			args;
	t_struct		sohr;

	init_struct(&sohr);
	if (!chetam || (chetam[0] == '%' && ft_strlen(chetam) == 1))
		return (0);
	va_start(args, chetam);
	while (chetam[sohr.i])
	{
		if (chetam[sohr.i] != '%')
			sohr.napechat += write(1, &chetam[sohr.i++], 1);
		else
		{
			sohr.i++;
			if (ft_checkweight(chetam, &sohr, args) == 1)
				break ;
		}
	}
	va_end(args);
	return (sohr.napechat);
}
