#include "ft_printf.h"

int    ft_printf_hexlow(unsigned int n)
{
    int i;

    i = 0;
    char *str = "0123456789abcdef";

    if(n < 16)
    {
        i += ft_printf_char(str[n]);
    }
    else if(n >= 16)
    {
        i += ft_printf_hexlow(n / 16);
        i += ft_printf_char(str[n % 16]);
    }
    return(i);
}


