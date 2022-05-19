#include "sources/fb_stats.h"

int		exit_with_esc(int key, t_mlx *mlx)
{
	(void)mlx;
	printf("%d\n", key);
	if (key == XK_Escape)
		exit(EXIT_SUCCESS);
	return (0);
}

void	print_error(char *reason)
{
	ft_putendl(reason);
	exit(EXIT_FAILURE);
}

t_image	*del_image(t_mlx *mlx, t_image *img)
{
	if (img != NULL)
	{
		if (img->image != NULL)
			mlx_destroy_image(mlx->mlxptr, img->image);
		ft_memdel((void **)&img);
	}
	return (NULL);
}

t_mlx		*mlxdel(t_mlx *mlx)
{
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlxptr, mlx->window);
/*	if (mlx->cam != NULL)
		ft_memdel((void **)&mlx->cam);
	if (mlx->mouse != NULL)
		ft_memdel((void **)&mlx->mouse);	*/
	if (mlx->image != NULL)
		del_image(mlx, mlx->image);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_image	*new_image(t_mlx *mlx)
{
	t_image		*img;

	if ((img = ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	if ((img->image = mlx_new_image(mlx->mlxptr, WIN_WIDTH, WIN_HEIGHT)) == NULL)
		return (del_image(mlx, img));
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->line_bytes,
			&img->endian);
	img->bpp /= 8;
	return (img);
}

t_mlx	*initialize_mlx(char *win_title)
{
	t_mlx	*mlx;

	mlx = ft_memalloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	printf("test\n");
	mlx->mlxptr = mlx_init();
	mlx->window = mlx_new_window(mlx->mlxptr, WIN_WIDTH, WIN_HEIGHT, win_title);
	mlx->image = new_image(mlx);
	if (mlx->mlxptr == NULL || mlx->window == NULL || mlx->image == NULL)
		return (mlxdel(mlx));
	return (mlx);
}

char	*ft_goals_mlx(t_player *player_list)
{
	int			ref;
	char		*leader;

	ref = 0;
	leader = NULL;
	while (player_list->next != NULL)
	{
		if (player_list->goals > ref)
		{
			ref = player_list->goals;
			leader = player_list->name;
		}
		if (player_list->next != NULL)
			player_list = player_list->next;
		if (player_list->next == NULL)
			break ;
	}
	return (ft_strjoin(leader, ft_itoa(ref)));
}

int	main2(t_player *players, char *arg2)
{
	t_mlx	*mlx;

	//output_stats_mlx(arg2, players);
	mlx = initialize_mlx("jalkapalli");
	if (mlx == NULL)
		print_error("Error; Cannot initialize mlx");
	mlx->players = players;
	render(mlx, players);
	if (ft_strcmp(arg2, "goals") == 0)
		mlx_string_put(mlx->mlxptr, mlx->window, WIN_WIDTH / 2, WIN_HEIGHT / 2, 0xFFFFFF, ft_goals_mlx(players));
	mlx_string_put(mlx->mlxptr, mlx->window, 20, 20, 0xFFFFFF, "Press 'ESC' for EXIT");
	mlx_key_hook(mlx->window, exit_with_esc, mlx);
	mlx_loop(mlx->mlxptr);
	return (0);
}
