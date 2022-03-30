/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_close_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkanate <vkanate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:20:12 by vkanate           #+#    #+#             */
/*   Updated: 2022/03/29 14:49:27 by vkanate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_init(t_plan *plan)
{	
	plan->x1 = -2.0;
	plan->n = 0;
	plan->x2 = 2.0;
	plan->y1 = -2.0;
	plan->c_r = 0.3;
	plan->c_i = 0.5;
	plan->y2 = 2.0;
	plan->color = 610;
	plan->iteration_max = 50;
	plan->mlx = mlx_init();
	plan->win = mlx_new_window(plan->mlx, 1000, 1000, "So_long");
}

void	ft_init_image(t_plan *plan)
{
	int	pix;
	int	lin;
	int	d;

	plan->img = mlx_new_image(plan->mlx, IMAGE_X, IMAGE_Y);
	plan->tab = (unsigned int *)mlx_get_data_addr(plan->img, &pix, &lin, &d);
}

void	direction_and_color(t_plan *vars, int keycode)
{
	if (keycode == 49)
		vars->color += 150;
	if (keycode == 123)
	{
		vars->x1 += 0.1;
		vars->x2 += 0.1;
	}
	else if (keycode == 124)
	{
		vars->x1 -= 0.1;
		vars->x2 -= 0.1;
	}
	else if (keycode == 125)
	{
		vars->y1 -= 0.1;
		vars->y2 -= 0.1;
	}
	else if (keycode == 126)
	{
		vars->y1 += 0.1;
		vars->y2 += 0.1;
	}
}

int	key_hook(int keycode, t_plan *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == 32)
	{
		if (vars->n)
			vars->n = 0;
		else
			vars->n = 1;
	}
	direction_and_color(vars, keycode);
	if (!vars->i)
		julia(vars);
	else if (vars->i == 1)
		mandelbrot(vars);
	else if (vars->i == 2)
		burningship(vars);
	return (0);
}

int	red_close(t_plan *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}
