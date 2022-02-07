/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:39:37 by itkimura          #+#    #+#             */
/*   Updated: 2022/02/07 11:27:28 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	printf("p->value = ");
	printbitc(p->value);
	p->value >>= (min_row * 16);
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
		if ((i % 5 != 4 && buf[i] != '#' && buf[i] != '.') || 
			(i % 5 == 4 && buf[i] != '\n'))
			return (-1);
		if (buf[i] == '#')
			connection_count += check_connection(buf, i);
		i++;
	}
	if ((count == 21 && buf[20] != '\n')
		|| (connection_count != 6 && connection_count != 8))
		return (-1);
	return (0);
}

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
		i++;
	}
	if (count != 0 || (count == 0 && list[0].value == 0))
		return (-1);
	return (alpha - 'A');
}
