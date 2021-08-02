/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obrab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edomino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:47:41 by edomino           #+#    #+#             */
/*   Updated: 2021/08/02 20:47:49 by edomino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_obrab(t_struct *sohr, int len)
{
	if (sohr->toch >= 0)
		sohr->flag_zero = FALSE;
	if (sohr->flag_minus > 0)
		sohr->flag_zero = FALSE;
	if (sohr->toch > len)
		sohr->zapol_p = sohr->toch - len;
	if (sohr->width != 0)
	{
		if (sohr->minus == TRUE)
			sohr->zapol_wid = sohr->width - sohr->zapol_p - len - 1;
		else
			sohr->zapol_wid = sohr->width - sohr->zapol_p - len;
	}
}
