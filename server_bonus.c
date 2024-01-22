/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:00:38 by aalshafy          #+#    #+#             */
/*   Updated: 2024/01/22 19:22:33 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ftprintf/ft_printf.h"

void	ft_putlong(long nbr)
{
	char	temp;

	if (nbr / 10 > 0)
		ft_putlong(nbr / 10);
	temp = nbr % 10 + '0';
	write(1, &temp, 1);
}

void	sig_handle(int signal, siginfo_t *info, void *context)
{
	static int	i;
	int			nb;
	static int	n;

	(void)context;
	if (signal == SIGUSR1)
		nb = 0;
	else
		nb = 1;
	n = (n << 1) + nb;
	i++;
	if (i == 8)
	{
		if (n == '\0')
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		else
			write(1, &n, 1);
		i = 0;
		n = 0;
	}
	else
		kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sigact;

	sigemptyset(&sigact.sa_mask);
	sigact.sa_sigaction = &sig_handle;
	sigact.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1, &sigact, 0);
	sigaction(SIGUSR2, &sigact, 0);
	ft_putlong(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
