/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:11:30 by mboumlik          #+#    #+#             */
/*   Updated: 2024/04/19 16:34:33 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./../so_long.h"
int ft_close(int keycode, void *tt)
{
    (void)tt;
    if(keycode == 65307)
        exit(0);
    return 0;
}

int ft_exit(int keycode , void *tt)
{
    (void)tt;
    (void)keycode;
    exit(0);
    return 0;
}

int count_lines(int fd)
{
    int i = 0;
    char *line = get_next_line(fd);
    while (line != NULL)
    {
        i++;
        free(line);
        line = get_next_line(fd);
    }
    return i;
}
