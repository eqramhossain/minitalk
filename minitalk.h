/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2025/03/24 12:22:35 by ehossain          #+#    #+#             */
/*   Updated: 2025/04/09 09:44:29 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# define BUFFER_SIZE 100000

/* size_t max = 18446744073709551615 */

/* helper function from libft */

void	ft_putchar(const char c);
void	ft_putstr(const char *str);
int		ft_atoi(const char *nbr);
void	ft_putnbr(int n);

/*              END           */

/* functions used in the client */

void	ft_client_init(void);
void	ft_signal_handler(int signal, siginfo_t *info, void *empty);
void	ft_send_message(const char *str, int pid);
void	ft_send_one_char(char c, int pid);

/*              END           */

/* functions used in the server */

void	ft_signal_handler(int signal, siginfo_t *info, void *empty);
void	ft_server_init(void);
void	ft_decrypt_char(int signal);
void	ft_manage_buffer(char c);

/*              END           */

#endif
