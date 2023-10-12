/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milousinke <milousinke@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:20:58 by milousinke        #+#    #+#             */
/*   Updated: 2023/10/12 20:52:00 by milousinke       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char    *ft_strrchr(const char *str, int c)
{
    const char a = c;
    int i;

    i = strlen((char *)str);
    while (i >= 0)
    {
        if (c == str[i])
            return(*str);
        else if (str[i] == '0')
            return(*str);
    }
    
    return (NULL);
}

int main(void)
{
    char    str[] = "HalloHallo";
    char c = 'a';
    ft_strrchr(str, c);
    return (0);
}