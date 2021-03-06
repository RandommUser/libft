/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phakakos <phakakos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:26:08 by phakakos          #+#    #+#             */
/*   Updated: 2020/02/19 20:06:27 by phakakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		floor(long num)
{
	if (num > 255)
		return (255);
	else if (num < 0)
		return (0);
	else
		return (num);
}

t_rgb			rgb_conv(long color)
{
	t_rgb	rtn;

	color = color > 0xffffff ? 0xffffff : color;
	color = color < 0 ? 0 : color;
	rtn.blue = color % 16;
	color = color / 16;
	rtn.blue = rtn.blue + color % 16 * 16;
	color = color / 16;
	rtn.green = color % 16;
	color = color / 16;
	rtn.green = rtn.green + color % 16 * 16;
	color = color / 16;
	rtn.red = color % 16;
	color = color / 16;
	rtn.red = rtn.red + color % 16 * 16;
	return (rtn);
}

int				rgb_color(unsigned int red, unsigned int green,
		unsigned int blue)
{
	red = floor(red);
	green = floor(green);
	blue = floor(blue);
	blue += green * 256;
	blue += red * 256 * 256;
	return (blue);
}

int				trgb_conv(t_rgb color)
{
	return (rgb_color(color.red, color.green, color.blue));
}
