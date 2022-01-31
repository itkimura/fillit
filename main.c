/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:38:41 by itkimura          #+#    #+#             */
/*   Updated: 2022/01/31 12:12:35 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
 * size[0] = min_height;
 * size[1] = max_height;
 * size[2] = min_width;
 * size[3] = max_width;


int	get_size(const char *buf, int	*size, t_tetri *list)
{
	int	i;

	size[0] = 3;
	size[1] = 0;
	size[2] = 3;
	size[3] = 0;
	i = 0;
	while (i < 10)
	{
		if (buf[i] == '#')
		{
			if (i % 5 < size[0]) 
				size[0] = i % 5;
			if (i % 5 > size[1]) 
				size[1] = i % 5;
			if (i / 5 < size[0]) 
				size[0] = i / 5;
			if (i / 5 > size[0]) 
				size[0] = i / 5;
		}
		i++;
	}
}
*/

void	printbitc(uint64_t	c)
{
	uint64_t	bit;
	int			i;

	i = 0;
	bit = 1 << 15;
	while (bit != 0)
	{
		if (c & bit)
			putchar('1');
		else
			putchar('0');
		bit >>= 1;
		i++;
		if (i % 4 == 0)
			putchar(' ');
	}
	putchar('\n');
}

void	print_tetris(uint64_t	c)
{
	uint64_t	bit;
	int			i;

	i = 0;
	bit = 1 << 15;
	while (bit != 0)
	{
		if (c & bit)
			putchar('#');
		else
			putchar('.');
		bit >>= 1;
		i++;
		if (i % 4 == 0 && i > 0)
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
		printf("height: %d\n", list[i].height);
		printf("next\t: %p\n\n\n", list[i].next);
		i++;
	}
}
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
			if(min_width > i % 5)
				min_width = i % 5;
			if (p->width < i % 5)
				p->width = i % 5;
		}
		if (i % 5 == 0 && ft_strnstr(&buf[i], "#", 4))
			p->height++;
		i++;
	}
	p->value <<= min_width;
	p->width = p->width - min_width + 1;
}

void	get_piece_in_list(const char	*buf, t_tetri	*p)
{
	int	i;
	int	j;
	int	add;

	i = 0;
	add = 1 << 15;
	p->value = 0;
	while (i < 20)
	{
		j = 0;
		if (i % 5 == 0 && ft_strnstr(buf + i, "#", 4))
		{
			while (j < 4)
			{
				if (buf[i + j] == '#')
					p->value += add;
					add /= 2;
				j++;
			}
		}
		i += j + 1;
	}
	insert_value_w_h(buf, p);
}

int	check_connection(const char *buf, int i)
{
	int	count;

	count = 0;
	if (i >= 1 && buf[i - 1] == '#')
		count++;
	if (i < 19 && buf[i + 1] == '#')
		count++;
	if (i >= 5 && buf[i - 5] == '#')
		count++;
	if (i < 15 && buf[i + 5] == '#')
		count++;
	return (count);
}

int	validate(const char *buf, int count)
{
	int	i;
	int	connection_count;

	i = 0;
	connection_count = 0;
	while (i < 20)
	{
		if ((buf[i] != '#' && buf[i] != '.' ) && (i % 5) != 4)
		{
			printf("2.error\n");
			return (-1);
		}
		if (buf[i] != '\n' && (i % 5) == 4)
		{
			printf("3.error\n");
			return (-1);
		}
		if (buf[i] == '#')
			connection_count += check_connection(buf, i);
		i++;
	}
	if ((count == 21 && buf[20] != '\n')
		|| (connection_count != 6 && connection_count != 8))
	{
		printf("4.error count = %d, buf[20] = %c, connection_count = %d\n%s", count, buf[20], connection_count, buf);
		return (-1);
	}
	return (0);
}

/*
 * buffer -> 21 ((4 + \n ) * 4 + EOF)
*/

int	read_tetri(const int fd, t_tetri *list)
{
	int		i;
	int		j;
	char	buf[22];
	int		count;
	char	alpha;

	i = 0;
	j = 0;
	alpha = 'A';
	if (fd < 0)
		return (-1);
	while (1)
	{
		count = read(fd, buf, 21);
		if (count < 20)
			break ;
		if (validate(buf, count) != 0)
			return (-1);
		get_piece_in_list(buf, &list[i]);
		list[i].letter = alpha++;
		j = i - 1;
		while (j >= 0)
		{
			if (list[j].value == list[i].value)
			{
				printf("i = %d, j = %d\n", i, j);
				list[i].next = list + j;
			}
			j--;
		}
		i++;
	}
	if (count != 0)
		return (-1);
	return (alpha - 'A');
}



/*
 * Attempts to find solution given size.
 * Save final position of each "solved" tetrimino reletive to size
*/

int	backtracking(t_tetri	*list, int	size, uint16_t	*map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	if (list->value == 0)
		return (-1);
	list->y = pos / size;
	printf("pos = %d\n", pos);
/*	while (list->height + y < size)
	{
		x = 0;
		while (lost->width + x < size)
		{
			if (!(*(uint64_t *)(map + y == pos / size ? pos % size : 0);
		}
	}
*/
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
	(void)list;
	while (!backtracking(list, size, map))
	{
		ft_bzero(map, sizeof(uint16_t) * 16);
		size++;
	}
	printf("number_of_piece = %d, size = %d map = %d\n", number_of_piece, size, map[0]);
	return (size);
}

char	*empty_map(int	size)
{
	char	*str;
	int		x;
	int		y;

	str = ft_strnew((size + 1) * (size));
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			str[y * (size + 1) + x] = '.';
			x++;
		}
		str[y * (size + 1) + x] = '\n';
		y++;
	}
	return (str);
}

void	print_map(t_tetri	*list, int	number_of_piece, int size)
{
	char	*str;
/*
	int		x;
	int		y;
*/
	str = empty_map(size);
/*
	while (number_of_piece > 0)
	{
		y = 0;
		while (y < t->height)
		{
			x = 0;
			while (x < t->width)
			{
				if((t->value >> (16 * (y + 1) - 1 - x)) & 1)
					str[(t->y + y) * (size + 1) + x + t->x] = t->letter;
				x++;
			}
			y__;
		}
		list++;
		number_of_piece--;
	}
*/
	(void)list;
	(void)number_of_piece;
	ft_putstr(str);
	ft_strdel(&str);
}

int	error(char *str)
{
	ft_putendl(str);
	return (1);
}

int	main(int argc, char **argv)
{
	t_tetri	list[MAX_TETRI + 1];
	uint16_t	map[16];
	int		number_of_piece;
	int		size;

	ft_bzero(list, sizeof(t_tetri) * (MAX_TETRI + 1));
	if (argc != 2)
		return (error("usage: fillit input_file"));
	number_of_piece = read_tetri(open(argv[1], O_RDONLY), list);
	if (number_of_piece < 0)
		return (error("error"));
	print_list(list);
	ft_bzero(map, sizeof(uint16_t) * 16);
	size = solve(list, number_of_piece, map);
	if (size == 0)
		return (error("error"));
	print_map(list, number_of_piece, size);
	return (0);
}
