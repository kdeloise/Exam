/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 06:51:14 by kdeloise          #+#    #+#             */
/*   Updated: 2019/06/20 06:51:15 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}

char *ft_strndup(char *str, int len)
{
    char *n;
    int i;

    i = 0;
    n = (char *)malloc(sizeof(char) * len + 1);
    if (n == NULL)
        return (NULL);
    while (i < len)
    {
        n[i] = str[i];
        i++; 
    }
    n[i] = '\0';
    return (n);
}

int cntwrd(char *str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        if (str[i] != ' ' && str[i] != '\t')
        {
            j++;
            while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
                i++;
            if (str[i] == '\0')
                return (j);
        }
        i++;
    }
    return (j);
}

char **ft_split(char *str)
{
    char **spl;
    int len;
    int i;
    int j;
    int k;

    j = 0;
    k = 0;
    i = 0;
    len = cntwrd(str);
    spl = (char **)malloc(sizeof(char *) * len + 1);
    if (spl == NULL)
        return (NULL);
    while (str[i] != '\0')
    {
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        j = i;
        while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
            i++;
        if (i > j)
        {
            spl[k] = ft_strndup(&str[j], i - j);
            k++;
        }
    }
    spl[k] = NULL;
    return(spl);
}

void rev(char *str)
{
    char **spl;
    int i;

    i = 0;
    spl = ft_split(str);
    while (spl[i] != '\0')
        i++;
    i--;
    while (i >= 0)
    {
        ft_putstr(spl[i]);
        if (i > 0)
            ft_putchar(' ');
        i--;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        rev(argv[1]);
    }
    write(1, "\n", 1);
    return (0);
}
