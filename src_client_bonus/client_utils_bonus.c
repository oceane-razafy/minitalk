/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:31:36 by orazafy           #+#    #+#             */
/*   Updated: 2023/04/10 01:02:52 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_char_to_int(char *str)
{
	int	nb;
	int	i;

	i = 1;
	nb = str[0] % '0';
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] % '0');
		i++;
	}
	if (i != ft_strlen(str))
		exit(1);
	return (nb);
}

int	ft_atoi(char *str)
{
	if ((*str < '0' || *str > '9') && (*str != '+'))
		exit(1);
	if (*str == '+')
	{
		str++;
		if (*str < '0' || *str > '9')
			exit(1);
	}
	return (ft_char_to_int(str));
}
