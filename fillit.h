/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:05:32 by itkimura          #+#    #+#             */
/*   Updated: 2022/01/28 19:11:02 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
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

# endif
