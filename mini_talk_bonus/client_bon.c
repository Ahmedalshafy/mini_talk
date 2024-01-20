/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:20:30 by aalshafy          #+#    #+#             */
/*   Updated: 2024/01/20 19:31:24 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - the client take two arguments, the first is the PID of the server and the second is the string to send
// - the client send the string to the server and the server print it
// The server acknowledges every message received by sending back a signal to the
//client.

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i;

    if (!str)
        return 0;
    i = 0;
    while (str[i])
        i++;
    return i;
}

char *str_to_bin(char *str)
{
    int i;
    int j;
    char *bin;
    int k;

    i = -1;
    j = -1;
    bin = (char *)malloc(sizeof(char) * (ft_strlen(str) * 8 + 1));
    while (str[++i])
    {
        k = 8;
        while (--k >= 0)
        {
            if (str[i] & (1 << k))
                bin[++j] = '1';
            else
                bin[++j] = '0';
        }
    }
    bin[++j] = '\0';
    return bin;
}

// send the string to the server and the server print it
// receive the server response and print it

void	ft_client_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		write(1, "Server signal recieved sucessfully\n", 35);
	}
}

int main(int argc, char **argv)
{
    int server_pid;
    char *str;
    struct sigaction sigact;
    
    if (argc != 3)
    {
        printf("Error: Wrong number of arguments\n");
        return (0);
    }
    sigact.sa_handler = &ft_client_handler;
	sigact.sa_flags = SA_SIGINFO;
    str = str_to_bin(argv[2]);
    printf("%s\n", str);
    server_pid = atoi(argv[1]);
    while (*str)
    {
        if (*str == '0')
        {
            printf("Sending SIGUSR1\n");
            kill(server_pid, SIGUSR1);
        }
        else if (*str == '1')
        {
            printf("Sending SIGUSR2\n");
            kill(server_pid, SIGUSR2);
        }
        str++;
        usleep(100);
    }
    return (0);
}
