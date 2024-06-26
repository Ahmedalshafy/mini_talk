/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:20:30 by aalshafy          #+#    #+#             */
/*   Updated: 2024/01/22 19:21:25 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "ftprintf/ft_printf.h"

pid_t	ft_atopid(const char *str)
{
	int		sign;
	pid_t	n;

	sign = 1;
	n = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str != 0 && *str >= 48 && *str <= 57)
	{
		n = (n * 10) + (*str - 48);
		str++;
	}
	return (n * sign);
}

void	ft_error_check(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Error: Wrong number of arguments\n");
		exit(0);
	}
	if (ft_atopid(argv[1]) <= 0)
	{
		ft_printf("Error: Wrong arguments\n");
		exit(0);
	}
}

void	send_message(int server_pid, char *str)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = -1;
	while (str[++i])
	{
		k = 8;
		while (--k >= 0)
		{
			if (str[i] & (1 << k))
				kill(server_pid, SIGUSR2);
			else
				kill(server_pid, SIGUSR1);
			usleep(100);
		}
	}
	i = -1;
	while (++i < 8)
	{
		kill(server_pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	ft_error_check(argc, argv);
	server_pid = ft_atopid(argv[1]);
	send_message(server_pid, argv[2]);
	return (0);
}
