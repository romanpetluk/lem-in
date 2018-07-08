
#ifndef LEM_IN_H
#define LEM_IN_H

# include "../libft/libft.h"

typedef struct			s_rooms
{
	char				*name;
	int					x;
	int 				y;
	int 				stat;
	int					lenmove;
	struct s_rooms		*prev;
	struct s_rooms		*next;
	//t_rooms				*room;
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
	int					error;
	int					grup_valid;
	int					start_count;
	int					end_count;
}						t_var;

int						read_instruction_ants(char *s, t_var *var);

int						read_instruction_room(char *s, t_var *var);
int						ft_newlist_room(char **s, t_rooms **room, int start);

int						read_instruction_move(char *s, t_var *var);
int						ft_newlist_move(char **s, t_move **inst);

int						ft_atoi_lem(char *str);
void					free_fail(char **split);


int						read_instruction(t_var *var);
int						algorithm(t_var *var);

#endif
