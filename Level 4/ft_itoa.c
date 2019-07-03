/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 09:30:05 by kdeloise          #+#    #+#             */
/*   Updated: 2019/06/20 09:30:06 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int lennbr(int n)
{
    int len;

    len = 0;
    while(n != 0)
    {
        n = n / 10;
        len++;
    }
    return (len);
}

char	*ft_itoa(int nbr)
{
    int x;
    int len;
    char *n;

    len = (nbr > 0) ? lennbr(nbr) : lennbr(nbr) + 1;
    n = (char *)malloc(sizeof(char) * len + 1);
    if (n == NULL)
        return (NULL);
    if (nbr == -2147483648)
        return ("-2147483648");
    n[len] = '\0';
    len--;
    x = (nbr < 0) ? (nbr * -1) : nbr;
    while (len >= 0)
    {
        n[len] = (x % 10 + '0');
        x = (x / 10);
        len--;
    }
    if (nbr < 0)
        n[0] = '-';
    return (n);
}

int main()
{
    printf("%s", ft_itoa(-2147488));
    return (0);
}