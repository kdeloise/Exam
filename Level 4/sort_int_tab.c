/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:15:23 by kdeloise          #+#    #+#             */
/*   Updated: 2019/06/20 10:15:23 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
    int i;
    int tmp;

    while (i < size)
    {
        if (tab[i] > tab[i + 1])
        {
            tmp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = tmp;
            i = -1;
        }
        i++;
    }
}

int main()
{
    int *tab = {3, 1, 4, 8, 6, 1 ,3 , -1, 5};
    int i;
    
    i = 0;
    sort_int_tab(tab, 6);
    while(i < 9)
    {
        printf("%d", tab[i]);
        i++;
    }
    return (0);
}