/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:01:36 by mliew             #+#    #+#             */
/*   Updated: 2022/08/05 12:34:37 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	server_handler(int sig)
{
	static int	c;
	static int	bit_count;

	if (sig == SIGUSR1)
		c += 1;
	if (++bit_count == 8)
	{
		write(1, &c, 1);
		c = 0;
		bit_count = 0;
	}
	c <<= 1;
}

int	main(void)
{
	signal(SIGUSR1, server_handler);
	signal(SIGUSR2, server_handler);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
}
