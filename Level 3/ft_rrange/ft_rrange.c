/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 00:36:46 by kdeloise          #+#    #+#             */
/*   Updated: 2019/06/20 00:36:47 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int ft_abs(int x)
{
    if (x < 0)
        return(-x);
    return (x);
}

int     *ft_rrange(int start, int end)
{
    int *tab;
    int i;

    i = 0;
    tab = (int *)malloc(sizeof(int) * ft_abs(end - start) + 1);
    if (tab == 0)
        return (0);
    while(end >= start)
    {
        tab[i] = end;
        end--;
        i++;
    }
    return (tab);
}

int main()
{
    int i, x, y ,res;
    int *tab;

    x = -1;
    y = 2;
    i = 0;
    tab = ft_rrange(x, y);
    res = y - x;
    while (x <= y)
    {
        printf("%d", tab[i]);
        x++;
        i++;
    }
    return (0);
}