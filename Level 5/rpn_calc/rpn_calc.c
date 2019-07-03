/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 06:18:36 by kdeloise          #+#    #+#             */
/*   Updated: 2019/06/29 06:18:37 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return(i);
}

int operate(int a, int b, char c)
{
    if (c == '*')
        return (a * b);
    if (c == '+')
        return (a + b);
    if (c == '-')
        return (a - b);
    if (c == '/')
    {
        if (b == 0)
        {
            return (9942);
        }
        return (a / b);
    }
    if (c == '%')
    {
        if (b == 0)
        {
            return (9942);
        }
        return (a % b);
    }
    return (9942);
}

int num(char *str)
{
    if(*str == '-' || *str == '+')
        str++;
    if (*str >= 0 || *str <=9)
        return(1);
    return (0);
}

int op(char c)
{
    if (c == '+' || c == '-' || c == '%' || c =='*' || c == '/')
        return (1);
    return (0);
}

int calc(char *str)
{
    int len;
    int i;
    int j;
    int *stack;

    len = ft_strlen(str);
    stack = (int *)malloc(sizeof(int) * len); 
    while (str[i] != '\0')
    {
        if (num(&str[i]))
        {
            j++;
            stack[j] = atoi(&stack);
        }
        if (op(str[i]))
            if ((operate(stack[j - 1],)


    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        calc(argv[1]);
    else
        write(1, "Error\n", 6);
    return (0);
}