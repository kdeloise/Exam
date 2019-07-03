/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 06:26:00 by kdeloise          #+#    #+#             */
/*   Updated: 2019/06/06 06:26:04 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

int		cmp(int a, int b)
{
	if (a > b)
		return (0);
	return (1);
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int swap;
	t_list *tmp;

	tmp = lst;
	while (lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}

int main()
{
	t_list	*list1, *list2, *list3, *tmp;
	int x = 32;
	int y = 45;
	int z = 9;

	list1 = malloc(sizeof(t_list));
	list2 = malloc(sizeof(t_list));
	list3 = malloc(sizeof(t_list));
	list1->next = list2;
	list1->data = x;
	list2->next = list3;
	list2->data = y;
	list3->next = NULL;
	list3->data = z;

	tmp = list1;
	while (list1)
	{
		printf("list data = %i\n", list1->data); 
		list1 = list1->next;
	}
	printf("\n");
	list1 = tmp;
	list1 = sort_list(list1, &cmp);
	while (list1)
	{
		printf("list data = %i\n", list1->data);
		list1 = list1->next;
	}
	return (0);
}