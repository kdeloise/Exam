/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 06:18:59 by kdeloise          #+#    #+#             */
/*   Updated: 2019/06/20 06:19:00 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char *ft_strndup(char *str, int len)
{
    int i;
    char *n;

    n = (char *)malloc(sizeof(char) * len + 1);
    if (n == NULL)
        return (NULL);
    i = 0;
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
    while(str[i] != '\0')
    {
        if (str[i] != ' ' && str[i] != '\t')
        {
            j++;
            while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
                i++;
            if (str[i] == '\0')
                    return(j);
        }
        i++;
    }
    return (j);
}

char    **ft_split(char *str)
{
    int i;
    int j;
    int k;
    int len;
    char **spl;

    i = 0;
    j = 0;
    k = 0;
    len = cntwrd(str);
    spl = (char **)malloc(sizeof(char *) * len + 1);
    if (spl == NULL)
        return (NULL);
    while(str[i] != '\0')
    {
        while(str[i] == ' ' || str[i] == '\t')
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
    return (spl);
}

int main()
{
    char *n = "  SFasfsfd asfsdfsdf sdfsdfsdf  fdsfsd";
    char **spl;
    int i;

    i = 0;
    spl = ft_split(n);
    while(spl[i] != '\0')
    {
        printf("%s\n", spl[i]);
        i++;
    }
    return (0);
}