/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:01:36 by mliew             #+#    #+#             */
/*   Updated: 2022/08/01 18:30:07 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int sig)
{
	static int	bit;
	
	if (sig == SIGUSR1)
		bit = 1;
	if (sig == SIGUSR2)
		bit = 0;
	bit <<= 1;
}


int	main()
{
	int pid = getpid();
	
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	printf("%d\n", pid);
	while (1)
	{
		sleep(1);
	}
}

// signal
// sigemptyset
// sigaddset
// sigaction
// kill
// getpid
// malloc
// free
// pause
// sleep
// usleep
// exit
