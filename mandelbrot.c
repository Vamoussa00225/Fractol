/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkanate <vkanate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:23:13 by vkanate           #+#    #+#             */
/*   Updated: 2022/03/29 14:20:00 by vkanate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	drawing_mandelbrot(t_plan *plan)
{
	int		i;
	double	tmp;

	i = 0;
	while ((plan->z_r * plan->z_r + plan->z_i * plan->z_i < 4)
		&& (i < plan->iteration_max))
	{
		tmp = plan->z_r;
		plan->z_r = plan->z_r * plan->z_r - plan->z_i
			* plan->z_i + plan->c_r;
		plan->z_i = 2 * plan->z_i * tmp + plan->c_i;
		i++;
	}
	return (i);
}

void	mandelbrot(t_plan *plan)
{
	int		x;
	int		y;
	int		i;

	ft_init_image(plan);
	x = -1;
	while (++x < IMAGE_X)
	{
		y = -1;
		while (++y < IMAGE_Y)
		{
			plan->c_r = (x * (plan->x2 - plan->x1) / 1000) + plan->x1;
			plan->c_i = (y * (plan->y2 - plan->y1) / 1000) + plan->y1;
			plan->z_r = 0;
			plan->z_i = 0;
			i = drawing_mandelbrot(plan);
			if (i != plan->iteration_max)
				plan->tab[y * 1000 + x] = i * plan->color * 650;
		}
	}
	mlx_put_image_to_window(plan->mlx, plan->win, plan->img, 0, 0);
}
