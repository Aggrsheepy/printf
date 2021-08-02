/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edomino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:48:43 by edomino           #+#    #+#             */
/*   Updated: 2021/08/02 20:48:47 by edomino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_int(t_struct *sohr, va_list args)
{
	int		len;

	len = 0;
	sohr->znach = (int)va_arg(args, int);
	if (sohr->znach < 0)
	{
		sohr->znach = -sohr->znach;
		sohr->minus = TRUE;
	}
	sohr->stroka = itoa_base_mod(sohr->znach, 10, 'a');
	len = ft_strlen(sohr->stroka);
	if (sohr->znach == 0 && sohr->toch >= 0)
		len = 0;
	ft_obrab(sohr, len);
	if (sohr->flag_minus == 1)
		print_sleva(sohr, sohr->stroka, len);
	else
		print_sprava(sohr, sohr->stroka, len);
	free(sohr->stroka);
}
