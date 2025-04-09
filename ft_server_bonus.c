/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:11:01 by ehossain          #+#    #+#             */
/*   Updated: 2025/04/09 10:36:15 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr("Server PID ---> ");
	ft_putnbr(pid);
	ft_putchar('\n');
	if (pid <= 0)
	{
		ft_putstr("Server PID ERROR\n");
		return (1);
	}
	else
	{
		ft_server_init();
	}
	return (0);
}

void	ft_server_init(void)
{
	struct sigaction	signal;

	signal.sa_sigaction = &ft_signal_handler;
	signal.sa_flags = SA_SIGINFO;
	sigemptyset(&signal.sa_mask);
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	ft_putstr("Waiting For Message....\n");
	while (1)
		pause();
}

void	ft_signal_handler(int signal, siginfo_t *info, void *empty)
{
	(void)empty;
	if (signal == SIGUSR1)
		ft_decrypt_char(signal, info);
	if (signal == SIGUSR2)
		ft_decrypt_char(signal, info);
	kill(info->si_pid, SIGUSR1);
}

void	ft_decrypt_char(int signal, siginfo_t *info)
{
	static char	c = 0;
	static int	bit = 0;

	if (signal == SIGUSR1)
		c = c << 1; // Shift bits to the left (make room for next bit)
	if (signal == SIGUSR2)
	{
		c = c << 1; // Shift bits to the left (make room for next bit)
		c = c | 1;  // Add a '1' to the least significant bit
	}
	bit++; // Count the bit
	if (bit == 8)
	{
		ft_manage_buffer(c);
		if (c == '\0')
			kill(info->si_pid, SIGUSR2);
		c = 0;
		bit = 0;
	}
}

void	ft_manage_buffer(char c)
{
	static char		buffer[BUFFER_SIZE];
	static size_t	i = 0;

	if (i < BUFFER_SIZE - 1)
	{
		buffer[i] = c;
		i++;
	}
	if (c == '\0')
	{
		ft_putstr(buffer);
		ft_putchar('\n');
		i = 0;
	}
}
