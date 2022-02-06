/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:38:12 by itkimura          #+#    #+#             */
/*   Updated: 2022/02/06 19:14:21 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	printbitc(uint64_t	c)
{
	uint64_t	bit;
	int			i;

	i = 0;
	bit = 1L << 63;
	while (bit != 0)
	{
		if (c & bit)
			putchar('1');
		else
			putchar('0');
		bit >>= 1;
		i++;
		if (i % 16 == 0)
			putchar(' ');
	}
	putchar('\n');
}

void	print_tetris(uint64_t	c)
{
	uint64_t	bit;
	int			i;

	i = 0;
	bit = 1L << 63;
	while (bit != 0)
	{
		if (c & bit)
			putchar('#');
		else
			putchar('.');
		bit >>= 1;
		i++;
		if (i % 16 == 0 && i > 0)
			putchar('\n');
	}
}

void	print_list(t_tetri	*list)
{
	int	i;
	i = 0;

	while (list[i].value)
	{
		printf("No.%d: %p\n", i + 1, &list[i]);
		print_tetris(list[i].value);
		printf("value\t: ");
		printbitc(list[i].value);
		printf("letter\t: %c\n", list[i].letter);
		printf("width\t: %d\n", list[i].width);
		printf("height\t: %d\n", list[i].height);
		printf("list->pos: %d\n", list[i].pos);
		printf("next\t: %p\n\n\n", list[i].next);
		i++;
	}
}
