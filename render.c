#include "sources/fb_stats.h"

void	clear_image(t_image *image)
{
	ft_bzero(image->ptr, WIN_WIDTH * WIN_HEIGHT * image->bpp);
}

void	render(t_mlx *mlx, t_player *players)
{
	int			x;
	int			y;

	clear_image(mlx->image);
	mlx_put_image_to_window(mlx->mlxptr, mlx->window, mlx->image->image, 0, 0);
}
