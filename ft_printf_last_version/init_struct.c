/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edomino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:50:45 by edomino           #+#    #+#             */
/*   Updated: 2021/08/02 20:50:49 by edomino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	init_struct(t_struct *sohr)
{
	sohr->i = 0;
	sohr->napechat = 0;
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
