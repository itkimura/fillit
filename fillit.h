/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:05:32 by itkimura          #+#    #+#             */
/*   Updated: 2022/02/06 19:49:14 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"

# define MAX_TETRI 26
typedef struct	s_tetri t_tetri;

struct s_tetri{
	uint64_t	value;
	char	letter;
	int		pos;
	int		min_width;
	int		width;
	int		height;
	t_tetri	*next;
};

void	print_map(t_tetri	*list, int size);
int	solve(t_tetri *list, const int number_of_piece, uint16_t *map);
int	read_tetri(const int fd, t_tetri *list);

//test
void	print_list(t_tetri	*list);
void	printbitc(uint64_t	c);

# endif
