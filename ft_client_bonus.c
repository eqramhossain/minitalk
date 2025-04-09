/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:11:42 by ehossain          #+#    #+#             */
/*   Updated: 2025/04/09 10:13:18 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static volatile sig_atomic_t	g_signal_received = 0;

int	main(int ac, char *av[])
{
	int	pid;

	if (ac != 3)
	{
		ft_putstr("Use case [./server] [PID] [Message]\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_putstr("The PID is not correct\n");
		return (0);
	}
	ft_client_init();
	ft_send_message((const char *)av[2], pid);
	return (0);
}

void	ft_client_init(void)
{
	struct sigaction	signal;

	signal.sa_sigaction = &ft_signal_handler;
	signal.sa_flags = SA_SIGINFO;
	sigemptyset(&signal.sa_mask);
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	return ;
}

void	ft_signal_handler(int signal, siginfo_t *info, void *empty)
{
	(void)empty;
	(void)info;
	if (signal == SIGUSR1)
		g_signal_received = 1;
	if (signal == SIGUSR2)
	{
		ft_putstr("Signal Confirmed by the server");
		exit(0);
	}
}

void	ft_send_message(const char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_send_one_char(str[i], pid);
		i++;
	}
	ft_send_one_char(str[i], pid);
}

void	ft_send_one_char(char c, int pid)
{
	int	byte;

	byte = 7;
	while (byte >= 0)
	{
		g_signal_received = 0;
		if (((c >> byte) & 1) == 0)
			kill(pid, SIGUSR1);
		else if (((c >> byte) & 1) == 1)
			kill(pid, SIGUSR2);
		while (!g_signal_received)
			usleep(100);
		byte--;
	}
}
