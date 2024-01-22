/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:03:20 by aalshafy          #+#    #+#             */
/*   Updated: 2023/11/18 15:02:25 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	count;	

	count = 0;
	if (nb == -2147483648)
	{
		count = ft_putchar('-');
		count += ft_putchar('2');
		return (count + ft_putnbr(147483648));
	}
	if (nb < 0)
	{
		count = ft_putchar('-');
		return (count + ft_putnbr(-nb));
	}
	else if (nb < 10)
		return (ft_putchar(nb + 48));
	else
	{
		count = ft_putnbr((nb / 10));
		return (count + ft_putnbr((nb % 10)));
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
