/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:59:41 by mliew             #+#    #+#             */
/*   Updated: 2022/08/23 13:14:08 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	message(int sig)
{
	(void)sig;
	write (1, "Message received by server.", 27);
	exit (0);
}

void	client_handler(int pid, char *msg)
{
	int		bit_count;
	int		byte_count;
	char	c;

	byte_count = 0;
	while (byte_count <= ft_strlen(msg))
	{
		c = msg[byte_count];
		bit_count = 8;
		while (--bit_count >= 0)
		{
			usleep(30);
			if (c && ((c >> bit_count) & 1))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(30);
		}
		byte_count++;
	}
}

int	main(int ac, char **av)
{
	signal(SIGUSR1, message);
	if (ac != 3)
		ft_printf("Invalid! Please input: ./client [PID] [MESSAGE]");
	else
		client_handler(ft_atoi(av[1]), av[2]);
}
