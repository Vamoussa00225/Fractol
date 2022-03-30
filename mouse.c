/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkanate <vkanate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 23:22:48 by vkanate           #+#    #+#             */
/*   Updated: 2022/03/29 13:35:35 by vkanate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_plan *plan, int button)
{
	if (button == 5)
	{
		plan->x1 *= 0.9;
		plan->x2 *= 0.9;
		plan->y1 *= 0.9;
		plan->y2 *= 0.9;
		plan->iteration_max++;
	}
	else if (button == 4)
	{
		plan->x1 /= 0.9;
		plan->x2 /= 0.9;
		plan->y1 /= 0.9;
		plan->y2 /= 0.9;
		if (plan->x1 > -2.1)
			plan->iteration_max--;
	}
}

int	mouse_hook(int button, int x, int y, void *params)
{
	t_plan	*plan;

	x = 0;
	y = 0;
	plan = (t_plan *)params;
	if (button == 5 && plan->x1 <= -0.00001)
		zoom(plan, button);
	else if (button == 4 && plan->x1 > -18.1)
		zoom(plan, button);
	if (!plan->i)
		julia(plan);
	else
		mandelbrot(plan);
	return (0);
}

int	mouse_move(int x, int y, t_plan *plan)
{
	if (x < 1000 && y < 1000)
	{
		plan->c_r = (x / 200) + plan->x1;
		plan->c_i = (y / 200) + plan->y1;
		julia(plan);
	}
	return (0);
}
