/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:26:19 by aalshafy          #+#    #+#             */
/*   Updated: 2023/11/18 08:59:53 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr(char *str)
{
	int	i;

	if (str == NULL)
		str = "(null)";
	i = 0;
	while (*str != '\0')
	{
		i += write(1, str, 1);
		str++;
	}
	return (i);
}

// int main()
// {
//     ft_putstr("ahmed");
// }
