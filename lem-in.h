
#ifndef LEM_IN_H
#define LEM_IN_H

# include "libft/libft.h"

typedef struct			s_rooms
{
	char				*name;
	int					x;
	int 				y;
	int 				ant;
	int 				stat;
	int					lenmove;
	char 				*prev;
	struct s_rooms		*next;
}						t_rooms;

typedef struct			s_move
{
	char				*name;
	char 				*name_next;
	int 				stat;
	int					distance;
	struct s_move		*next;
}						t_move;

typedef struct			s_var
{
	t_move				*inst;
	t_rooms				*room;
	int 				ants;
	int					start;
}						t_var;

int						inst_cmp(char *s);
void					creat_list(char *s, t_var *var, int cmp);
int						read_instruction(t_var *var);
void					dijkstra(t_var *var);

#endif
