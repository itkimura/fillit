/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:33:45 by briffard          #+#    #+#             */
/*   Updated: 2022/01/21 13:30:52 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*INCLUDES*/
# include <fcntl.h>
# include <stdint.h>
# include "libft.h"
# include <stdio.h>

/*DEFINE*/
# define BUFF_SIZE 8

# define BLOCK '#'
# define EMPTY '.'
# define NEWLINE '\n'
# define MAX_SIZE 21



/*TYPEDEF*/
typedef struct	s_tetriminos
{
	char 					*tetriminos;
//	char					order;
//	int						position_horizontal;
//	int	 					position_verticale;
	struct s_tetriminos		*next;
}				t_tetri_list,*List;

/*Value of false = 0 and value of true = 1*/
typedef enum
{
	false,
	true
}	t_bool;

/*PROTOTYPES*/
List	newlist(void);
List	push_back_list(List li, char *shape);
void	print_list(List li);

t_bool	is_valid(char *tetriminos);
int		sidechecker(char *tetriminos, int index);

#endif