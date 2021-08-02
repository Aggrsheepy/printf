/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edomino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:48:12 by edomino           #+#    #+#             */
/*   Updated: 2021/08/02 20:48:20 by edomino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	for_char(t_struct *sohr)
{
	sohr->zapol_wid = sohr->width - 1;
	if (sohr->flag_minus != FALSE)
		sohr->flag_zero = FALSE;
}

void	napechat_z_or_sp(t_struct *sohr)
{
	while (sohr->zapol_wid > 0)
	{
		if (sohr->flag_zero == FALSE)
			sohr->napechat += write(1, " ", 1);
		else
			sohr->napechat += write(1, "0", 1);
		sohr->zapol_wid--;
	}
}

void	ft_print_char(t_struct *sohr, va_list args)
{
	sohr->c = (unsigned char)va_arg(args, int);
	for_char(sohr);
	if (sohr->flag_minus == TRUE)
	{
		sohr->napechat += write(1, &sohr->c, 1);
		napechat_z_or_sp(sohr);
	}
	else
	{
		while (sohr->zapol_wid > 0)
		{
			if (sohr->flag_zero == FALSE)
				sohr->napechat += write(1, " ", 1);
			else
				sohr->napechat += write(1, "0", 1);
			sohr->zapol_wid--;
		}
		sohr->napechat += write(1, &sohr->c, 1);
	}
}
