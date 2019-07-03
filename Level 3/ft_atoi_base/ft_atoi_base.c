/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 03:46:52 by kdeloise          #+#    #+#             */
/*   Updated: 2019/06/20 03:46:53 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
    int i;
    int n;
    int res;

    i = 0;
    res = 0;
    n = 1;
    if (str[i] == '-')
    {
        n = -1;
        i++;
    }
    while (str[i] != '\0')
    {
        res = res * str_base;
        if(str[i] >= '0' && str[i] <= '9')
            res = res + str[i] - 48;
        else if (str[i] >= 'a' && str[i] <= 'z')
            res = res + str[i] - 87;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            res = res + str[i] - 55;
        i++;
    }
    return(res * n);
}

int main()
{
    printf("%d", ft_atoi_base("255", 4));
    return (0);
}