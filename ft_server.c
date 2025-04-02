/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:23:52 by ehossain          #+#    #+#             */
/*   Updated: 2025/04/02 15:49:30 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_decrypt_message(int signal)
{
	(void)signal;
}

void	ft_signal_handler(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("I AM SIGUSR1 = %d\n", signal);
	if (signal == SIGUSR2)
		ft_printf("I AM SIGUSR2 = %d\n", signal);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("Server PID = %d\n", pid);
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = ft_signal_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) ==
		-1)
	{
		ft_printf("Sigaction Failed\n");
		return (1);
	}
	if (pid < 0 || pid > PID_MAX)
	{
		printf("Pid is not correct\n");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
