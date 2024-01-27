#include "ft_printf.h"

int	ft_printf_int(int n)
{
	long	nb;
	int i;

	nb = n;
	i = 0;
	if (nb < 0)
	{
		i += ft_printf_char('-');
		nb *= -1;
	}
	if (nb <= 9)
	{
		i += ft_printf_char(nb + '0');
	}
	else
	{
	i += ft_printf_int(nb / 10);
	i += ft_printf_char(nb % 10 + '0');
	}
	return(i);
}
