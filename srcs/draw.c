/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 18:40:55 by lchappon          #+#    #+#             */
/*   Updated: 2018/08/19 15:34:34 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_mandelbrot(t_fractol *e)
{
	double	tmp;

	tmp = 0;
	e->zr = (e->x - e->x1 / 2) / e->zoom - 0.5;
	e->zi = (e->y - e->y1 / 2) / e->zoom;
	e->cr = e->zr;
	e->ci = e->zi;
	e->i = 0;
	while (e->zr * e->zr + e->zi * e->zi < 4 && e->i < e->iter_max)
	{
		tmp = e->zr;
		e->zr = e->zr * e->zr - e->zi * e->zi + e->cr;
		e->zi = 2 * tmp * e->zi + e->ci;
		e->i++;
	}
	if (e->i == e->iter_max)
		ft_inside(e);
	else
		ft_outside(e);
}

void		ft_julia(t_fractol *e)
{
	double	tmp;

	tmp = 0;
	e->zr = (e->x - e->x1 / 2) / e->zoom;
	e->zi = (e->y - e->y1 / 2) / e->zoom;
	e->cr = e->julia_cr;
	e->ci = e->julia_ci;
	e->i = 0;
	while (e->zr * e->zr + e->zi * e->zi < 4 && e->i < e->iter_max)
	{
		tmp = e->zr;
		e->zr = e->zr * e->zr - e->zi * e->zi + e->cr;
		e->zi = 2 * tmp * e->zi + e->ci;
		e->i++;
	}
	if (e->i == e->iter_max)
		ft_inside(e);
	else
		ft_outside(e);
}

void		ft_burningship(t_fractol *e)
{
	double	tmp;

	tmp = 0;
	e->zr = (e->x - e->x1 / 2) / e->zoom - 0.5;
	e->zi = (e->y - e->y1 / 2) / e->zoom - 0.5;
	e->cr = e->zr;
	e->ci = e->zi;
	e->i = 0;
	while (e->zr * e->zr + e->zi * e->zi < 4 && e->i < e->iter_max)
	{
		tmp = e->zr;
		e->zr = e->zr * e->zr - e->zi * e->zi + e->cr;
		e->zi = 2 * fabs(tmp * e->zi) + e->ci;
		e->i++;
	}
	if (e->i == e->iter_max)
		ft_inside(e);
	else
		ft_outside(e);
}

void		ft_douady(t_fractol *e)
{
	double	tmp;

	tmp = 0;
	e->zr = (e->x - e->x1 / 2) / e->zoom;
	e->zi = (e->y - e->y1 / 2) / e->zoom;
	e->cr = -0.123;
	e->ci = 0.745;
	e->i = 0;
	while (e->zr * e->zr + e->zi * e->zi < 4 && e->i < e->iter_max)
	{
		tmp = e->zr;
		e->zr = e->zr * e->zr - e->zi * e->zi + e->cr;
		e->zi = 2 * tmp * e->zi + e->ci;
		e->i++;
	}
	if (e->i == e->iter_max)
		ft_inside(e);
	else
		ft_outside(e);
}

void		ft_draw(t_fractol *e)
{
	ft_bzero(e->data, e->s_l * HEIGHT);
	e->x = 0;
	while (e->x < WIDTH)
	{
		e->y = 0;
		while (e->y < HEIGHT)
		{
			if (e->fractal == 1)
				ft_mandelbrot(e);
			else if (e->fractal == 2)
				ft_julia(e);
			else if (e->fractal == 3)
				ft_burningship(e);
			else if (e->fractal == 4)
				ft_douady(e);
			e->y++;
		}
		e->x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ft_info(e);
}
