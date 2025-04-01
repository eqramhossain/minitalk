/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:23:45 by ehossain          #+#    #+#             */
/*   Updated: 2025/04/01 16:10:06 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char *av[])
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		ft_printf("%d\n", pid);
		ft_printf("%s\n", av[2]);
	}
	else
		ft_putstr_fd("Use case: [./client] [PID_NUM] [Message]", 2);
	return (0);
}
