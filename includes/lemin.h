/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:41:41 by lmabaso           #+#    #+#             */
/*   Updated: 2018/09/05 09:54:18 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/libft.h"

typedef struct		s_string
{
	char			*str;
	struct s_string	*next;
}					t_string;

typedef struct		s_co
{
	int				x;
	int				y;
}					t_co;

typedef struct		s_room
{
	char			*room_num;
	t_co			pos;
	double			f;
	double			g;
	double			h;
	t_string		*neighbours;
	struct s_room	*previous;
}					t_room;

typedef struct		s_node
{
	size_t			index;
	t_room			data;
	struct s_node	*next;
}					t_node;

typedef struct		s_data
{
	int				nb_ants;
	char			*start;
	char			*end;
	t_node			*cells;
	t_string		*tubs;
	int				fstart;
	int				fend;
}					t_data;

typedef struct		s_ant
{
	char			*ant_name;
	struct s_string	*room;
}					t_ant;

typedef struct		s_colony
{
	t_ant			ant;
	struct s_colony	*next;
}					t_colony;

typedef struct		s_astar
{
	t_string		*path_to_finish;
	t_node			*open_set;
	t_node			*closed_set;
	t_node			*current;
	t_node			*tmp;
	t_room			*neighbour;
	double			tmp_g;
	t_node			*winner;
	t_room			element;
	t_string		*tmp_nei;
}					t_astar;

void				ft_add_neigbour(t_node **head, char *room, char *neighbour);
t_node				*ft_find_room(t_node *head, char *room);
int					ft_search(t_string *str, char *to_find);

void				ft_append(t_node **head, char *new_data);
void				ft_append_data(t_node **head, t_room new_data);
void				ft_append_string(t_string **head, char *new_data);
int					ft_search_node(t_node *head, char *x);
void				ft_show_input(t_string *input);

void				delete_str(t_string **head_ref, char *key);
void				delete_node(t_node **head_ref, char *key);

t_string			*ft_astar(t_data *c, t_node *map);
void				ft_get_room(t_node **head, char *room);
void				ft_add_coordinates(t_node **head, t_node *rooms, char *str);

double				ft_get_distance(t_co a, t_co b);

void				ft_node_str_free(t_string **head);
void				ft_reverse(t_string **head_ref);

t_string			*copy_string(t_string *l1);
t_node				*ft_node_dup(t_node *l1);

size_t				ft_lst_node_len(t_node *head);
size_t				ft_lst_str_len(t_string *head);
void				ft_node_free(t_node **head);

int					ft_same_co(t_node *room);
int					ft_is_only_space(char *str);
int					ft_dup(t_string *input);

void				ft_remove_ants_at_end(t_colony **ants_in_maize, t_data *c);
void				ft_delete_ant(t_colony **head_ref, char *key);
void				ft_free_map(t_node **map);
void				ft_node_free2(t_node **head);
void				ft_node_str_free(t_string **head);

int					ft_error_handle(t_string **input);
int					ft_err_pipes(t_string *tmp, t_string **input);
int					ft_is_not_eof(t_string *tmp);
int					ft_first_check(t_string **tmp);

void				ft_process_input(t_string *input, t_data *c);
void				ft_creat_links(t_node **map, t_data *c);

void				ft_trans_ant(t_colony **head, t_colony *new_data);
void				ft_append_ant(t_colony **head, char *new_data);
t_colony			*ft_get_ants(t_data *c);
void				ft_get_moving(t_ant mr_ant);
void				ft_move_ants(t_string *route, t_data *c);

void				ft_assign_routs(t_colony *ants, t_string *da_wae);
t_colony			*ft_pop(t_colony **head);
void				ft_push_to(t_colony **dest, t_colony **src);
void				ft_move_ants_in_maize(t_colony **ants);
void				ft_display(t_colony *ants);

int					ft_bouncer(t_colony *ft_move_ants_in_maize, char *room);
void				ft_print_error(t_data *c);
int					ft_err_room(t_string *tmp);
int					ft_cont_check(t_string	*tmp, t_string **input);
int					ft_is_not_eof(t_string *tmp);
#endif
