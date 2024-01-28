/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:55:52 by bjandri           #+#    #+#             */
/*   Updated: 2024/01/28 18:00:01 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *str)
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

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	ft_send_bit(int pid, char *str, size_t len)
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

static void	ft_client_handler(int signum)
{
	if (signum == SIGUSR2)
	{
		ft_printf("Received a signal\n");
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;

	if (ac == 3)
	{
		signal(SIGUSR2, ft_client_handler);
		pid = ft_atoi(av[1]);
		str = av[2];
		ft_send_bit(pid, str, ft_strlen(str));
	}
	else
	{
		ft_printf("invalid args");
	}
	return (0);
}
