/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:23:52 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/27 14:59:24 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signal)
{
	printf("signal = %d\n", signal);
}

int	main(void)
{
	// struct sigaction	sa;
	//
	// sa.sa_handler = ft_handler;
	// sigemptyset(sa.sa_mask);
	// sa.sa_flags = SA_RESTART;
	// sigaction(SIGINT, &sa, NULL);
	ft_handler(43);
	return (0);
}
