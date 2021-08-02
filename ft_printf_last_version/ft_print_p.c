/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edomino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:48:53 by edomino           #+#    #+#             */
/*   Updated: 2021/08/02 20:48:56 by edomino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	for_pointer(t_struct *sohr, int len)
{
	if (sohr->flag_minus > 0)
		sohr->flag_zero = FALSE;
	if (sohr->toch > len)
		sohr->zapol_p = sohr->toch - len;
	if (sohr->width >= len + sohr->zapol_p)
		sohr->zapol_wid = sohr->width - len - 2;
}

void	ft_print_p(t_struct *sohr, va_list args)
{
	int					len;
	unsigned long long	pointer;

	sohr->pointer = TRUE;
	pointer = (unsigned long long)va_arg(args, void *);
	sohr->stroka = itoa_base_mod(pointer, 16, 'a');
	len = ft_strlen(sohr->stroka);
	if ((pointer == 0) && (sohr->toch >= 0))
	{
		sohr->null_p = TRUE;
		len--;
	}
	for_pointer(sohr, len);
	if (sohr->flag_minus == TRUE)
		print_sleva(sohr, sohr->stroka, len);
	else
		print_sprava(sohr, sohr->stroka, len);
	free(sohr->stroka);
}
