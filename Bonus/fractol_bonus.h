/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkanate <vkanate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:44:09 by vkanate           #+#    #+#             */
/*   Updated: 2022/03/29 14:47:12 by vkanate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# define IMAGE_X 1000
# define IMAGE_Y 1000

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_plan {
	void			*mlx;
	void			*win;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	int				color;
	int				n;
	int				i;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	unsigned int	*tab;
	void			*img;
	int				iteration_max;
}	t_plan;

void	ft_init(t_plan *plan);
int		key_hook(int keycode, t_plan *vars);
int		red_close(t_plan *vars);
void	burningship(t_plan *plan);
int		ft_strcmp(const char *s1, const char *s2);
int		mouse_hook(int button, int x, int y, void *params);
int		mouse_move(int x, int y, t_plan *plan);
void	mandelbrot(t_plan *plan);
void	julia(t_plan *plan);
void	ft_init_image(t_plan *plan);

#endif