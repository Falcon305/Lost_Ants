/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:05:37 by hrazani           #+#    #+#             */
/*   Updated: 2020/02/16 23:10:22 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"

# define MIN(a,b) (((a)<(b))?(a):(b))
# define INT_MAX 2147483647
# define NO_MATCH 0
# define ANTS 1
# define COMMENT 2
# define COMMAND 3
# define START 4
# define END 5
# define ROOM 6
# define LINK 7
# define ANTS_ERROR -1
# define START_ERROR -4
# define END_ERROR -5
# define ROOM_ERROR -6
# define LINK_ERROR -7
# define NO_END -8
# define NO_START -9
# define ORDER_ERROR -10
# define END_OF_ROOMS -11

typedef struct			s_data
{
	int					id;
	char				*data;
	struct s_data		*next;
}						t_data;

typedef struct			s_stack
{
	int					data;
	struct s_stack		*next;
}						t_stack;

typedef struct			s_path
{
	t_stack				*path;
	int					len;
	int					reg;
	struct s_path		*next;
}						t_path;

typedef struct			s_group
{
	t_path				*path;
	int					score;
	int					n_paths;
	int					n_verts;
	struct s_group		*next;
}						t_group;

typedef struct			s_elt
{
	struct s_elt		*next;
	int					value;
}						t_elt;

typedef struct			s_queue
{
	t_elt				*head;
	t_elt				*tail;
}						t_queue;

typedef struct			s_cords
{
	int					x;
	int					y;
}						t_cords;

typedef struct			s_room
{
	char				*name;
	int					visited;
	int					type;
	int					blocked;
	int					parent;
	int					full;
	t_elt				*list;
	t_cords				cords;
}						t_room;

typedef struct			s_at
{
	int					id;
	t_stack				*room;
}						t_at;

typedef struct			s_graph
{
	int					nbr_verts;
	int					**cap;
	t_room				*verts;
	int					**adj;
	char				*line;
	int					start;
	int					end;
	int					valid;
	int					ants;
	int					ans;
	int					curr;
	t_at				*at;

}						t_graph;

typedef struct			s_algo
{
	t_stack				*path;
	t_group				*group;
	t_path				*pt;
	int					max_group;
}						t_algo;

typedef struct			s_bfs
{
	t_queue	*q;
	int		near;
	int		curr;
	t_elt	*list;
}						t_bfs;

/*
** *****************************************************************************
**								PARSSING FUNCTIONS
** *****************************************************************************
*/
void					ft_garbadge(char **str);
void					ft_init_list(t_data **head);
void					ft_add_list(t_data **head, int id, char *line);
void					ft_free_list(t_data *head);
void					ft_print_list(t_data *head);
int						ft_check_ants(t_data **head, char *line);
int						ft_check_command_comment(t_data **head, char *line);
int						ft_check_link(t_data **head, char *line);
int						ft_count_char(char *line, char c);
int						ft_checker_room_template(char *line);
int						ft_check_room(t_data **head, char *line, t_graph **g);
int						ft_checker(t_data **head, char *line,
		int i, t_graph *g);
int						ft_check_start_end(t_data **head, int *nbr_links);
int						ft_read_data(t_data **head, int *nbr_links, t_graph *g);
int						ft_binary_search(t_graph *g, int start, int end,
		char *room);
void					ft_is_start_end(t_graph *g, int i, int j);
void					ft_sort_rooms(t_graph *g);
int						ft_get_rooms_links(t_data **head, t_graph *g);
int						ft_parsing_data(t_graph *g, t_data **head);
void					ft_free_struct_pars(t_graph *g, t_data *head);
int						ft_fill_it(t_data **head, t_graph *g);
/*
** *****************************************************************************
**								QUEUE FUNCTIONS
** *****************************************************************************
*/
t_queue					*queue_create(void);
void					enq(t_queue *q, int value);
int						queue_empty(const t_queue *q);
int						deq(t_queue *q);
int						queue_destroy(t_queue *q);
/*
** *****************************************************************************
**								STACK FUNCTIONS
** *****************************************************************************
*/
void					init_stack(t_stack *head);
t_stack					*push(t_stack *head, int data);
t_stack					*pop(t_stack *head, int *element);
int						empty(t_stack *head);
int						stack_len(t_stack *path);
/*
** *****************************************************************************
**								PATH FUNCTIONS
** *****************************************************************************
*/
int						paths_len(t_path *path);
void					path_reg(t_path *path);
int						nodes_num(t_path *path);
void					init_g(t_group **head);
void					add_g(t_group **head, t_path *path, t_graph *g);
void					init_p(t_path **head);
void					add_p(t_path **head, t_stack *path);
void					free_p(t_path *head);
void					free_g(t_group *head);
void					free_links(t_graph *g);
/*
** *****************************************************************************
**								ALGO FUNCTIONS
** *****************************************************************************
*/
void					fill_capacity(t_graph *g);
void					blocked(t_graph *g);
void					visited(t_graph *g);
int						end_road(t_graph *g, int room);
t_group					*algo(t_graph *g, int s, int t);
void					adjust_capacity(t_graph *g, int node);
void					remove_link(t_graph *g, int node, int start);
void					reset_links(t_graph *g);
int						correct_path(t_graph *g, int s, int t);
t_stack					*construct_path(t_graph *g, int s, int t);
int						bfs_corr(t_graph *g, int s, int t);
t_stack					*bfs_path(t_graph *g, int s, int t);
void					reset_visited(t_graph *g);
int						calc_score(t_graph *g, int paths, int nodes);
void					build_list(t_graph *g);
/*
** *****************************************************************************
**								INSTRUCTIONS FUNCTIONS
** *****************************************************************************
*/
void					output(t_graph *g, int s, int t, t_data *data);
t_at					*make_at(int nbr);
void					ant_distrib(t_graph *g, t_group group);
void					move_ants(t_graph *g);
int						start_end(t_graph *g);
void					print_special(t_graph *g);
#endif
