/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:58:32 by bjandri           #+#    #+#             */
/*   Updated: 2024/01/29 13:22:02 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handle(int signal)
{
	static int	i;
	static char	n;
	int			nb;

	if (signal == SIGUSR1)
		nb = 1;
	else
		nb = 0;
	n = (n << 1) + nb;
	i++;
	if (i == 8)
	{
		write(1, &n, 1);
		i = 0;
		n = 0;
	}
}

int	main(void)
{
	ft_printf("________________________________________________\n\n");
	ft_printf("  Welcome To Bjandri Minitalk Mandatory Part 🖥️\n");
	ft_printf("________________________________________________\n\n");
	ft_printf("  The Server PID is : %d\n", getpid());
	ft_printf("________________________________________________\n");
	while (1)
	{
		signal(SIGUSR1, &sig_handle);
		signal(SIGUSR2, &sig_handle);
	}
	return (0);
}
