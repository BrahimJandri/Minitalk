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

// server.c

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

static int g_msg_i = 0;
static char g_msg_c = 0;

void bit_handler(int signum, siginfo_t *info, void *context) {
    (void)context;  // Unused parameter

    if (signum == SIGUSR1 || signum == SIGUSR2) {
        int bit = (signum == SIGUSR1) ? 1 : 0;

        char mask = 1 << g_msg_i;
        g_msg_c += (bit << g_msg_i);
        g_msg_i++;

        if (g_msg_i == 7) {
            printf("%c", g_msg_c);

            if (g_msg_c == '\0') {
                printf("\n");
                exit(0);  // Exit when null character is received
            }

            g_msg_c = 0;
            g_msg_i = 0;
        }
    }
}

int main(void) {
    printf("Welcome To Bjandri Server!\n");
    printf("My Server PID is: %d\n", getpid());

    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = bit_handler;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1) {
        sigaction(SIGUSR1, &sa, NULL);
    	sigaction(SIGUSR2, &sa, NULL);   // Introduce a small delay to allow processing
    }

    return 0;
}
