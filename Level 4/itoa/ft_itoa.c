/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 23:02:07 by kdeloise          #+#    #+#             */
/*   Updated: 2019/04/22 23:02:08 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_lennbr(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	int		nbr;
	char	*t;

	i = (n > 0) ? ft_lennbr(n) : ft_lennbr(n) + 1;
	t = (char *)malloc(sizeof(char) * i + 1);
	if (t == NULL)
		return (0);
	if (n == -2147483648)
		return (ft_strcpy(t, "-2147483648"));
	t[i] = '\0';
	i--;
	nbr = (n < 0) ? (n * -1) : n;
	while (i >= 0)
	{
		t[i] = (nbr % 10 + '0');
		nbr = (nbr / 10);
		i--;
	}
	if (n < 0)
		t[0] = '-';
	return (t);
}
