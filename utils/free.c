/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:05:41 by mboumlik          #+#    #+#             */
/*   Updated: 2024/04/25 15:19:27 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void freefun (void ** p)
{
    int i ;
    i = 0; 
    while (p[i])
        free(p[i++]);
    free(p);
    
}
void free_everything(t_long *so_long)
{
    
    // mlx_destroy_window(so_long->mlx,so_long->window);
    // freefun((void **)so_long->map);
    // freefun((void **)so_long->visited);
    // free(so_long->mlx);
    (void) so_long;
    
}