
#ifndef LEM_IN_H
#define LEM_IN_H

# include "libft/libft.h"

# define ERROR_ANTS		"Not valid number of ants"
# define ERROR_L		"The room name can not begin with 'L'"
# define ERROR_LINE		"Empty line"
# define ERROR_MINUS	"The room name can not contain '-'"
# define ERROR_ROOM_ARG	"Not the correct number of arguments"
# define ERROR_COORD1	"Not valid first coordinate"
# define ERROR_COORD2	"Not valid second coordinate"
# define ERROR_ROOM_NAME	"Room with that name already exists"
# define ERROR_DUP_START	"Duplicate command start"
# define ERROR_DUP_END	"Duplicate command end"
# define ERROR_COM_ROOM	"The command should be followed by a room"
# define ERROR_NUMB_ANTS	"First enter the number of ants"
# define ERROR_COM_LINK	"This command is not used for links"
# define ERROR_LINK_ARG	"Not the correct number of arguments"
# define ERROR_LINK_FAIL	"Not a valid link"
# define ERROR_NOT_START	"No start room specified"
# define ERROR_NOT_END	"No end room specified"
# define ERROR_NOT_S_E	"There is 0 available paths"

typedef struct			s_rooms
{
	char				*name;
	int					x;
	int 				y;
	int 				stat;
	int					start;
	int					ants;
	int					lenmove;
	struct s_rooms		*prev;
	struct s_rooms		*next;
}						t_rooms;

typedef struct			s_move
{
	char				*name;
	char 				*name_next;
	int					distance;
	struct s_move		*next;
}						t_move;

typedef struct			s_txt
{
	char				*string;
	struct s_txt		*next;
}						t_txt;

typedef struct			s_way
{
	int 				ant;
	int					distance;
	t_rooms				*room;
	struct s_way		*next_room;
	struct s_way		*next_way;
}						t_way;

typedef struct			s_bonus
{
	int					count_line;
	int					error_key;
	int					error_line;
	int					way;
	int					count_iter;
}						t_bonus;

typedef struct			s_var
{
	t_move				*moves;
	t_rooms				*rooms;
	t_txt				*txt;
	t_bonus				bon;
	int 				ants;
	int					comand;
	int					error;
	int					grup_valid;
	int					start_count;
	int					end_count;
}						t_var;

int						read_instruction_ants(char *s, t_var *var);

int						read_instruction_room(char *s, t_var *var);
int						ft_newlist_room(char **s, t_rooms **room, int comand);

int						read_instruction_move(char *s, t_var *var);
int						ft_newlist_move(t_move **moves, char *r_name1, char *r_name2);

int						ft_atoi_lem(char *str, int n);
void					free_fail(char **split);
void					free_failn(char **split, int count);

int						ft_newlist_way(t_way **way, t_rooms *room);

int						read_instruction(t_var *var);
int						algorithm(t_var *var);
void					validate_instruction(t_var *var);
void					ants_move(int ants, t_way *way, int iter);

int						add_string_txt(char *s, t_txt **txt);
void					ft_errors(t_var *var);
int						remove_start_finish(t_rooms *room, t_move **move);
void					ft_bonus(t_var *var, int argc, char **argv);
void					ft_free_way(t_way *way, t_var *var);
void					way_list(t_way *way);

#endif
