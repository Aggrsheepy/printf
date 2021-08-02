/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_proc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edomino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:49:07 by edomino           #+#    #+#             */
/*   Updated: 2021/08/02 20:49:09 by edomino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_proc(t_struct *sohr, char c)
{
	for_char(sohr);
	if (sohr->flag_minus == TRUE)
	{
		sohr->napechat += write(1, &c, 1);
		while (sohr->zapol_wid > 0)
		{
			if (sohr->flag_zero == FALSE)
				sohr->napechat += write(1, " ", 1);
			else
				sohr->napechat += write(1, "0", 1);
			sohr->zapol_wid--;
		}
	}
	else
	{
		while (sohr->zapol_wid > 0)
		{
			if (sohr->flag_zero == 0)
				sohr->napechat += write(1, " ", 1);
			else
				sohr->napechat += write(1, "0", 1);
			sohr->zapol_wid--;
		}
		sohr->napechat += write(1, &c, 1);
	}
}
