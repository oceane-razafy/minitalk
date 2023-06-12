/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:32:50 by orazafy           #+#    #+#             */
/*   Updated: 2023/03/14 15:06:05 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr(char *str)
{
	if (str != NULL)
	{
		while (*str)
			write(1, str++, 1);
	}
}

char	*ft_strdup_plus_c(char *str, int len, char c)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
	{
		if (str != NULL)
			free(str);
		exit(1);
	}
	i = 0;
	if (str != NULL)
	{
		while (str[i])
		{
			dest[i] = str[i];
			i++;
		}
	}
	dest[i++] = c;
	dest[i] = 0;
	if (str != NULL)
		free(str);
	return (dest);
}

void	ft_character(int *len, unsigned char *c, char **str, int *nb_bits)
{
	(*len)++;
	if (*c == 0)
	{
		ft_putstr(*str);
		free(*str);
		*str = NULL;
	}
	else if (*c != 0)
		*str = ft_strdup_plus_c(*str, *len, *c);
	*c = 0;
	*nb_bits = 0;
}
