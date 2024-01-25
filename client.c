/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:59:00 by bjandri           #+#    #+#             */
/*   Updated: 2024/01/23 16:10:44 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// client.c

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void	send_bit(int pid, char *str, size_t len)
{
    int shift;
    size_t i;

    i = 0;
    while (i < len)
    {
        shift = 0;
        while (shift < 7)
        {
            if((str[i] >> shift) & 1)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            shift++;
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
		pid = atoi(av[1]);
		str = av[2];
		send_bit(pid, str, strlen(str));
	}
	else
		printf("\nNUMBER OF ARGUMMENT IS WRONG !!\n\n");
}