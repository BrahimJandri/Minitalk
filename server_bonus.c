/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:56:50 by bjandri           #+#    #+#             */
/*   Updated: 2024/01/28 17:55:27 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	sig_handle(int signal, siginfo_t *info, void *context)
{
	static int	i;
	static char	n;
	int			nb;
	(void)context;

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
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction	sigact;

	sigact.sa_sigaction = &sig_handle;
	sigact.sa_flags = SA_SIGINFO;
	sigemptyset(&sigact.sa_mask);
	ft_printf("________________________________________________\n\n");
	ft_printf("  Welcome To Bjandri Minitalk Bonus Part 🧑🏻  \n");
	ft_printf("________________________________________________\n\n");
	ft_printf("  The Server PID is : %d\n", getpid());
	ft_printf("________________________________________________\n");
	while (1)
	{
		sigaction(SIGUSR1, &sigact, NULL);
		sigaction(SIGUSR2, &sigact, NULL);
		pause();
	}
}
