#include "ft_printf.h"

int main()
{
    	int		e = -2147483648;
        int		j = -12;
    // ft_printf("%s","hello");
    // ft_printf("%d",ft_printf("%s","hello"));
    // printf("%0*d", -7, -54);
    // printf("%09s", "hi low");
    // ft_printf("%5.p\n",NULL);
    // printf("%d\n",printf("%0d",e));
    // ft_printf("%d",ft_printf("%0d",j));
    // ft_printf("%0d",e);
    printf("p:%0*.*d\n",1,-2,j);
    ft_printf("%0*.*d",1,-2,j);
    // ft_printf("%d",ft_printf("%0d",e));
    // printf("%2.p",NULL);
    // printf("%-07d", -54);
    // ft_printf("%-07i", -54);
}