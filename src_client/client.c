/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 23:26:51 by orazafy           #+#    #+#             */
/*   Updated: 2023/03/14 15:36:52 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_signal_received = 0;

void	ft_send_character(int server_pid, unsigned char c)
{
	if ((c & 128) == 128)
	{
		if (kill(server_pid, SIGUSR1) == -1)
			exit(1);
	}
	else
	{
		if (kill(server_pid, SIGUSR2) == -1)
			exit(1);
	}
}

void	ft_send_final_character(int server_pid)
{
	int	i;

	{
		i = 0;
		while (i < 8)
		{
			ft_send_character(server_pid, 0);
			i++;
			if (g_signal_received == 0)
				pause();
			if (g_signal_received == 1)
			{
				usleep(200);
				g_signal_received = 0;
			}
		}
	}
}

void	ft_send_str(int server_pid, char *str)
{
	unsigned char	c;
	int				i;

	while (*str)
	{
		c = *str;
		i = 0;
		while (i < 8)
		{
			ft_send_character(server_pid, c);
			c <<= 1;
			i++;
			if (g_signal_received == 0)
				pause();
			if (g_signal_received == 1)
			{
				usleep(200);
				g_signal_received = 0;
			}
		}
		str++;
	}
	ft_send_final_character(server_pid);
	g_signal_received = 0;
}

void	client_handler(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == SIGUSR1)
		g_signal_received = 1;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					server_pid;

	if (argc != 3)
		exit(1);
	server_pid = ft_atoi(argv[1]);
	sa.sa_sigaction = client_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, 0) == -1)
		exit(1);
	ft_send_str(server_pid, argv[2]);
	return (0);
}
