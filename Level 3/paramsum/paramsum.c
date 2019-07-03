/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 04:28:28 by kdeloise          #+#    #+#             */
/*   Updated: 2019/06/20 04:28:28 by kdeloise         ###   ########.fr       */
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

int main(int argc, char **argv)
{
    (void)argv;
    ft_putnbr(argc - 1);
    ft_putchar('\n');
    return (0);
}