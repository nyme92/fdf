#include "fdf.h"
void		draw_points(t_vec *a, t_vec *b, t_env *e)
{
	t_vec point;
	t_vec point2;

	point = fdf_project(*a, e);
	point2 = fdf_project(*b, e);
	if ((int)a->z != (int)b->z)
		dda(&point, &point2, \
				RED - ((fmax(a->z, b->z) - fmin(a->z, b->z)) * 150), e);
	else
		dda(&point, &point2, point.c, e);
}

/*t_vec			fdf_project(t_vec p, t_env *e)
{
	t_vec t_a;
	int meow;
	p.c =  RED - p.z * 150;
	p.x -= (e->map.size.x / 2);
	p.y -= (e->map.size.y / 2);
	p.z *= e->map.scale;
	t_a = mlx_rotate(&p);
	t_a.x = (double)((WIN_X / 2)) + (t_a.x * e->map.tile);
	t_a.y = (double)((WIN_Y / 2)) + (t_a.y * e->map.tile);
	return (t_a);
}*/
