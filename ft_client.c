/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:23:45 by ehossain          #+#    #+#             */
/*   Updated: 2025/04/02 15:56:16 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_message(int pid, char *message)
{
	printf("pid = %d\n", pid);
	printf("%s\n", message);
}

int	main(int ac, char *av[])
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		ft_send_message(pid, av[2]);
		kill(pid, 9);
	}
	else
		ft_putstr_fd("Use case: [./client] [PID_NUM] [Message]", 2);
	return (0);
}
