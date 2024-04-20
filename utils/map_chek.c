/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chek.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:30:31 by mboumlik          #+#    #+#             */
/*   Updated: 2024/04/20 17:50:57 by mboumlik         ###   ########.fr       */
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
int map_check_coins(t_long *so_long)
{
    int i = 0;
    int j =0;
    int flag = 0;
    while (so_long ->map[i] != NULL)
    {
        j= 0;
        while (so_long->map[i][j] != '\n' && so_long->map[i][j] != '\0')
        {
            if (so_long->map[i][j]  == 'C')
                flag += 1 ;
            j++;
        }
        i++;
    }
    return flag;
}

int fill_array(t_long *so_long)
{
    int i = 0;
    int j = 0;
    so_long->visited = malloc(so_long->height * sizeof(int *));
    while (i < so_long->height)
    {
        j = 0;
        so_long->visited[i] = malloc(so_long->width * sizeof(int));
        while(j < so_long->width)
        {
            so_long->visited[i][j] = 0;
            j++;
        }
        i++;
    }
    return 0;
}

void flood_fill(t_long *so_long, int pos_x, int pos_y)
{
    if (pos_x > 0 && pos_x < so_long->height && pos_y > 0 && pos_y < so_long->width  && so_long->visited[pos_x][pos_y] == 0 && (so_long->map[pos_x][pos_y] == '0' || so_long->map[pos_x][pos_y] == 'P' || so_long->map[pos_x][pos_y] == 'C'))
    {
        // printf("map[%d][%d] = %c\n", pos_x, pos_y, so_long->map[pos_x][pos_y]);
        so_long->visited[pos_x][pos_y] = 1;
        if (so_long->map[pos_x][pos_y] == 'C')
            so_long->collect_found += 1;
        flood_fill(so_long, pos_x - 1, pos_y);
        flood_fill(so_long, pos_x + 1, pos_y);
        flood_fill(so_long, pos_x, pos_y - 1);
        flood_fill(so_long, pos_x, pos_y + 1);
        // printf("collect found == %d\n", so_long->collect_found);
    }
}

void get_player_cord(t_long *so_long)
{
    int x = 0;
    int y = 0;

    while (so_long->map[y] != NULL)
    {
        x = 0;
        while(so_long->map[y][x])
        {
            if (so_long->map[y][x] == 'P')
            {
                so_long->player_y = y;
                so_long->player_x = x;
                return ;
            }
            x++;
        }
        y++;
    }
    return ;
}
