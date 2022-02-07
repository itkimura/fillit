/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:05:32 by itkimura          #+#    #+#             */
/*   Updated: 2022/02/07 16:24:48 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

# define MAX_TETRI 26

typedef struct s_tetri{
	uint64_t	value;
	char		letter;
	int			pos;
	int			width;
	int			height;
}				t_tetri;

void	print_result(t_tetri *list, int size);
int		solve(t_tetri *list, const int number_of_piece, uint16_t *map);
int		read_tetri(const int fd, t_tetri *list);

//test
# include <stdio.h>
void	test_printbitc(uint64_t	c);
void	test_print_tetris(uint64_t	c);
void	test_print_map(uint16_t	*map, int size);
void	test_print_list(t_tetri	*list);

#endif
