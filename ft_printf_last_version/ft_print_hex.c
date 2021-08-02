/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edomino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:48:28 by edomino           #+#    #+#             */
/*   Updated: 2021/08/02 20:48:35 by edomino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_hex(t_struct *sohr, va_list args, char ch)
{
	unsigned long long		pointer;
	size_t					len;

	pointer = (unsigned int)va_arg(args, unsigned int);
	sohr->stroka = itoa_base_mod(pointer, 16, ch);
	len = ft_strlen(sohr->stroka);
	if (pointer == 0 && sohr->toch >= 0)
		len = 0;
	ft_obrab(sohr, len);
	if (sohr->flag_minus == TRUE)
		print_sleva(sohr, sohr->stroka, len);
	else
		print_sprava(sohr, sohr->stroka, len);
	free(sohr->stroka);
}
