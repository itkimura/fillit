/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:38:12 by itkimura          #+#    #+#             */
/*   Updated: 2022/02/07 15:03:55 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	test_printbitc(uint64_t	c)
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

void	test_print_tetris(uint64_t	c, size)
{
	uint64_t	bit;
	int			i;

	i = 0;
	bit = 1 << 15;
	while (i < 20)
	{
		if (c & bit)
			putchar('#');
		else
			putchar('.');
		bit >>= 1;
		i++;
		if (i % 5 == 0 && i > 0)
		{
			bit <<= 21;
			printf("............\n");
		}
	}
}

void	test_print_map(uint64_t	c)
{
	uint64_t	bit;
	int			i;

	i = 0;
	bit = 1 << 15;
	while (i < 64)
	{
		if (c & bit)
			putchar('1');
		else
			putchar('0');
		bit >>= 1;
		i++;
		if (i % 5 == 0 && i > 0)
		{
			bit <<= 21;
			putchar('\n');
		}
	}
}

void	test_print_list(t_tetri	*list)
{
	int	i;
	i = 0;

	while (list[i].value)
	{
		printf("No.%d: %p\n", i + 1, &list[i]);
		test_print_tetris(list[i].value);
		printf("value\t: ");
		test_printbitc(list[i].value);
		printf("letter\t: %c\n", list[i].letter);
		printf("width\t: %d\n", list[i].width);
		printf("height\t: %d\n", list[i].height);
		printf("list->pos: %d\n", list[i].pos);
		i++;
	}
}
