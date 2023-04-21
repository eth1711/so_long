/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:02:01 by etlim             #+#    #+#             */
/*   Updated: 2023/04/21 20:45:55 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "ANTOINE!");
// 	mlx_loop(mlx);
// }

// int	main(void)
// {
// 	void	*img;
// 	void	*mlx;

// 	mlx = mlx_init();
// 	img = mlx_new_image(mlx, 1920, 1080);
// }

// int	main(void)
// {
// 	void	*mlx;
// 	t_data	img;

// 	mlx = mlx_init();
// 	img.img = mlx_new_image(mlx, 1920, 1080);

// // 	/*
// // 	** After creating an image, we can call `mlx_get_data_addr`, we pass
// // 	** `bits_per_pixel`, `line_length`, and `endian` by reference. 
// These will
// // 	** then be set accordingly for the *current* data address.
// // 	*/
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// }

// void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
// {
// 	char	*dst;

// 	img->addr = mlx_get_data_addr(img->img, img->)

//  	dst = data->addr + (y * data->line_length + x * 
// (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	void	*mlx_img;
// 	int		width = 800;
// 	int		height = 600; 
// 	// t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "My Map");
// 	// img.img = mlx_new_image(mlx, 1920, 1080);
// 	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
//  &img.line_length,
// 	// 							&img.endian);
// 	mlx_img = mlx_xpm_file_to_image(mlx, "picture.xpm", &width, &height);
// 	// my_mlx_pixel_put(&img, 100, 100, 0x00FFFF00);
// 	// my_mlx_pixel_put(&img, 101, 100, 0x00FFFF00);
// 	// my_mlx_pixel_put(&img, 102, 100, 0x00FFFF00);
// 	// my_mlx_pixel_put(&img, 103, 100, 0x00FFFF00);
// 	// my_mlx_pixel_put(&img, 104, 100, 0x00FFFF00);
// 	// my_mlx_pixel_put(&img, 105, 100, 0x00FFFF00);
// 	// my_mlx_pixel_put(&img, 106, 100, 0x00FFFF00);
// 	// my_mlx_pixel_put(&img, 107, 100, 0x00FFFF00);
// 	// my_mlx_pixel_put(&img, 108, 100, 0x00FFFF00);
// 	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_put_image_to_window(mlx, mlx_win, mlx_img, 600, 300);
// 	mlx_loop(mlx);
// }