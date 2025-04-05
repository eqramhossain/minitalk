/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:23:52 by ehossain          #+#    #+#             */
/*   Updated: 2025/04/05 19:16:16 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_print_message(unsigned char c)
{
	static char		buffer[1000000];
	static size_t	buffer_index = 0;

	if (c == '\0')
	{
		if (buffer_index > 0)
		{
			write(1, buffer, buffer_index);
			write(1, "\n", 1);
		}
		buffer_index = 0;
	}
	else
	{
		if (buffer_index < sizeof(buffer) - 1)
			buffer[buffer_index++] = c;
		else
		{
			write(1, buffer, buffer_index);
			buffer_index = 0;
			buffer[buffer_index++] = c;
		}
	}
}

void	ft_decrypt_message(int signal)
{
	static int				bit_count = 0;
	static unsigned char	tmp_c = 0;

	tmp_c <<= 1;
	if (signal == SIGUSR2)
		tmp_c |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		ft_print_message(tmp_c);
		bit_count = 0;
		tmp_c = 0;
	}
}

void	ft_signal_handler(int signal)
{
	if (signal == SIGUSR1)
		ft_decrypt_message(signal);
	if (signal == SIGUSR2)
		ft_decrypt_message(signal);
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
	if ((sigaction(SIGUSR1, &sa, NULL) == -1) || (sigaction(SIGUSR2, &sa,
				NULL) == -1))
	{
		ft_printf("Sigaction Function Failed\n");
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
