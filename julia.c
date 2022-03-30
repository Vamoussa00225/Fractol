/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkanate <vkanate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:24:11 by vkanate           #+#    #+#             */
/*   Updated: 2022/03/29 14:40:08 by vkanate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	drawing(t_plan *plan)
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

void	julia(t_plan *plan)
{
	int		x;
	int		y;
	int		i;

	x = -1;
	ft_init_image(plan);
	while (++x < IMAGE_X)
	{
		y = -1;
		while (++y < IMAGE_Y)
		{
			plan->z_r = (x * (plan->x2 - plan->x1) / 1000) + plan->x1;
			plan->z_i = (y * (plan->x2 - plan->x1) / 1000) + plan->y1;
			i = drawing(plan);
			if (i != plan->iteration_max)
				plan->tab[y * 1000 + x] = i * plan->color * 650;
		}
	}
	mlx_put_image_to_window(plan->mlx, plan->win, plan->img, 0, 0);
}
