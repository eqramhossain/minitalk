/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_binary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:57:52 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/24 15:58:15 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_char_to_binary(char c)
{
	int		j;
	char	binary[9] = {0};
	char	*test;

	j = 7;
	if (c == '\0')
		return (NULL);
	binary[0] = '\0';
	while (j >= 0)
	{
		if (c & (1 << j))
			strcat(binary, "1");
		else
			strcat(binary, "0");
		j--;
	}
	test = binary;
	return (test);
}
