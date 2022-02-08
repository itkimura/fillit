/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:42:55 by itkimura          #+#    #+#             */
/*   Updated: 2022/02/08 12:34:56 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * Attempts to find solution given size.
 * Save final position of each "solved" tetrimino reletive to size
*/

int	backtrack(t_tetri *list, int size, uint16_t *map)
{
	int	x;
	int	y;

	if (list->value == 0)
		return (-1);
	y = 0;
	while (list->height + y < size)
	{
		x = 0;
		while (list->width + x < size)
		{
			if (!(*(uint64_t *)(map + y) & list->value >> x))
			{
				*(uint64_t *)(map + y) ^= (list->value >> x);
				list->pos = x + (y * size);
				if (backtrack(list + 1, size, map))
					return (1);
				*(uint64_t *)(map + y) ^= (list->value >> x);
			}
			x++;
		}
		y++;
	}
	return (0);
}

/*
.* Finds minimum starting size based on number of tetriminos
 * size -> the smallest possible size of square
 * Updates size untill solution is found
*/

int	solve(t_tetri *list, const int number_of_piece, uint16_t *map)
{
	int	size;

	size = 2;
	while (size * size < number_of_piece * 4)
		size++;
	ft_bzero(map, sizeof(uint16_t) * 16);
	while (!backtrack(&list[0], size, map))
	{
		ft_bzero(map, sizeof(uint16_t) * 16);
		size++;
	}
	return (size);
}

/*
 * Filling map(str) according to backtrack result
 * list->pos hold the position of map for each tetorimo
 */
void	print_map(t_tetri	*list, int size, char *str)
{
	uint64_t	bit;
	int			count;
	int			i;

	while (list->value)
	{
		i = 0;
		bit = 1 << 15;
		count = list->pos;
		while (i < 64)
		{
			if (i % 16 < size)
			{
				if (bit & list->value)
					str[count] = list->letter;
				count++;
			}
			if (i % 16 < 15)
				bit >>= 1;
			if (i % 16 == 15)
				bit <<= 31;
			i++;
		}
		list++;
	}
}

/*
 * Make the empty str bu strnew and chage all char to '.'
 * Print map and del malloc
*/
void	print_result(t_tetri *list, int size)
{
	int		i;
	char	*str;

	str = ft_strnew(size * size);
	ft_memset(str, '.', size * size);
	print_map(list, size, str);
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		if ((i + 1) % size == 0 && i > 0)
			ft_putchar('\n');
		i++;
	}
	ft_strdel(&str);
}
