/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:59:41 by mliew             #+#    #+#             */
/*   Updated: 2022/08/01 18:24:07 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	int pid = atoi(av[1]);
	char *msg = av[2];
	int	bit_count = 7;
	int byte_count = 0;
	char c;
	
	if (ac != 3)
	{
		ft_printf("Invalid please input: ./client [PID] [MESSAGE]");
		return (0);
	}
	// kill(pid, SIGUSR1);
	// sleep(2);
	// kill(pid, SIGUSR2);
	
	// while (bit_count > 0)
	// {
		// c >>= 1;
		// printf("%i", c);
	// }
	while (msg[byte_count])
	{
		c = msg[byte_count];
		bit_count = 7;
		while (bit_count >= 0)
		{
			if (c && ((c >> bit_count) & 1))
			{
				kill(pid, SIGUSR1);
				printf("1");
			}
			else
			{
				kill(pid, SIGUSR2);
				printf("0");
			}
			bit_count--;
		}
		printf(" %c\n", c);
		byte_count++;
	}
}