/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:32:49 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/10 20:56:50 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

inline static void	log_add(uint32_t cursor_id,
							int32_t r1_id,
							int32_t r2_id,
							int32_t r3_id)
{
	ft_printf("P %4d | add r%d r%d r%d\n", cursor_id, r1_id, r2_id, r3_id);
}

void				add(t_vm *vm, t_cursor *cursor)
{
	int32_t	r1_id;
	int32_t	r2_id;
	int32_t	r3_id;
	int32_t	value;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	r1_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->step += REG_LEN;
	r2_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->step += REG_LEN;
	value = cursor->reg[INDEX(r1_id)] + cursor->reg[INDEX(r2_id)];
	cursor->carry = (t_bool)(!value);
	r3_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->reg[INDEX(r3_id)] = value;
	cursor->step += REG_LEN;
	if (vm->log & OP_LOG)
		log_add(cursor->id, r1_id, r2_id, r3_id);
}
