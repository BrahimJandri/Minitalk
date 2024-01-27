#include "ft_printf.h"

int	ft_printf_unsigned(unsigned int n)
{
	int i;

	i = 0;
	if (n <= 9)
	{
		i += ft_printf_char(n + '0');
	}
	else {
		i += ft_printf_int(n / 10);
		i += ft_printf_char(n % 10 + '0');
	}
	return(i);
}
