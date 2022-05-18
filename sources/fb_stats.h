#ifndef		FB_STATS_H
# define	FB_STATS_H

#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"

# define WIN_WIDTH 720
# define WIN_HEIGHT 360

# include "mlx.h"
# include "fb_stats.h"

# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <X11/keysym.h>

typedef struct	s_player
{
	int		line_index;
	int		lst_index;
	//int		rank;
	char	*name;
	//char	*nation;
	char	*position;
	//char	*squad;
	int		age;
	//char	*born;
	//int		mp;
	//int		starts;
	int			minutes;
	//int		ninetys;
	int			goals;
	int		assists;
	struct	s_player		*next;
	struct	s_player		*previous;
	struct	s_player		*current;
}				t_player;

typedef struct		s_top10
{
	t_player		*player;
	struct s_g10	*next;
	
}					t_top10;

/*typedef struct	s_p_lst
{
	t_player		*player;
	struct s_list	*next;
	struct s_list	*previous;
}				t_p_lst;*/


typedef struct		s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			line_bytes;
	int			endian;
}					t_image;

/*typedef struct		s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
}					t_mouse;*/

typedef struct		s_mlx
{
	void		*mlxptr;
	void		*window;
	t_player	*players;
	t_image		*image;
	double		**zbuf;
}					t_mlx;

void		usage(char *reason);
int			ft_is_ext_ascii(int c);

int			save_position(char *line, int i, int len, t_player *player);
char		*save_char(char *line, int i, int len, t_player *players);
int			save_integer(char *line, int i, int len, t_player *players);
int			skip_column(char *line, int i, int n);
t_player	*parse_stats(char	*line, t_player *player);
size_t		ft_playercount(t_player *lst);

void		output_stats(char	*av2, t_player *head);
char		*output_type(char	*av2);


void		ft_assists(t_player *player_list);
void		ft_goals(t_player *player_list);
void		ft_most_mins(t_player *player_list);
void		ft_goals_per_90(t_player *player_list);
void		ft_goals_and_assists(t_player *player_list);


void		ft_goals_min(t_player *player_list);
void		ft_assists_min(t_player *player_list);
void		ft_goals_and_assists_min(t_player *player_list);
void		ft_age_goals_and_assists_min(t_player *player_list);
void		ft_goals_top_10(t_player *player_list, int max, int count);
void		ft_assists_top_10(t_player *player_list, int max, int count);

int			main2(t_player *players, char *arg2);
void		render(t_mlx *mlx, t_player *players);

#endif