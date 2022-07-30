/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:01:36 by mliew             #+#    #+#             */
/*   Updated: 2022/07/30 13:33:32 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int num)
{
	write(STDOUT_FILENO,"Terminal is terminating...\n", 28);
}

void	handler2(int num)
{
	int pid = getpid();
	write(STDOUT_FILENO,"TERMINAL KILLED\n", 17);
	kill(pid, SIGKILL);
}

int	main()
{
	int pid = getpid();
	
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler2);
	while (1)
	{
		printf("Im just stuck in a loop. %d\n", pid);
		sleep(1);
	}
	// ft_printf("%d\n", id);
	// pause();
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
