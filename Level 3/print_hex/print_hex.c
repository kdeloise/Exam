/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 01:56:16 by kdeloise          #+#    #+#             */
/*   Updated: 2019/06/20 01:56:17 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
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

void print_hex(int x)
{
    if (x >= 16)
    {
        print_hex(x / 16);
        print_hex(x % 16);
    }
    else if (x < 10)
        ft_putchar(x + 48);
    else if (x < 16)
        ft_putchar(x + 87);
}

int main(int argc, char **argv)
{
    if (argc == 2)
        print_hex(ft_atoi(argv[1]));
    write(1, "\n", 1);
    return(0);
}