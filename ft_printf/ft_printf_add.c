/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:02:58 by bjandri           #+#    #+#             */
/*   Updated: 2024/01/28 18:03:13 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex(unsigned long int n)
{
	int		i;
	char	*str;

	i = 0;
	str = "0123456789abcdef";
	if (n <= 15)
	{
		i += ft_printf_char(str[n]);
	}
	else if (n >= 16)
	{
		i += hex(n / 16);
		i += ft_printf_char(str[n % 16]);
	}
	return (i);
}

int	ft_printf_add(void *ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (ft_printf_str("(nil)"));
	i += ft_printf_str("0x");
	i += hex((unsigned long int)ptr);
	return (i);
}
