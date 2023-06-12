/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 23:27:58 by orazafy           #+#    #+#             */
/*   Updated: 2023/03/15 03:30:28 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	ft_init_zero(int *len, unsigned char *c, int *nb_bits, char **str)
{
	*len = 0;
	*c = 0;
	*nb_bits = 0;
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

void	server_handler(int signum, siginfo_t *info, void *context)
{
	static char				*str;
	static int				len;
	static int				client_pid;
	static int				nb_bits;
	static unsigned char	c;

	(void)context;
	if (client_pid == 0)
		client_pid = info->si_pid;
	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		ft_init_zero(&len, &c, &nb_bits, &str);
	}
	nb_bits++;
	if (signum == SIGUSR1)
		c |= 1;
	if (nb_bits == 8)
		ft_character(&len, &c, &str, &nb_bits);
	c <<= 1;
	usleep(200);
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				server_pid;

	server_pid = getpid();
	ft_putnbr(server_pid);
	sa.sa_sigaction = server_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, 0) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &sa, 0) == -1)
		exit(1);
	while (1)
		pause();
	return (0);
}
