/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 00:31:23 by kdeloise          #+#    #+#             */
/*   Updated: 2019/06/27 00:31:24 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int        cycle_detector(const t_list *list)
{
    const t_list *first;
    const t_list *second;

    first = list;
    second = list;
    if (!list)
        return (0);
    while (second && second->next)
    {
        first = first->next;
        second = second->next->next;
        if (second == first)
            return(1);
    }
    return (0);
}

int main()
{
    t_list *node1;
    t_list *node2;
    t_list *node3;
    t_list *node4;

    node1 = malloc(sizeof(t_list));
    node2 = malloc(sizeof(t_list));
    node3 = malloc(sizeof(t_list));
    node4 = malloc(sizeof(t_list));

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node3;

printf("%d", cycle_detector(node1));

    return (0);
}