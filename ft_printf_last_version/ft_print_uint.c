/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edomino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:49:27 by edomino           #+#    #+#             */
/*   Updated: 2021/08/02 20:49:29 by edomino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_uint(t_struct *sohr, va_list args)
{
	size_t				len;
	unsigned int		value;

	value = (unsigned int)va_arg(args, unsigned int);
	sohr->stroka = itoa_base_mod(value, 10, 'a');
	len = ft_strlen(sohr->stroka);
	if (value == 0 && sohr->toch >= 0)
		len = 0;
	ft_obrab(sohr, len);
	if (sohr->flag_minus == TRUE)
		print_sleva(sohr, sohr->stroka, len);
	else
		print_sprava(sohr, sohr->stroka, len);
	free(sohr->stroka);
}
