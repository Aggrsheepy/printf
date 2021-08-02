/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_weight.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edomino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:46:25 by edomino           #+#    #+#             */
/*   Updated: 2021/08/02 20:46:29 by edomino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	check_flags(t_struct *sohr, const char *chetam)
{
	while (chetam[sohr->i] == '-' || chetam[sohr->i] == '0')
	{
		if (chetam[sohr->i] == '0')
			sohr->flag_zero = TRUE;
		else if (chetam[sohr->i] == '-')
			sohr->flag_minus = TRUE;
		sohr->i++;
	}
}

void	check_width(t_struct *sohr, const char *chetam, va_list args)
{
	if (chetam[sohr->i] == '*')
	{
		sohr->width = (int)va_arg(args, int);
		if (sohr->width < 0)
		{
			sohr->flag_minus = TRUE;
			sohr->flag_zero = FALSE;
			sohr->width *= -1;
		}
		if (chetam[sohr->i + 1] == '.')
			sohr->i++;
		if (ft_strchr("cspdiuxX%", chetam[sohr->i + 1]))
			sohr->i++;
	}
	else if (chetam[sohr->i] >= '0' && chetam[sohr->i] <= '9')
	{
		sohr->width = ft_atoi(&chetam[sohr->i]);
		while (chetam[sohr->i] >= '0' && chetam[sohr->i] <= '9')
			sohr->i++;
	}
}

void	check_toch(t_struct *sohr, const char *chetam, va_list args)
{
	if (chetam[sohr->i] == '.')
	{
		sohr->toch = 0;
		sohr->i++;
		if (chetam[sohr->i] >= '0' && chetam[sohr->i] <= '9')
		{
			sohr->toch = ft_atoi(&chetam[sohr->i]);
			while (chetam[sohr->i] >= '0' && chetam[sohr->i] <= '9')
				sohr->i++;
		}
		else if (chetam[sohr->i] == '*')
		{
			sohr->toch = (int) va_arg(args, int);
			if (sohr->toch < 0)
			{
				sohr->toch = OFF;
				sohr->flag_zero = TRUE;
			}
			sohr->i++;
		}
		else
			sohr->toch = FALSE;
	}
}

void	check(const char *chetam, t_struct *sohr, va_list args)
{
	null_struct(sohr);
	check_flags(sohr, chetam);
	check_width(sohr, chetam, args);
	check_toch(sohr, chetam, args);
}

int	ft_checkweight(const char *chetam, t_struct *sohr, va_list args)
{
	check(chetam, sohr, args);
	if (!(ft_strchr("cspdiuxX%", chetam[sohr->i])))
		return (1);
	if (chetam[sohr->i] == 'd' || chetam[sohr->i] == 'i')
		ft_print_int(sohr, args);
	else if (chetam[sohr->i] == 'c')
		ft_print_char(sohr, args);
	else if (chetam[sohr->i] == 's')
		ft_print_str(sohr, args);
	else if (chetam[sohr->i] == 'p')
		ft_print_p(sohr, args);
	else if (chetam[sohr->i] == 'u')
		ft_print_uint(sohr, args);
	else if (chetam[sohr->i] == 'x')
		ft_print_hex(sohr, args, 'a');
	else if (chetam[sohr->i] == 'X')
		ft_print_hex(sohr, args, 'A');
	else if (chetam[sohr->i] == '%')
		ft_print_proc(sohr, '%');
	else
		return (0);
	sohr->i++;
	return (0);
}
