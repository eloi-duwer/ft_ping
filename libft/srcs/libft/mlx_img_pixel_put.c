/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_pixel_put.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:31:43 by eduwer            #+#    #+#             */
/*   Updated: 2016/12/13 13:17:38 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	mlx_img_pixel_put(char *pt_img, int size_line, int coord[2], int color)
{
	int				i;
	unsigned char	*color_pt;

	pt_img += (size_line * coord[1]) + (coord[1] * 4);
	color_pt = (unsigned char *)&color;
	i = 0;
	while (i < 3)
	{
		*pt_img = *color_pt;
		pt_img++;
		color_pt++;
		i++;
	}
}
