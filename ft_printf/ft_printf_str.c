#include "ft_printf.h"

int    ft_printf_str(char *str)
{
    int i;

    i = 0;
    if(!str)
        return(ft_printf_str("(null)"));
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return(i);
}

