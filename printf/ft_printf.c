#include "ft_printf.h"

int ft_dot(const char *str, int i, t_flags *flags, va_list args)//.정밀도를 나타냄
{
	int d;

	d = i + 1;
	if (str[d] == '*')
	{
		flags->dot = va_arg(args, int);
		d++;
	}
	else
	{
		flags->dot = 0;
		while (ft_is_digit(str[d]))
		{
			flags->dot = flags->dot * 10 + (str[d] - '0');
			d++;
		}
	}
	return (d);
}

int	ft_is_type(int a)
{
	if (a == 'c')
		return ('c');
	if (a == 's')
		return ('s');
	if (a == 'p')
		return ('p');
	if (a == 'd')
		return ('d');
	if (a == 'u')
		return ('u');
	if (a == 'x')
		return ('x');
	if (a == 'X')
		return ('X');
	if (a == '%')
		return ('%');
	if (a == 'i')
		return ('i');
	return (0);
}

int ft_is_flaglist(int a)
{
	if (a == '-')
		return ('-');
	if (a == ' ')
		return (' ');
	if (a == '0')
		return ('0');
	if (a == '.')
		return ('.');
	if (a == '*')
		return ('*');
	return (0);
}

int	ft_process(const char *str, va_list args)
{
	int	i;
	t_flags flags;
	int count;
	
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		flags = ft_zero_flags();
		if (!str[i])
			break;
		else if (str[i] == '%' && str[i + 1] != '\0')
		{
			i = ft_flag_p(str, ++i, &flags, args);
			if (ft_is_type(str[i]))//d,c등의 타입인지 확인부분
				count += ft_treat((char)flags.type, flags, args);
			else if(str[i])
				count += ft_putchar2(str[i]);	
		}
		else if (str[i] != '%')
			count += ft_putchar2(str[i]);
		i++;
	}
	return (count);
}
int	ft_printf(const char *fmt, ...)
{
	const char *str;
	va_list		args;
	int			count;

	str = ft_strdup(fmt);
	count = 0;
	va_start(args, fmt);
	count += ft_process(str, args);
	va_end(args);
	free((char *)str);
	return (count);
}
