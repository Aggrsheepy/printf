#include "printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		k1;
	int		k2;
	char	*str;

	if (s1 && s2)
	{
		k1 = ft_strlen(s1);
		k2 = ft_strlen(s2);
		str = (char *)malloc(sizeof(char) * (k1 + k2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[k1] = s2[i];
			k1++;
		}
		str[k1] = '\0';
		return (str);
	}
	return (NULL);
}
