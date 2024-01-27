#include "ft_printf.h"

int ft_printf_hexupp(unsigned int n)
{
    int i;

    i = 0;
    char *str = "0123456789ABCDEF";

    if (n < 16)
    {
        i += ft_printf_char(str[n]);
    }
    else if (n >= 16)
    {
        i += ft_printf_hexupp(n / 16);
        i += ft_printf_char(str[n % 16]);
    }
    return i;
}
