/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:01:36 by mliew             #+#    #+#             */
/*   Updated: 2022/08/02 18:22:56 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	server_handler(int sig, siginfo_t *info, void *context)
{
	static int		c;
	static int		bit_count;
	static pid_t	client_pid;

	(void)(context);
	if (client_pid != info->si_pid && client_pid != 0)
		client_pid = info->si_pid;
	else
	{
		if (sig == SIGUSR1)
			c += 1;
		if (bit_count == 7)
		{
			write(1, &c, 1);
			bit_count = -1;
			c = 0;
		}
		c <<= 1;
		bit_count++;
	}
}

int	main(void)
{
	struct sigaction	sa;
	
	sa.sa_sigaction = server_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("Server PID: %d\n", getpid());
	while (1)
		pause();
}
