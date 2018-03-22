/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:14:00 by lprior            #+#    #+#             */
/*   Updated: 2018/03/21 16:46:10 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_repeat(t_env *all)
{
    ft_calc_radian(all->rot);
    ft_lets_get_started(all->links, all->rot, all);
    mlx_clear_window(all->mlx, all->win);
    ft_draw(all, all->links, all->tools);
}

int    ft_key_hook(int key, t_env *all)
{
    // printf("in key hook\n");
    if (key == 53)
    {
        write(1, "quit\n", 5);
        //ft_exit(1, all);//I have to free all my structs close window and terminate program;
    }
    else if (key == 126)
        all->rot->degree_x += .01;
    else if (key == 124)
        all->rot->degree_y += .01;
    else if (key == 125)
        all->rot->degree_x -= .01;
    else if (key == 123)
        all->rot->degree_y -= .01;
    ft_repeat(all);
    return (0);
}

void ft_mlx_looper(t_env *all)
{
    all->mlx = mlx_init();
    all->win = mlx_new_window(all->mlx, WIDTH, HEIGHT, "KMS");
    ft_draw(all, all->links, all->tools);
    mlx_key_hook(all->win, ft_key_hook, all);
    mlx_loop(all->mlx);
}