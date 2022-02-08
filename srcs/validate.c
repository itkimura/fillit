/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:39:37 by itkimura          #+#    #+#             */
/*   Updated: 2022/02/08 15:43:48 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * Save width and height in struct
 * At the same time, move bitwise value to the left
*/
void	insert_value_w_h(const char	*buf, t_tetri	*p)
{
	int	i;
	int	min_width;

	i = 0;
	min_width = 3;
	p->height = 0;
	p->width = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			if (min_width > i % 5)
				min_width = i % 5;
			if (p->width < i % 5)
				p->width = i % 5;
		}
		if (i % 5 == 0 && ft_strnstr(&buf[i], "#", 4))
			p->height++;
		i++;
	}
	p->height--;
	p->value <<= min_width;
	p->width = p->width - min_width;
}

/*
 * Save the tetrimos in bitwise in struct
 * Move the tetrimo in the top
*/
void	get_piece_in_list(const char	*buf, t_tetri	*p)
{
	int			i;
	int			min_row;
	uint64_t	add;

	i = 0;
	add = 1 << 15;
	min_row = 3;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			p->value += add;
			if (i / 5 < min_row)
				min_row = i / 5;
		}
		if (buf[i] == '\n')
			add <<= 20;
		else
			add >>= 1;
		i++;
	}
	p->value >>= (min_row * 16);
	insert_value_w_h(buf, p);
}

int	validate(const char *buf, int count)
{
	int	i;
	int	sharp;
	int	counter;

	i = 0;
	sharp = 0;
	counter = 0;
	while (buf[i])
	{
		if ((i % 5 < 4 && i < 20 && buf[i] != '#' && buf[i] != '.')
			|| (i % 5 == 4 && buf[i] != '\n'))
			return (-1);
		if (buf[i] == '#')
		{
			sharp++;
			counter += (i / 5 != 0 && buf[i - 5] == '#');
			counter += (i / 5 != 3 && buf[i + 5] == '#');
			counter += (i % 5 != 0 && buf[i - 1] == '#');
			counter += (i % 5 != 3 && buf[i + 1] == '#');
		}
		i++;
	}
	if (sharp != 4 || (counter != 6 && counter != 8))
		return (-1);
	return (0);
}

int	read_tetri(const int fd, t_tetri *list)
{
	int		i;
	char	buf[22];
	int		count;
	char	alpha;

	i = 0;
	count = 1;
	alpha = 'A';
	if (fd < 0)
		return (-1);
	while (count)
	{
		count = read(fd, buf, 21);
		buf[count] = '\0';
		if (validate(buf, count) != 0)
			break ;
		if (count < 20 || i > 25)
			break ;
		get_piece_in_list(buf, &list[i]);
		list[i].letter = alpha++;
		if (count == 20)
			return (++i);
		i++;
	}
	return (-1);
}
