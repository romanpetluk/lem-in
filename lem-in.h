
#ifndef LEM_IN_H
#define LEM_IN_H

# include "libft/libft.h"

typedef struct			s_rooms
{
	char				*name;
	int					x;
	int 				y;
	int 				stat;
	int					start;
	int					lenmove;
	struct s_rooms		*prev;
	struct s_rooms		*next;
}						t_rooms;

typedef struct			s_move
{
	char				*name;
	char 				*name_next;
	//int 				stat;
	int					distance;
	struct s_move		*next;
}						t_move;

typedef struct			s_var
{
	t_move				*moves;
	t_rooms				*rooms;
	int 				ants;
	int					start;
	int					error;
	int					grup_valid;
	int					start_count;
	int					end_count;
}						t_var;

typedef struct			s_way
{
	int 				stat;
	int					distance;
	t_rooms				*room;
	struct s_way		*next_room;
	struct s_way		*next_way;
}						t_way;

int						read_instruction_ants(char *s, t_var *var);

int						read_instruction_room(char *s, t_var *var);
int						ft_newlist_room(char **s, t_rooms **room, int comand);

int						read_instruction_move(char *s, t_var *var);
int						ft_newlist_move(t_move **moves, char *r_name1, char *r_name2);

int						ft_atoi_lem(char *str);
void					free_fail(char **split);

int						ft_newlist_way(t_way **way);

int						read_instruction(t_var *var);
int						algorithm(t_var *var);

#endif
