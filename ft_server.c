/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:23:52 by ehossain          #+#    #+#             */
/*   Updated: 2025/04/01 21:23:58 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void	ft_handler(int signal)
// {
// 	if (signal == SIGUSR1)
// 		ft_printf("I AM SIGUSR1\n");
// 	if (signal == SIGUSR2)
// 		ft_printf("I AM SIGUSR2\n");
// }
//
// int	main(void)
// {
// 	signal(SIGUSR1, ft_handler);
// 	signal(SIGUSR2, ft_handler);
// 	ft_printf("Server PID = %d\n", getpid());
// 	while (1)
// 	{
// 		sleep(1);
// 	}
// 	return (0);
// }

int	main(void)
{
	int	id;
	int	n;
	int	w;

	id = fork();
	n = 0;
	w = 5;
	if (id == 0)
		n = 1;
	else
		n = 6;
	if (id != 0)
		wait(&w);
	for (int i = n; i < n + 5; i++)
	{
		printf("%d ", i);
		fflush(stdout);
	}
	printf("\n");
	return (0);
}
