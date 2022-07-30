/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:59:41 by mliew             #+#    #+#             */
/*   Updated: 2022/07/30 13:42:08 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	int pid = atoi(av[1]);
	
	if (ac != 3)
	{
		ft_printf("Invalid please input: ./client [PID] [MESSAGE]");
		return (0);
	}
	kill(pid, SIGUSR1);
	sleep(2);
	kill(pid, SIGUSR2);

	write (1, av[2], strlen(av[2]));
}