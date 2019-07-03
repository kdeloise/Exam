/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 01:31:37 by kdeloise          #+#    #+#             */
/*   Updated: 2019/06/20 01:31:38 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void pgcd(int x, int y)
{
    int d;

    if (x > y)
    {
        d = y;
        while (d > 0)
        {
            if (y % d == 0 && x % d == 0)
            {
                   printf("%d", d);
                   break ;
            }
            d--;
        }
    }
    else
    {
        d = x;
        while(d > 0)
        {
            if (x % d == 0 && y % d == 0)
            {
                printf("%d", d);
                break ;
            }
            d--;
        }
    }

}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        pgcd(atoi(argv[1]), atoi(argv[2]));
    }
    printf("\n");
    return (0);
}

