/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 15:30:55 by lchappon          #+#    #+#             */
/*   Updated: 2018/08/21 16:51:02 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_psychedelic3(t_fractol *e, int layer)
{
	if (layer == 2)
	{
		e->psy_r = 0;
		e->psy_g = 0;
		e->psy_b = 255;
	}
	else if (layer == 1)
	{
		e->psy_r = 128;
		e->psy_g = 0;
		e->psy_b = 255;
	}
	else if (layer == 0)
	{
		e->psy_r = 255;
		e->psy_g = 0;
		e->psy_b = 255;
	}
}

void		ft_psychedelic2(t_fractol *e, int layer)
{
	if (layer == 5)
	{
		e->psy_r = 255;
		e->psy_g = 255;
		e->psy_b = 0;
	}
	else if (layer == 4)
	{
		e->psy_r = 0;
		e->psy_g = 255;
		e->psy_b = 0;
	}
	else if (layer == 3)
	{
		e->psy_r = 0;
		e->psy_g = 255;
		e->psy_b = 255;
	}
	ft_psychedelic3(e, layer);
}

void		ft_psychedelic1(t_fractol *e)
{
	int		layer;

	layer = (e->i + e->depth) % 8;
	if (layer == 7)
	{
		e->psy_r = 255;
		e->psy_g = 0;
		e->psy_b = 0;
	}
	else if (layer == 6)
	{
		e->psy_r = 255;
		e->psy_g = 128;
		e->psy_b = 0;
	}
	ft_psychedelic2(e, layer);
}

void		ft_outside(t_fractol *e)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (e->psy == 1)
	{
		ft_psychedelic1(e);
		r = e->psy_r;
		g = e->psy_g;
		b = e->psy_b;
	}
	else
	{
		r = (e->i * e->r / e->iter_max * e->depth);
		g = (e->i * e->g / e->iter_max * e->depth);
		b = (e->i * e->b / e->iter_max * e->depth);
	}
	e->data[(((int)e->y * WIDTH + (int)e->x) * 4) + 2] = r;
	e->data[(((int)e->y * WIDTH + (int)e->x) * 4) + 1] = g;
	e->data[(((int)e->y * WIDTH + (int)e->x) * 4)] = b;
}

void		ft_inside(t_fractol *e)
{
	if (e->depth == 256 && e->psy == 0)
	{
		e->data[(((int)e->y * WIDTH + (int)e->x) * 4) + 2] = e->r;
		e->data[(((int)e->y * WIDTH + (int)e->x) * 4) + 1] = e->g;
		e->data[(((int)e->y * WIDTH + (int)e->x) * 4)] = e->b;
	}
	else
	{
		e->data[(((int)e->y * WIDTH + (int)e->x) * 4) + 2] = 0;
		e->data[(((int)e->y * WIDTH + (int)e->x) * 4) + 1] = 0;
		e->data[(((int)e->y * WIDTH + (int)e->x) * 4)] = 0;
	}
}
