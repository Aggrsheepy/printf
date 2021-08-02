/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edomino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:49:17 by edomino           #+#    #+#             */
/*   Updated: 2021/08/02 20:49:19 by edomino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	string_sleva(t_struct *sohr, char *str, int len)
{
	while (sohr->zapol_wid > 0)
	{
		sohr->napechat += write(1, " ", 1);
		sohr->zapol_wid--;
	}
	while (len > 0)
	{
		sohr->napechat += write(1, str, 1);
		str++;
		len--;
	}
}

void	string_sprava(t_struct *sohr, char *str, int len)
{
	while (len > 0)
	{
		sohr->napechat += write(1, str, 1);
		str++;
		len--;
	}
	while (sohr->zapol_wid > 0)
	{
		sohr->napechat += write(1, " ", 1);
		sohr->zapol_wid--;
	}
}

void	ft_print_str(t_struct *sohr, va_list args)
{
	int		len;

	sohr->stroka = (char *)va_arg(args, char *);
	if (sohr->stroka == NULL)
		sohr->stroka = "(null)";
	len = ft_strlen(sohr->stroka);
	if (sohr->toch >= 0)
	{
		if (sohr->toch < len)
			len = sohr->toch;
		else
			len = len;
	}
	sohr->zapol_wid = sohr->width - len;
	if (sohr->flag_minus == TRUE)
		string_sprava(sohr, sohr->stroka, len);
	else
		string_sleva(sohr, sohr->stroka, len);
}
