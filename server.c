/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:01:36 by mliew             #+#    #+#             */
/*   Updated: 2022/08/08 14:20:12 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	server_handler(int sig, siginfo_t *info, void *context)
{
	static int	c;
	static int	bit_count;
	static int	client_pid;

	(void)context;
	client_pid = info->si_pid;
	if (sig == SIGUSR1)
		c += 1;
	if (++bit_count == 8)
	{
		bit_count = 0;
		if (!c)
			kill(client_pid, SIGUSR1);
		write(1, &c, 1);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = server_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
}
