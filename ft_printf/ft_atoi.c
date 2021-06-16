#include "printf.h"

int	ft_atoi(const char *str)
{
	unsigned int	nom;
	int				i;

	i = 0;
	nom = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nom = nom * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(nom));
}
