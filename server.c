/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:58:32 by bjandri           #+#    #+#             */
/*   Updated: 2024/01/23 16:10:37 by bjandri          ###   ########.fr       */
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
	struct sigaction	sigact;

	sigact.sa_handler = &sig_handle;
	sigact.sa_flags = SA_RESTART;
	printf("The Server PID is : %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sigact, 0);
		sigaction(SIGUSR2, &sigact, 0);
	}
	return (0);
}
