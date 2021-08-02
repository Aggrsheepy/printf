/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprava.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edomino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:51:19 by edomino           #+#    #+#             */
/*   Updated: 2021/08/02 20:51:55 by edomino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_sprava(t_struct *sohr, char *str, int len)
{
	if (sohr->minus == TRUE && sohr->flag_zero == TRUE)
		sohr->napechat += write(1, "-", 1);
	while (sohr->zapol_wid > 0)
	{
		if (sohr->flag_zero == FALSE)
			sohr->napechat += write(1, " ", 1);
		else
			sohr->napechat += write(1, "0", 1);
		sohr->zapol_wid--;
	}
	if (sohr->pointer == TRUE)
		sohr->napechat += write(1, "0x", 2);
	if (sohr->minus == TRUE && sohr->flag_zero == FALSE)
		sohr->napechat += write(1, "-", 1);
	while (sohr->zapol_p > 0)
	{
		sohr->napechat += write(1, "0", 1);
		sohr->zapol_p--;
	}
	while (len-- > 0 && sohr->null_p != TRUE)
	{
		sohr->napechat += write(1, str, 1);
		str++;
	}
}
