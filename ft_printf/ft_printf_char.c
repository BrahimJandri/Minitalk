#include "ft_printf.h"

int    ft_printf_char(int c)
{
    write(1, &c, 1);
    return(1);
}

