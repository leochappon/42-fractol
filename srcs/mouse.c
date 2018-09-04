/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 20:11:52 by lchappon          #+#    #+#             */
/*   Updated: 2018/08/21 18:38:35 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_unzoom_move(int x, int y, t_fractol *e)
{
	double	tmp;

	tmp = 0;
	if (x > WIDTH / 2)
	{
		tmp = x - (e->x1 / 2);
		e->x1 += tmp;
	}
	else
	{
		tmp = (e->x1 / 2) - x;
		e->x1 -= tmp;
	}
	if (y > HEIGHT / 2)
	{
		tmp = y - (e->y1 / 2);
		e->y1 += tmp;
	}
	else
	{
		tmp = (e->y1 / 2) - y;
		e->y1 -= tmp;
	}
}

void		ft_zoom_move(int x, int y, t_fractol *e)
{
	double	tmp;

	tmp = 0;
	if (x > WIDTH / 2)
	{
		tmp = x - (e->x1 / 2);
		e->x1 -= tmp;
	}
	else
	{
		tmp = (e->x1 / 2) - x;
		e->x1 += tmp;
	}
	if (y > HEIGHT / 2)
	{
		tmp = y - (e->y1 / 2);
		e->y1 -= tmp;
	}
	else
	{
		tmp = (e->y1 / 2) - y;
		e->y1 += tmp;
	}
}

int			ft_deal_mouse(int button, int x, int y, t_fractol *e)
{
	if (y > 0)
	{
		if (button == 1 || button == 4 || button == 6)
		{
			ft_zoom_move(x, y, e);
			e->zoom *= 1.5;
		}
		else if (button == 2 || button == 5 || button == 7)
		{
			ft_unzoom_move(x, y, e);
			e->zoom /= 2;
		}
		else if (button == 3)
		{
			e->x1 = x * 2;
			e->y1 = y * 2;
			e->zoom = e->zoom > 300 ? 300 : e->zoom;
		}
		mlx_clear_window(e->mlx, e->win);
		ft_draw(e);
	}
	return (0);
}

int			ft_julia_mouse(int x, int y, t_fractol *e)
{
	if (e->julia_move == 1)
	{
		e->julia_cr = ((double)x - WIDTH / 2) / (double)(e->zoom / 2);
		e->julia_ci = ((double)y - HEIGHT / 2) / (double)(e->zoom / 2);
	}
	ft_draw(e);
	return (0);
}
