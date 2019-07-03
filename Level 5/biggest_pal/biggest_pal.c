/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 02:19:38 by kdeloise          #+#    #+#             */
/*   Updated: 2019/06/27 02:19:39 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void pal(char *str)
{
    int i;
    int j;
    int k;
    int max, min;
    int max1, min1;

    i = 0;
    k = 1;
    while (str[i] != '\0' )
    {
// printf("res - %d\n", i);
        while (str[i] == str[i + k])
        {   
            if (str[i] != str[i + k])
            {
                min1 = i + 1;
                max1 = i + k - 1;
                break ;
            }
            k++;
        }
        if (str[i] == str[i + k])
            k = 1;
        while (str[i + k] == str[i - k])
        {    
            k++;
            if (str[i + k] != str[i - k])
            {
                min = i - k + 1;
                max = i + k - 1;
                break ;
            }
        }
        i++;
        
// printf("min - %d\n", min);
// printf("max - %d\n", max);
        while (min <= max)
        {
            write(1, &str[min], 1);
            min++;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        pal(argv[1]);
    }
    return (0);
}