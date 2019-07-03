/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 02:23:05 by kdeloise          #+#    #+#             */
/*   Updated: 2019/06/20 02:23:05 by kdeloise         ###   ########.fr       */
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
            if (str[i + 1] != ' ' || str[i + 1] != '\t' || str[i + 1] != '\0')
                str[i] = str[i] + 32;
        if (str[i] >= 'a' && str[i] <= 'z')
            if (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0')
                str[i] = str[i] - 32;
        write(1, &str[i], 1);
        i++;
    }

}

int main(int argc, char **argv)
{
    int i;

    i = 1;
    while (argv[i] != '\0')
    {
        cap(argv[i]);
        write(1, "\n", 1);
        i++;
    }
    return (0);
}