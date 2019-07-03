/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 23:57:46 by kdeloise          #+#    #+#             */
/*   Updated: 2019/06/19 23:57:47 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_epur_str(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        while (str[i] != '\t' && str[i] != ' ' && str[i] != '\0')
        {
            ft_putchar(str[i]);
            i++;
        }
        while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
        {   
            i++;
            if (str[i] == '\0')
                while (str[i] == '\t' || str [i] == ' ')
                {
                    i--;
                    if (str[i] != '\t' || str[i] != ' ')
                    {
                        i++;
                        str[i] = '\0';
                    }
                }
        }
        if (str[i] != '\0')
        {
            ft_putchar(' ');
            ft_putchar(' ');
            ft_putchar(' ');
        }
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ft_epur_str(argv[1]);
    }
    write(1, "\n", 1);
    return (0);
}