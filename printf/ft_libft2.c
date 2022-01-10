#include "ft_printf.h"
char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (s1[len] != '\0')
		len++;
	ptr = (char *)malloc(len + 1);
	len = len - 1;
	while (len >= 0)
	{
		ptr[i] = s1[i];
		i++;
		len--;
	}
	ptr[i] = '\0';
	return (ptr);
}
int	ft_is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}