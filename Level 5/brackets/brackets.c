/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 21:15:26 by kdeloise          #+#    #+#             */
/*   Updated: 2019/07/01 21:15:27 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

static int check(char a, char b)
{
    if ((a == '{' && b == '}') || (a == '[' && b == ']') || (a == '(' && b == ')'))
        return (1);
    return (0);
}

static int brackets(char *str)
{
    int i;
    int top;
    int stack[4096];

    i = 0;
    top = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(')
            stack[++top] = str[i];
        if (str[i] == '}' || str[i] == ']' || str[i] == ')')
            if (check(stack[top--], str[i]) == 0)
                return(0);
        i++;
    }
    if (top != 0)
        return (0);
    else
        return (1);
}
int main(int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (brackets(argv[i]))
        {   
            //printf("!top - %d",brackets(argv[i]));
            write(1, "OK\n", 3);
        }
        else
            write(1, "error\n", 6);
        i++;
    }
    return (0);
}