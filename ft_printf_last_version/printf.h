/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edomino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:52:16 by edomino           #+#    #+#             */
/*   Updated: 2021/08/02 20:52:21 by edomino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "stdlib.h"
# include "unistd.h"
# include "stdarg.h"
# include "limits.h"
# include "stdio.h" // TODO delete this

# define TRUE 	1
# define FALSE 	0
# define OFF   (-1)
//# define FT_LIM			922337203685477580

typedef struct s_struct
{
	int				napechat;
	int				i;
	_Bool			flag_zero;
	_Bool			flag_minus;
	_Bool			minus;
	int				toch;
	int				width;
	int				zapol_wid;
	long			pointer;
	long			null_p;
	long			znach;
	int				zapol_p;
	unsigned char	c;
	char			*stroka;
}					t_struct;

int			ft_printf(const char *chetam, ...);

int			ft_strlen(const char *s);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
int			len(long n);
char		*ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*itoa_base_mod(unsigned long long value, unsigned long long base,
				char reg);

void		init_struct(t_struct *sohr);
void		null_struct(t_struct *sohr);

void		ft_print_str(t_struct *sohr, va_list args);
void		ft_print_int(t_struct *sohr, va_list args);
void		ft_print_char(t_struct *sohr, va_list args);
void		ft_print_p(t_struct *sohr, va_list args);
void		ft_print_hex(t_struct *sohr, va_list args, char ch);
void		ft_print_uint(t_struct *sohr, va_list args);
void		ft_print_proc(t_struct *sohr, char c);

int			ft_checkweight(const char *chetam, t_struct *sohr, va_list args);

void		check_toch(t_struct *sohr, const char *chetam, va_list args);
void		check_width(t_struct *sohr, const char *chetam, va_list args);
void		check_flags(t_struct *sohr, const char *chetam);
void		for_char(t_struct *sohr);
void		napechat_z_or_sp(t_struct *sohr);
void		for_pointer(t_struct *sohr, int len);
void		print_sprava(t_struct *sohr, char *str, int len);
void		print_sleva(t_struct *sohr, char *str, int len);
void		string_sprava(t_struct *sohr, char *str, int len);
void		string_sleva(t_struct *sohr, char *str, int len);

void		ft_obrab(t_struct *sohr, int len);

#endif
