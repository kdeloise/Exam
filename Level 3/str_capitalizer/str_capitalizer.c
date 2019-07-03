/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 04:39:25 by kdeloise          #+#    #+#             */
/*   Updated: 2019/06/20 04:39:26 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void cap(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
           if (str[i - 1] != ' ' || str[i - 1] != '\t' || i - 1 != -1)
               str[i] = str[i] + 32;
        if (str[i] >= 'a' && str[i] <= 'z')
            if (str[i - 1] == ' ' || str[i - 1] == '\t' || i - 1 == -1)
               str[i] = str[i] - 32;
        ft_putchar(str[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    int i;

    i = 1;
    while(argv[i] != '\0')
    {
        cap(argv[i]);
        ft_putchar('\n');
        i++;
    }
    return (0);
}