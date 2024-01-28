/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:59:00 by bjandri           #+#    #+#             */
/*   Updated: 2024/01/28 15:50:56 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	resu;
	char	*s;

	sign = 1;
	resu = 0;
	s = (char *)str;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		resu = resu * 10 + *s - '0';
		s++;
	}
	return (resu * sign);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_send_bit(int pid, char *str, size_t len)
{
	size_t	i;
	int		shift;

	i = 0;
	while (i <= len)
	{
		shift = 7;
		while (shift >= 0)
		{
			if ((str[i] >> shift) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			shift--;
			usleep(300);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		str = av[2];
		if (!pid)
		{
			ft_printf("%s is an invalid pid ❌\n", av[1]);
			exit(EXIT_FAILURE);
		}
		ft_send_bit(pid, str, ft_strlen(str));
	}
	else
		ft_printf("Usage : ./client [Server_PID] Strint_to_send ✅");
	return (0);
}
