/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 09:23:30 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/09 16:33:36 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	COREWAR_H

# define COREWAR_H

# include "libft.h"
# include "op.h"
# include <stdlib.h>

typedef struct			s_player
{
	int					id;
	int					code_size;
	char				*name;
	char				*comment;
	char				*code;
	size_t				current_num_lives;	// number of reports that player is alive during current cycles_to_die period
	size_t				previous_num_lives; // number of reports that player is alive during previous cycles_to_die period
	ssize_t				last_live;			// cycle's number, on which player was assigned as alive last time
	struct	s_player	*next;

}						t_player;

typedef	struct			s_coach
{
	char				op_hash;
	unsigned int		carry : 1;
	unsigned int		id;
	unsigned int		step; 				// number of bytes to shift
	unsigned int		cycles_to_wait;
	ssize_t				last_live;			// cycle's number when live operator was executed last time
	char				arg_type[3];		// types of op's each argument before operator execution
	int					pc;					// address of the next operator to execute at memory (change name of var)
	int					reg[REG_NUMBER];
	t_player			*player;			// owner
	struct	s_coach		*next;

}						t_coach;

typedef struct			s_cw
{
	char				map[MEM_SIZE];
	t_player			player[MAX_PLAYERS];
	size_t				amt_players;
	t_player			*last_player;
	t_coach				*coach;
	size_t				amt_coaches;
	ssize_t				cycles;				// number of cycles that was passed after start
	ssize_t				cycles_to_die;		// game param
	ssize_t				cycles_after_check;	// number of cycles that was passed after last rules check
	size_t				checks_num;			// game param
	bool				isdump;
	size_t				dump_cycle;
}						t_cw;

void					abort(char *s);
void                    print_help(void);
void					parse_flags(int	argc, char **argv, t_cw *cw);
t_cw					*initializer_cw(void);

#endif
