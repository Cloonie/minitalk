/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:59:41 by mliew             #+#    #+#             */
/*   Updated: 2022/08/02 18:27:08 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	message(int sig)
{
	if (sig == SIGUSR1)
		printf("Message Sent");
}

void	client_handler(int pid, char *msg)
{
	int		bit_count;
	int		byte_count;
	char	c;

	byte_count = 0;
	while (msg[byte_count])
	{
		c = msg[byte_count];
		bit_count = 7;
		while (bit_count >= 0)
		{
			if (c && ((c >> bit_count) & 1))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit_count--;
			usleep(150);
		}
		byte_count++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*msg;

	pid = atoi(av[1]);
	msg = av[2];
	if (ac != 3)
	{
		ft_printf("Invalid! Please input: ./client [PID] [MESSAGE]");
		return (0);
	}
	client_handler(pid, msg);
	signal(SIGUSR1, message);
}
