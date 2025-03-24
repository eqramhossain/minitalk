/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:23:45 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/24 17:12:28 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minitalk.h"

#include <stdio.h>
#include <unistd.h>

int	main(int ac, char *av[])
{
	int	pid;
	int	i;
	int	n;

	pid = fork();
	if (pid == 0)
		n = 1;
	else
		n = 6;
	i = n;
	while (i < n + 5)
	{
		printf("pid = %d i = %d\n", pid, i);
		i++;
	}
	return (0);
}
