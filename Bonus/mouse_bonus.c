/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkanate <vkanate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 23:22:48 by vkanate           #+#    #+#             */
/*   Updated: 2022/03/29 00:41:42 by vkanate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	rappel(t_plan *plan)
{
	if (!plan->i)
		julia(plan);
	else if (plan->i == 1)
		mandelbrot(plan);
	else if (plan->i == 2)
		burningship(plan);
}

int	mouse_hook(int button, int x, int y, void *params)
{
	t_plan	*plan;
	float	mouse_x;
	float	mouse_y;

	plan = (t_plan *)params;
	mouse_x = (x * (plan->x2 - plan->x1) / 1000) + plan->x1;
	mouse_y = (y * (plan->y2 - plan->y1) / 1000) + plan->y1;
	if (button == 5)
	{
		plan->x1 = ((plan->x1 - mouse_x) * 0.9) + mouse_x;
		plan->x2 = ((plan->x2 - mouse_x) * 0.9) + mouse_x;
		plan->y1 = ((plan->y1 - mouse_y) * 0.9) + mouse_y;
		plan->y2 = ((plan->y2 - mouse_y) * 0.9) + mouse_y;
	}
	else if (button == 4 && plan->x1 > -18.1)
	{
		plan->x1 = ((plan->x1 - mouse_x) / 0.9) + mouse_x;
		plan->x2 = ((plan->x2 - mouse_x) / 0.9) + mouse_x;
		plan->y1 = ((plan->y1 - mouse_y) / 0.9) + mouse_y;
		plan->y2 = ((plan->y2 - mouse_y) / 0.9) + mouse_y;
	}
	rappel(plan);
	return (0);
}

int	mouse_move(int x, int y, t_plan *plan)
{
	if (x < 1000 && y < 1000 && !plan->n && !plan->i)
	{
		plan->c_r = (x / 200) + plan->x1;
		plan->c_i = (y / 200) + plan->y1;
		julia(plan);
	}
	return (0);
}
