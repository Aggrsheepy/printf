#include "printf.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	simvol;

	ptr = (char *)s;
	simvol = (char)c;
	while (*ptr && !(*ptr == simvol))
		ptr++;
	if (*ptr == simvol)
		return (ptr);
	else
		return (NULL);
}
