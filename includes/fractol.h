/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 15:03:38 by lchappon          #+#    #+#             */
/*   Updated: 2018/08/19 17:11:14 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct		s_fractol
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				s_l;
	int				endian;
	unsigned int	i;
	unsigned int	iter_max;
	double			zr;
	double			zi;
	double			cr;
	double			ci;
	double			julia_cr;
	double			julia_ci;
	double			x;
	double			y;
	double			x1;
	double			y1;
	double			zoom;
	int				r;
	int				g;
	int				b;
	int				psy_r;
	int				psy_g;
	int				psy_b;
	int				depth;
	int				fractal;
	int				julia_move;
	int				info;
	int				psy;
}					t_fractol;

void				ft_draw(t_fractol *e);

void				ft_inside(t_fractol *e);
void				ft_outside(t_fractol *e);

void				ft_info(t_fractol *e);

int					ft_deal_key(int keycode, t_fractol *e);

int					ft_deal_mouse(int button, int x, int y, t_fractol *e);
int					ft_julia_mouse(int x, int y, t_fractol *e);

#endif
