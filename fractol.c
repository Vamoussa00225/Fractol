/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkanate <vkanate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:56:20 by vkanate           #+#    #+#             */
/*   Updated: 2022/03/29 15:20:11 by vkanate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_choice(t_plan *plan, char *str)
{	
	if (ft_strcmp("julia", str))
	{
		julia(plan);
		plan->i = 0;
		mlx_hook(plan->win, 6, 0, mouse_move, plan);
	}
	else if (ft_strcmp("mandelbrot", str))
	{
		mandelbrot(plan);
		plan->i = 1;
	}
	else
	{
		printf("Parametres disponibles : \n");
		printf("1 - Mandelbrot\n");
		printf("2 - Julia");
		exit (0);
	}
}

int	main(int argc, char **str)
{
	t_plan	plan;

	if (argc == 2)
	{
		ft_init(&plan);
		ft_choice(&plan, str[1]);
		mlx_hook(plan.win, 2, 0, key_hook, &plan);
		mlx_hook(plan.win, 17, 0, red_close, &plan);
		mlx_hook(plan.win, 4, 0, mouse_hook, &plan);
		mlx_loop(plan.mlx);
	}
	else
	{
		printf("Parametres disponibles : \n");
		printf("1 - Mandelbrot\n");
		printf("2 - Julia");
		exit(0);
	}
}
