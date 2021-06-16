#include "printf.h"

static void	ft_free(t_struct *sohr)
{
	free(sohr->stroka_new);
	free(sohr->stroka_new_with_width);
	free(sohr->stroka_joined);
}

char *create_str(t_struct *sohr)
{
	char	 *str_width;
	char 	zap;
	int		i;

	i = 0;
	if (sohr->flag_zero == TRUE)
		zap = '0';
	else
		zap = ' ';
	str_width = (char *)malloc(sohr->zapol_wid + 1);
	if (!str_width)
		return (NULL);
	while (i < sohr->zapol_wid)
	{
		str_width[i] = zap;
		i++;
	}
	str_width[i] = '\0';
	return (str_width);
}

void 	ft_print_int(t_struct *sohr, va_list args)
{
	size_t	len;

	sohr->i++;
	sohr->stroka = (int*)va_arg(args, int* );
	if (sohr->stroka == NULL)
		sohr->stroka = "(null)";
	if (sohr->toch == FALSE)
		sohr->stroka = "";
	if (sohr->stroka < 0)
	{
//		sohr->stroka = - 1  sohr->stroka;
	}
	len = ft_strlen(sohr->stroka);
	if (sohr->toch > 0 && len > sohr->toch)
		len = sohr->toch;
	if (sohr->width > 0 && sohr->width > len)
		sohr->zapol_wid = sohr->width - len;
	sohr->stroka_new = ft_substr(sohr->stroka, 0, len);
	sohr->stroka_new_with_width = create_str(sohr);
	if (sohr->flag_minus == TRUE)
		sohr->stroka_joined = ft_strjoin(sohr->stroka_new, sohr->stroka_new_with_width);
	else
		sohr->stroka_joined = ft_strjoin(sohr->stroka_new_with_width, sohr->stroka_new); //pechat sprava
	sohr->napechat += write(1, sohr->stroka_joined, ft_strlen(sohr->stroka_joined));
	ft_free(sohr);
}

