/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:23:45 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/28 16:59:18 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char *av[])
{
	if (ac == 3)
	{
		ft_printf(av[3]);
	}
	else
		ft_putstr_fd("Use case: [./client] [PID_NUM] [Message]", 2);
	return (0);
}
