/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 15:06:03 by lchappon          #+#    #+#             */
/*   Updated: 2018/08/19 17:58:29 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_event(t_fractol *e)
{
	mlx_key_hook(e->win, ft_deal_key, e);
	mlx_mouse_hook(e->win, ft_deal_mouse, e);
	mlx_hook(e->win, 6, 0, ft_julia_mouse, e);
}

void		ft_init(t_fractol *e)
{
	e->x1 = WIDTH;
	e->y1 = HEIGHT;
	e->zoom = 300;
	e->iter_max = 50;
	e->r = 255;
	e->g = 255;
	e->b = 255;
	e->depth = 1;
	e->julia_move = 1;
	e->info = 0;
	e->psy = 0;
}

void		ft_mlx(t_fractol *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "fractol");
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_l), &(e->endian));
	ft_init(e);
	ft_draw(e);
	ft_event(e);
	mlx_loop(e->mlx);
}

void		ft_usage(void)
{
	ft_putendl("usage: ./fractol <mandelbrot | julia | burningship | douady>");
}

int			main(int argc, char **argv)
{
	t_fractol	e;
	char		*param;

	e.fractal = 0;
	if (argc == 2)
	{
		param = ft_strtrim(argv[1]);
		ft_strtolower(param);
		if (!ft_strcmp(param, "mandelbrot"))
			e.fractal = 1;
		else if (!ft_strcmp(param, "julia"))
			e.fractal = 2;
		else if (!ft_strcmp(param, "burningship"))
			e.fractal = 3;
		else if (!ft_strcmp(param, "douady"))
			e.fractal = 4;
		free(param);
		if (e.fractal)
			ft_mlx(&e);
		else
			ft_usage();
	}
	else
		ft_usage();
	return (0);
}
