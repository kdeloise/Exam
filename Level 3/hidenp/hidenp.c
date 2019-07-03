/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 01:19:25 by kdeloise          #+#    #+#             */
/*   Updated: 2019/06/20 01:19:26 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void hidenp(char *str1, char *str2)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str1[i] != '\0' && str2[j] != '\0')
    {
        if (str1[i] == str2[j])
            i++;
        j++;
    }
    if (str1[i] != '\0')
        write (1, "0", 1);
    else
        write (1, "1", 1);
} 

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        hidenp(argv[1], argv[2]);
    }
    write(1, "\n", 1);
    return (0);
}