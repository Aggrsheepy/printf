#include "printf.h"

size_t	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	if (s[0] == '\0')
		return 0;
	while (s[i])
		i++;
	return (i);
}
