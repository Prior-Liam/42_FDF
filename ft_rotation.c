/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:56:05 by lprior            #+#    #+#             */
/*   Updated: 2018/03/24 12:24:07 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
        // printf("here = %f\n", rot->x0);
        // printf("x = %f y = %f\n", rot->x2, rot->y2);
        // printf("x2 = %f y2 = %f\n", rot->x2, rot->y2);
        //  printf("tru_x = %f tru_y = %f\n", links->tru_x, links->tru_y);
//okay bud im leaking in here!!!!!!!!!!!
t_links     *ft_lets_get_started(t_links *head, t_rotation *rot, t_env *all)
{
    t_links *links;

    links = head;
    while (links)//->next != NULL)
    {
        rot->x0  =  (double)links->x;
        rot->y0  =  ((links->y) * cos(rot->radian_x)) + (links->altitude * sin(rot->radian_x));
        rot->z0  =  (links->altitude * cos(rot->radian_x)) - ((links->y) * sin(rot->radian_x));
        rot->x1  =  (rot->x0 * cos(rot->radian_y)) - (rot->z0 * sin(rot->radian_y));
        rot->y1  =  rot->y0;
        rot->z1  =  (rot->z0 * cos(rot->radian_y)) + (rot->x0 * sin(rot->radian_y));
        rot->x2  =  (rot->x1 * cos(rot->radian_z)) + (rot->y1 * sin(rot->radian_z));
        rot->y2  =  (rot->y1 * cos(rot->radian_z)) - (rot->x1 * sin(rot->radian_z));
        rot->x2 *= (WIDTH - 320) / all->x_max;
        rot->y2 *= (HEIGHT - 300) / all->y_max;
        rot->x2 += 150;
        rot->y2 += 150;
        links->tru_y = rot->y2;
        links->tru_x = rot->x2;
        links = links->next;
    }
    return (head);
}

// t_links     *ft_lets_get_started(t_links *head, t_rotation *rot, t_env *all)
// {
//     t_links *links;

//     links = head;
//     while (links)//->next != NULL)
//     {
//         rot->x0  =  (double)links->x - 1;
//         rot->y0  =  ((links->y - 1) * cos(rot->degree_x)) + (links->altitude * sin(rot->degree_x));
//         rot->z0  =  (links->altitude * cos(rot->degree_x)) - ((links->y - 1) * sin(rot->degree_x));
//         rot->x1  =  (rot->x0 * cos(rot->degree_y)) - (rot->z0 * sin(rot->degree_y));
//         rot->y1  =  rot->y0;
//         rot->z1  =  (rot->z0 * cos(rot->degree_y)) + (rot->x0 * sin(rot->degree_y));
//         rot->x2  =  (rot->x1 * cos(rot->degree_z)) + (rot->y1 * sin(rot->degree_z));
//         rot->y2  =  (rot->y1 * cos(rot->degree_z)) - (rot->x1 * sin(rot->degree_z));
//         rot->x2 *= 10;// (WIDTH - 200) / all->x_max;
//         rot->y2 *= 10;// (HEIGHT - 200) / all->y_max;
//         rot->x2 += 150;
//         rot->y2 += 150;
//         links->tru_y = rot->y2;
//         links->tru_x = rot->x2;
//         links = links->next;
//     }
//     return (head);
// }