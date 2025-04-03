/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2025/03/24 12:22:35 by ehossain          #+#    #+#             */
/*   Updated: 2025/04/03 18:47:03 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./libft/include/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# ifndef PID_MAX
#  define PID_MAX 4194304
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

#endif
