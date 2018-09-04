/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 18:41:57 by lchappon          #+#    #+#             */
/*   Updated: 2018/08/19 16:43:17 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_fractal_name(t_fractol *e)
{
	if (e->fractal == 1)
		mlx_string_put(e->mlx, e->win, 10, 0, 0xFFFFFF, "Mandelbrot");
	else if (e->fractal == 2)
	{
		mlx_string_put(e->mlx, e->win, 10, 0, 0xFFFFFF, "Julia");
		if (e->julia_move == 1)
			mlx_string_put(e->mlx, e->win, 10, 20, 0xFFFFFF,
					"Press space to stop moving");
		else if (e->julia_move == 0)
			mlx_string_put(e->mlx, e->win, 10, 20, 0xFFFFFF,
					"Press space to start moving");
	}
	else if (e->fractal == 3)
		mlx_string_put(e->mlx, e->win, 10, 0, 0xFFFFFF, "Burning Ship");
	else if (e->fractal == 4)
		mlx_string_put(e->mlx, e->win, 10, 0, 0xFFFFFF, "Douady");
}

void		ft_info_box(t_fractol *e)
{
	int		x;
	int		y;

	x = 5;
	y = HEIGHT - 5;
	while (y >= HEIGHT - 175)
		mlx_pixel_put(e->mlx, e->win, x, y--, 0xFFFFFF);
	while (x <= 195)
		mlx_pixel_put(e->mlx, e->win, x++, y, 0xFFFFFF);
	while (y <= HEIGHT - 5)
		mlx_pixel_put(e->mlx, e->win, x, y++, 0xFFFFFF);
	while (x >= 5)
		mlx_pixel_put(e->mlx, e->win, x--, y, 0xFFFFFF);
}

void		ft_info(t_fractol *e)
{
	ft_fractal_name(e);
	if (e->info == 0)
		mlx_string_put(e->mlx, e->win, 10, HEIGHT - 30, 0xFFFFFF,
				"Press C to show commands");
	else if (e->info == 1)
	{
		ft_info_box(e);
		mlx_string_put(e->mlx, e->win, 10, HEIGHT - 170, 0xFFFFFF,
				"FRACTALS = 1 2 3 4");
		mlx_string_put(e->mlx, e->win, 10, HEIGHT - 150, 0xFFFFFF,
				"MOVE = ^ v < >");
		mlx_string_put(e->mlx, e->win, 10, HEIGHT - 130, 0xFFFFFF,
				"ZOOM = mouse");
		mlx_string_put(e->mlx, e->win, 10, HEIGHT - 110, 0xFFFFFF,
				"DEPTH = * /");
		mlx_string_put(e->mlx, e->win, 10, HEIGHT - 90, 0xFFFFFF,
				"DETAILS = + -");
		mlx_string_put(e->mlx, e->win, 10, HEIGHT - 70, 0xFFFFFF,
				"COLOR = R G B");
		mlx_string_put(e->mlx, e->win, 10, HEIGHT - 50, 0xFFFFFF,
				"PSYCHEDELIC = P");
		mlx_string_put(e->mlx, e->win, 10, HEIGHT - 30, 0xFFFFFF,
				"QUIT = esc");
	}
}
