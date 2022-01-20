/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:33:45 by briffard          #+#    #+#             */
/*   Updated: 2022/01/20 15:43:16 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*INCLUDES*/
# include <fcntl.h>
# include <stdint.h>
# include "libft.h"

/*DEFINE*/
# define BUFF_SIZE 8

# define BLOCK '#'
# define EMPTY '.'
# define NEWLINE '\n'
# define MAX_SIZE 20



/*TYPEDEF*/
typedef struct	s_tetriminos
{
	char 					*tetriminos;
//	char					order;
//	int						position_horizontal;
//	int	 					position_verticale;
	struct s_tetriminos		*next;
}				t_tetri_list,*List;

/*PROTOTYPES*/
List	newlist(void);
List	push_back_list(List li, char *shape);
void	print_list(List li);
#endif