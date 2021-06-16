#include <printf.h>

void	check_flags(t_struct *sohr, const char *chetam)
{
	if (chetam[sohr->i] == '0') {
		sohr->flag_zero = TRUE;
		sohr->i++;
	}
	else if (chetam[sohr->i] == '-') {
		sohr->flag_minus = TRUE;
		sohr->i++;
	}
}

void	check_width(t_struct *sohr, const char *chetam, va_list args)
{
	if (chetam[sohr->i] == '*')
	{
		sohr->width = (int)va_arg(args, int);
		if (sohr->width < 0) {
			sohr->flag_minus = TRUE; // нулями слева
			sohr->flag_zero = FALSE; // свободное пространство заполнится нулями, если положительное width окажется ->
			// -> больше к-ва символов подаваемой строки, тк ->
			// -> к-во выведенных символов не может быть меньше заданного положительного width йопта
			sohr->width *= -1; // нулями слева
		}
		sohr->i++;
	}
	else if (chetam[sohr->i] >= '0' && chetam[sohr->i] <= '9') {
		sohr->width = ft_atoi(&chetam[sohr->i]);
		while (chetam[sohr->i] >= '0' && chetam[sohr->i] <= '9')
			sohr->i++;
	}
}

void	check_toch(t_struct *sohr, const char *chetam, va_list args) {
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
			sohr->i++;
			sohr->toch = (int) va_arg(args, int);
			if (chetam[sohr->toch] < 0)
			{
				sohr->toch = OFF;
			} //точность игнорируется, тк отрицат
		}
	}
}
int ft_checkweight(const char *chetam, t_struct *sohr, va_list args)
{
	check_flags(sohr, chetam);
	check_width(sohr, chetam, args);
	check_toch(sohr, chetam, args);


//	1. check flags (0 -) если оба, то 0 игнор-ся + если типа %0.4d то 0 иг-ся
//	2. check width (0-9 *)
//	3. check prec (. 0-9 *)
//	4. check CONVERSIONS (cspdiuxX%)

	if (!(ft_strchr("cspdiuxX%", chetam[sohr->i])))
		return(1);
	if ( chetam[sohr->i] == 'd' || chetam[sohr->i] == 'i') //точность опр мин кво сим. если < 0, то доплняется нулями слева, и не усек если > 0
		ft_print_int(sohr, args);
//	else if (chetam[sohr->i] == 'c') точ не прим
//		то_шо_принтует_сивм(sohr, args);
	if (chetam[sohr->i] == 's') // точ опр мах кво выводимых символов, ес > то усек
		ft_print_str(sohr, args);
//	else if (chetam[sohr->i] == 'p')
//		то_шо_принтует_поинтер(sohr, args);
//	else if (chetam[sohr->i] == 'u') точность опр мин кво сим. если < 0, то доплняется нулями слева, и не усек если > 0
//		то_шо_принтует_юинт(sohr, args);
//	else if (chetam[sohr->i] == 'x') точность опр мин кво сим. если < 0, то доплняется нулями слева, и не усек если > 0
//		то_шо_принтует_16ричное(sohr, args, 'a');
//	else if (chetam[sohr->i] == 'X') точность опр мин кво сим. если < 0, то доплняется нулями слева, и не усек если > 0
//		то_шо_принтует_16ричное(sohr, args, 'A');
//	else if (chetam[sohr->i] == '%')
//		то_шо_принтует_проц(sohr, '%');
//	else
//		return (0);
//	sohr->i++;
	return (0);
}

void	init_struct(t_struct *sohr)
{
	sohr->i 					= 0;
	sohr->napechat 				= 0;
	sohr->flag_minus 			= FALSE;
	sohr->flag_zero 			= FALSE;
	sohr->width					= 0;
	sohr->zapol_wid				= 0;
	sohr->toch					= OFF;
	sohr->stroka				= NULL;
	sohr->stroka_new			= NULL;
	sohr->stroka_new_with_width	= NULL;
	sohr->stroka_joined			= NULL;
}

int ft_printf(const char *chetam, ...)
{
	va_list			args;
	t_struct		sohr;

	init_struct(&sohr);
	if (!chetam || (chetam[0] == '%' && ft_strlen(chetam) == 1))
		return (0);
	va_start(args, chetam);

	while (chetam[sohr.i])
	{
		if (chetam[sohr.i] != '%')
			sohr.napechat += write(1, &chetam[sohr.i++], 1);
		else
		{
			sohr.i++;
			if (ft_checkweight(chetam, &sohr, args) == 1)
				break;
		}
	}
	va_end(args);
	return (sohr.napechat);
}

int main()
{
	size_t res;
	printf("Original |%-5.8s|\n", "huilo");

	res = ft_printf("Fake     |%-5.8s|", "huilo");
	return 0;
}
