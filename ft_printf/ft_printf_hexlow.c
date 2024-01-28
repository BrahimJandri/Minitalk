/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexlow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:04:26 by bjandri           #+#    #+#             */
/*   Updated: 2024/01/28 18:04:27 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hexlow(unsigned int n)
{
	int		i;
	char	*str;

	i = 0;
	str = "0123456789abcdef";
	if (n < 16)
	{
		i += ft_printf_char(str[n]);
	}
	else if (n >= 16)
	{
		i += ft_printf_hexlow(n / 16);
		i += ft_printf_char(str[n % 16]);
	}
	return (i);
}
