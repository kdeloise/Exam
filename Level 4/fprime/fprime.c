/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 13:03:43 by kdeloise          #+#    #+#             */
/*   Updated: 2019/06/04 13:03:44 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //atoi
#include <stdio.h>	//printf

int ft_prime(int num)
{
	int d;

	d = 2;
	while (num > d)
	{
		if (num % d == 0)
			return (0);
		d++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int n;
	int d;
	int nb;

	if (argc == 2)
	{
		n = atoi(argv[1]);		
		while (n > d)
		{
			if (n % d == 0 && ft_prime(d) == 1)
				printf("%d*", d);
			d++;
		}
	}
	printf("\n");
	return (0);
}