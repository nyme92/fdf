
#ifndef FDF_H
# define FDF_H
# define PI 3.14159265359
# include "colors.h"
# include "keycode_mac.h"
# include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include<unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "mlx.h"
#include "libft/libft.h"
# define WIN_X 1000
# define WIN_Y 1000
# define CZ 0xFFFFFF
# define CX 0x0E50BA
# define CC 0xC60707
# define CV 0x8c0fc6
# define CB 0xe8930b
# define CN 0x04963e

//typedef struct			s_vector3 t_vec;

typedef struct			s_point
{
	int					z;
	int					z0;
	int					xp;
	int					yp;
}						t_point;

typedef struct			s_vec
{

	double					x;
	double					y;
	double                 z;
	int                     c;
	//int                 maxx;
	//int                    maxy;

}                       t_vec;

typedef struct			s_map
{

t_vec			size;
int                 **mat;
double              tile;
double              scale;
}						t_map;

typedef struct		s_size
{
	int		x;
	int		y;
}
					t_size;



typedef struct			s_env
{
//	t_vec          point;
//	t_vec          point2;
	int                 x;
	int                 y;
	int                 ptct;
	//t_coord				coord;
	t_map				map;
	void				*mlx;
	void				*win;
	//t_coord				scale;
	int					height;
	int					width;
	//t_coord				pos;
	int					alt;
	size_t				smallest;
	int					count_line;
	int					color;
}						t_env;
//static void		draw_line(t_env *e, t_coord src, t_coord dst);

t_vec  g_offset;

t_vec			fdf_project(t_vec p, t_env *e);
int         main(int argc, char **argv);
int        fdf_keyhook(int key, t_env *e);
void		parse(char *filepath, t_env *e);
void	splitline(char *str,int y,  t_env *e);
void		draw(t_env *e);
void        draw_points(t_vec *a, t_vec *b, t_env *e);
void		dda(t_vec *start, t_vec *end, int color, t_env *e);
void        dunk(t_env *e);
void					check_args(int ac);
void					parse_args(char *filepath, t_env *env);
void					read_args(char *filepath, t_env *env);
void					exit_error(int c);
void					apply_proj(t_env *env);
void					apply_height(t_env *e, int c);
void					draw_lines(t_env *env, int x, int y);
void					pixel_put(t_env *e, int x, int y, int color);
void					draw_again(t_env *e);
int						event_mouse(int button, int x, int y, t_env *env);
int						event_key(int keycode, t_env *env);
int			check_error(int argc, char **argv);
int			get_map_size(t_env *e, char *argv);
void		mlx_check_putpixel(t_env *e, int x, int y, int c);
#endif
