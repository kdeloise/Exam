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
#include <fcntl.h>
#define BUFSIZE 1000000

void pal(char *str)
{
    int i;
    int j;
    int maxlen, maxlen1, maxlen2;
    int max, min;
    int max1, min1;
    int max2, min2;

    i = 0;
    maxlen = 0;
    maxlen1 = 0;
    maxlen2 = 0;
    min = 0; max = 0; max1 = 0; min1 = 0;
    while (str[i] != '\0')
    {
        if (str[i] == str[i + 1])
        {
            min1 = i;
            max1 = i + 1;
            while (str[min1] == str[max1])
            {
                max1++;
                min1--;
                if (str[min1] != str[max1] || min1 < 0)
                {
                    min1++;
                    max1--;
                    maxlen1 = max1 - min1;
                    if (maxlen1 >= maxlen)
                    {
                        maxlen = maxlen1;
                        max = max1;
                        min = min1;
                    }
                        break ;
                }
            }
        }
        if (str[i - 1] == str[i + 1])
        {
            min2 = i - 1;
            max2 = i + 1;
            while (str[min2] == str[max2])
            {
                max2++;
                min2--;
                if (str[min2] != str[max2] || min2 < 0)
                {
                    min2++;
                    max2--;
                    maxlen2 = max2 - min2;
                    if (maxlen2 >= maxlen)
                    {
                        maxlen = maxlen2;
                        max = max2;
                        min = min2;
                    }
                        break ;
                }
            }
        }
        i++;
    }
    if (maxlen > 0)
    {
        while (min <= max)
        {
            write(1, &str[min], 1);
            min++;
        }
    }
    else if (maxlen == 0)
    {
        write(1, &str[i - 1], 1);
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    // char buf[BUFSIZE + 1];
    // int fd;
    // int ret;

    if (argc == 2)
    {
        // fd = open(argv[1], O_RDONLY);
        // while (read(fd, buf, BUFSIZE) > 0)
        //     ;   
        pal(argv[1]);
    }
    return (0);
}