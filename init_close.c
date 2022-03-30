/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkanate <vkanate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 23:24:31 by vkanate           #+#    #+#             */
/*   Updated: 2022/03/29 14:41:43 by vkanate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init(t_plan *plan)
{	
	plan->x1 = -2;
	plan->x2 = 2;
	plan->y1 = -2;
	plan->c_r = 0.3;
	plan->c_i = 0.5;
	plan->y2 = 2;
	plan->color = 1;
	plan->iteration_max = 50;
	plan->mlx = mlx_init();
	plan->win = mlx_new_window(plan->mlx, 1000, 1000, "Fractol");
}

void	ft_init_image(t_plan *plan)
{
	int	pix;
	int	lin;
	int	d;

	plan->img = mlx_new_image(plan->mlx, IMAGE_X, IMAGE_Y);
	plan->tab = (unsigned int *)mlx_get_data_addr(plan->img, &pix, &lin, &d);
}

int	key_hook(int keycode, t_plan *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	red_close(t_plan *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}
