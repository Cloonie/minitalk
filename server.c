/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:01:36 by mliew             #+#    #+#             */
/*   Updated: 2022/08/02 17:09:11 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	server_handler(int sig)
{
	static int	c;
	static int	bit_count;

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

int	main(void)
{
	int	server_pid;

	server_pid = getpid();
	signal(SIGUSR1, server_handler);
	signal(SIGUSR2, server_handler);
	printf("Server PID: %d\n", server_pid);
	while (1)
		sleep(1);
}
