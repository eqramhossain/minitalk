/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:23:45 by ehossain          #+#    #+#             */
/*   Updated: 2025/04/05 09:50:07 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_one_char(int pid, unsigned char c)
{
	int	byte;

	byte = 7;
	while (byte >= 0)
	{
		if (((c >> byte) & 1) == 0)
			kill(pid, SIGUSR1);
		else if (((c >> byte) & 1) == 1)
			kill(pid, SIGUSR2);
		usleep(50);
		byte--;
	}
}

void	ft_send_message(int pid, unsigned char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		ft_send_one_char(pid, message[i]);
		i++;
	}
	ft_send_one_char(pid, '\0');
}

int	main(int ac, char *av[])
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid < 0 || pid > PID_MAX)
		{
			ft_printf("Pid is not correct\n");
			return (1);
		}
		if (av[2][0] == 0)
		{
			ft_printf("No Message Sent\n");
			return (1);
		}
		ft_send_message(pid, (unsigned char *)av[2]);
	}
	else
		ft_putstr_fd("Use case: [./client] [PID_NUM] [Message]", 2);
	return (0);
}
