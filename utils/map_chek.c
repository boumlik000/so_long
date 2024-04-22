/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chek.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:30:31 by mboumlik          #+#    #+#             */
/*   Updated: 2024/04/21 16:43:15 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void map_check_borders(t_long *so_long)
{
    int i= 0, j=0;
    
    while (so_long->map[i] != NULL)
    {
        j = 0;
        while (so_long->map[i][j] != '\n' && so_long->map[i][j] != '\0')
        {
            if (so_long->map[0][j] != '1' || so_long->map[so_long->height - 1][j] != '1')
            {
                printf("error in map border");
                exit(1);
            }
            if (so_long->map[i][0] != '1' || so_long->map[i][so_long->width - 1] != '1')
            {
                printf("error in map border");
                exit(1);
            }
            j++;
        }
        i++;
    }
}

void map_chek_width(t_long *so_long)
{
    int i = 0,j,m = 0;
    while (so_long->map[i] != NULL)
    {
        j = 0;
        while (so_long->map[i][j] != '\n' && so_long->map[i][j] != '\0')
        {
            j++;
        }
        i++;
        m = i;
    }
    j=0;
    i=0;
    while (so_long->map[i][j] != '\n')
        j++;

    if(m == j)
    {
        printf("makhssoch ikon morba3");
        exit(1);
    }
}

void map_check_player(t_long *so_long)
{
   int i =0;
   int j ;
   so_long->flag_player=0;
   so_long->flag_coin=0;
   so_long->flag_exit=0;
    while (so_long->map[i] != NULL)
    {
        j=0;
        while (so_long->map[i][j] != '\n' && so_long->map[i][j] != '\0')
        {
            if(so_long->map[i][j] == 'P')
                so_long->flag_player += 1;
            if(so_long->map[i][j] == 'E')
                so_long->flag_exit += 1;
            if(so_long->map[i][j] == 'C')
                so_long->flag_coin +=1;
            j++;
        }
       i++;
    }
    if (so_long->flag_coin < 1 || so_long->flag_exit != 1 ||so_long->flag_player != 1 )
    {
        printf("Error\nan item is missing\n");
        exit(1);
    }
}
// void map_check_path(t_long *s_long)