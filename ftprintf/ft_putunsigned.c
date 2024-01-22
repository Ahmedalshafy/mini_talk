/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:03:20 by aalshafy          #+#    #+#             */
/*   Updated: 2023/11/18 14:40:32 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int nb)
{
	int	count;	

	count = 0;
	if (nb < 10)
		return (ft_putchar(nb + 48));
	else
	{
		count = ft_putunsigned((nb / 10));
		return (count + ft_putunsigned((nb % 10)));
	}
}

// int	main(void)
// {
// 	int	x = -2147483648;
// 	int y;

// 	y = ft_putnbr(x);
// 	printf("\n");
// 	printf("%i\n", y);
// }
