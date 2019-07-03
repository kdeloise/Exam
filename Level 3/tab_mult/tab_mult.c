/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 03:28:56 by kdeloise          #+#    #+#             */
/*   Updated: 2019/06/20 03:28:56 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c , 1);
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
    int i;
    int res;

    res = 0;
    i = 0;
    while (str[i] != '\0')
    {
        res = res * 10;
        res = res + str[i] - '0';
        i++;
    }
    return (res);
}

void tab_mult(int nbr)
{
    int i;
    int res;

    i = 1;
    while (i < 10)
    {
        ft_putnbr(i);
        write(1, " x ", 3);
        ft_putnbr(nbr);
        write(1, " = ", 3);
        res = i * nbr;
        ft_putnbr(res);
        write(1, "\n", 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        tab_mult(ft_atoi(argv[1]));
    }
    write(1, "\n", 1);
    return (0);
}