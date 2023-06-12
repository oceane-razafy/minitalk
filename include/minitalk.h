/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 23:47:09 by orazafy           #+#    #+#             */
/*   Updated: 2023/03/12 23:47:10 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *str);
int		ft_char_to_int(char *str);
int		ft_atoi(char *str);
void	ft_send_character(int server_pid, unsigned char c);
void	ft_send_final_character(int server_pid);
void	ft_send_str(int server_pid, char *str);
void	client_handler(int signum, siginfo_t *info, void *context);
void	ft_putstr(char *str);
char	*ft_strdup_plus_c(char *str, int len, char c);
void	ft_character(int *len, unsigned char *c, char **str, int *nb_bits);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_init_zero(int *len, unsigned char *c, int *nb_bits, char **str);
void	server_handler(int signum, siginfo_t *info, void *context);

#endif