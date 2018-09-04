/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 20:09:56 by lchappon          #+#    #+#             */
/*   Updated: 2018/09/04 15:18:03 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_details(int keycode, t_fractol *e)
{
	if (keycode == 69)
		e->iter_max += 5;
	else if (keycode == 78 && e->iter_max > 5)
		e->iter_max -= 5;
	else if (keycode == 67)
	{
		e->depth++;
		e->depth = e->depth == 257 ? 1 : e->depth;
	}
	else if (keycode == 75)
	{
		e->depth--;
		e->depth = e->depth == 0 ? 256 : e->depth;
	}
	else if (keycode == 8)
		e->info = e->info == 0 ? 1 : 0;
	else if (keycode == 35)
		e->psy = e->psy == 0 ? 1 : 0;
	mlx_clear_window(e->mlx, e->win);
	ft_draw(e);
}

void		ft_color(int keycode, t_fractol *e)
{
	if (e->r == 255 && e->g == 255 && e->b == 255)
	{
		e->r = 0;
		e->g = 0;
		e->b = 0;
	}
	if (keycode == 15)
		e->r = e->r == 255 ? 0 : 255;
	else if (keycode == 5)
		e->g = e->g == 255 ? 0 : 255;
	else if (keycode == 11)
		e->b = e->b == 255 ? 0 : 255;
	if (e->r == 0 && e->g == 0 && e->b == 0)
	{
		e->r = 255;
		e->g = 255;
		e->b = 255;
	}
	mlx_clear_window(e->mlx, e->win);
	ft_draw(e);
}

void		ft_move(int keycode, t_fractol *e)
{
	if (keycode == 123)
		e->x1 += 100;
	else if (keycode == 124)
		e->x1 -= 100;
	else if (keycode == 125)
		e->y1 -= 100;
	else if (keycode == 126)
		e->y1 += 100;
	else if (keycode == 49)
		e->julia_move = e->julia_move == 1 ? 0 : 1;
	mlx_clear_window(e->mlx, e->win);
	ft_draw(e);
}

void		ft_fractal(int keycode, t_fractol *e)
{
	if (keycode == 18 || keycode == 83)
		e->fractal = 1;
	else if (keycode == 19 || keycode == 84)
		e->fractal = 2;
	else if (keycode == 20 || keycode == 85)
		e->fractal = 3;
	else if (keycode == 21 || keycode == 86)
		e->fractal = 4;
	else
		return ;
	e->x1 = WIDTH;
	e->y1 = HEIGHT;
	e->zoom = 300;
	e->iter_max = 50;
	mlx_clear_window(e->mlx, e->win);
	ft_draw(e);
}

int			ft_deal_key(int keycode, t_fractol *e)
{
	if (keycode == 53)
		exit(0);
	ft_fractal(keycode, e);
	ft_move(keycode, e);
	if (e->psy == 0)
		ft_color(keycode, e);
	ft_details(keycode, e);
	return (0);
}
