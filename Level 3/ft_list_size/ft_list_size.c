/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 23:59:20 by kdeloise          #+#    #+#             */
/*   Updated: 2019/06/19 23:59:21 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
    int i;
    t_list *list;

    i = 0;
    list = begin_list;
    while (list != NULL)
    {
        list = list->next;
        i++;
    }
    return (i);
}
