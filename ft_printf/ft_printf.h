
# ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int ft_printf(const char *format, ...);
int    ft_printf_add(void *ptr);
int    ft_printf_hexlow(unsigned int n);
int    ft_printf_char(int c);
int    ft_printf_hexupp(unsigned int n);
int ft_printf_int(int n);
int    ft_printf_str(char *str);
int	ft_printf_unsigned(unsigned int n);


#endif