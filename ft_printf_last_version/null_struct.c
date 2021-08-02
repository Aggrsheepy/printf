/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edomino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:50:57 by edomino           #+#    #+#             */
/*   Updated: 2021/08/02 20:51:00 by edomino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	null_struct(t_struct *sohr)
{
	sohr->flag_minus = FALSE;
	sohr->minus = FALSE;
	sohr->znach = 0;
	sohr->flag_zero = FALSE;
	sohr->width = 0;
	sohr->pointer = FALSE;
	sohr->null_p = FALSE;
	sohr->zapol_p = 0;
	sohr->zapol_wid = 0;
	sohr->toch = OFF;
	sohr->stroka = NULL;
}
