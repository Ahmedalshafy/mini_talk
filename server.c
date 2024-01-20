/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:00:38 by aalshafy          #+#    #+#             */
/*   Updated: 2024/01/20 11:23:59 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
creat a communication program between server and client
- the server start first and after it starts print its PID
- the client take two arguments, the first is the PID of the server and the second is the string to send
- the client send the string to the server and the server print it
- the server has to display the string pretty quickly as soon as it is received
- the server must be able to receive strings from several clients in a row, without needing to be restarted
- the communication between processes is done using UNIX signals
- you can only use the two signals SIGUSR1 and SIGUSR2
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// - the server start first and after it starts print its PID

// void   handler(int sig)
// {
//     static int i = 0;
//     static char c = 0;
//     if (sig == SIGUSR1)
//         c = c | (0 << i);
//     else if (sig == SIGUSR2)
//         c = c | (1 << i);
//     i++;
//     if (i == 8)
//     {
//         write(1, &c, 1);
//         i = 0;
//         c = 0;
//     }
// }

void	ft_putnbr(long nbr)
{
	char	temp;

	if (nbr / 10 > 0)
		ft_putnbr(nbr / 10);
	temp = nbr % 10 + '0';
	write(1, &temp, 1);
}

void	sig_handle(int signal)
{
	static int	i;
	static int	n;
	int			nb;

	if (signal == SIGUSR1)
		nb = 0;
	else
		nb = 1;
	n = (n << 1) + nb;
	i++;
	if (i == 8)
	{
		write(1, &n, 1);
		i = 0;
		n = 0;
	}
}

int	main(void)
{
	struct sigaction	sigact;

	sigact.sa_handler = &sig_handle;
	sigact.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sigact, 0);
	sigaction(SIGUSR2, &sigact, 0);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		usleep(100);
	return (0);
}