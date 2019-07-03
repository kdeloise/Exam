/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:16:20 by kdeloise          #+#    #+#             */
/*   Updated: 2019/06/19 21:16:21 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int x)
{
    if (x > 9)
    {
        ft_putnbr(x / 10);
        ft_putnbr(x % 10);
    }
    else
        ft_putchar(x + '0');
}

int ft_atoi(char *str)
{
    int nbr;
    int i;

    i = 0;
    nbr = 0;
    while (str[i] != '\0')
    {
        nbr = nbr * 10;
        nbr = nbr + str[i] - '0';
        i++;
    }
    return (nbr);
}

int ft_prime(int n)
{
    int i;

    i = 2;
    while (i < n)
    {
        if (n % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int add_prime_sum(char *c)
{
    int x;
    int i;
    int res;

    res = 0;
    i = 2;
    x = ft_atoi(c);
    while(i <= x)
    {
        if (ft_prime(i))
        {
            res = res + i;
        }
        i++;
    }
    return (res);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ft_putnbr(add_prime_sum(argv[1]));
    }
    else
        write (1, "0", 1);
    write(1, "\n", 1);
    return (0);
}