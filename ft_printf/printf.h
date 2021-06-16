#ifndef PRINTF_H
# define PRINTF_H

#include "stdlib.h"
#include "unistd.h"
#include "stdarg.h"

#include "stdio.h" // TODO delete this

# define TRUE 	1
# define FALSE 	0
# define OFF   (-1)

typedef struct	s_struct
{
		size_t 		napechat;
		size_t 		i;
		_Bool 		flag_zero;
		_Bool 		flag_minus;
		long		toch;
		long		width;
		long	    zapol_wid;

		char 		*stroka;
		char 		*stroka_new;
		char 		*stroka_new_with_width;
		char 		*stroka_joined;
}					t_struct;

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

void 	ft_print_str(t_struct *sohr, va_list args);
void 	ft_print_int(t_struct *sohr, va_list args);
#endif