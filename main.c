/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:38:41 by itkimura          #+#    #+#             */
/*   Updated: 2022/01/24 23:22:54 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
 * size[0] = min_height;
 * size[1] = max_height;
 * size[2] = min_width;
 * size[3] = max_width;
*/

int	test_size(const char *buf, int	*size, t_tetri *tetris)
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


int	check_connection(const char	*buf, int	i)
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

int	validate(const char	*buf, int count)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (buf[i])
	{
		if ((buf[i] != '#' && buf[i] != '.' )&& (i % 5) != 4)
			return (-1);
		if (buf[i] != '\n' && (i % 5) == 4)
			return (-1);
		if (buf[i] == '#')
			count += check_connection(buf, i); 
		i++;
	}
	if ((count == 21 && str[20] != '\n') || (count != 6 || count != 8))
		return (-1);
	return (0);
}

/*
 * buffer -> 21 ((4 + \n ) * 4 + EOF)
*/

int	read_tetri(const int fd, t_tetris *tetris)
{
	int	i;
	char	buf[22];
	int count;

	i = 0;
	if (fd < 0)
		return (-1);
	while (1)
	{
		count = read(fd, buf, 21);
		if (validate(buf, count) != 0)
			return (-1);
		tetris[i] = get_tetri(buf);
		j = i - 1;
		while (j >= 0)
		{
			if (tetris[i].value == tetris[i].value)
				tetris[i].next = tetris + j;
			j--;
		}
		i++;
		if (count < 20)
			break ;
	}
	if (count != 0)
		return (-1);
	return (0);
}

int	error(char *str)
{
	ft_putendl(str);
	return (1);
}

/*
 * count -> how many tetrimos are given.
 * map -> bitwise map for DP
 * size -> the smallest possible size of square
 */

int	main(int	argc, char	**argv)
{
//	uint16_t	map[16]; 
	t_tetri	tetris[MAX_TETRI + 1];

	if (argc != 2)
		return (error("usage: fillit input_file"));
	if (read_tetri(open(argv[1], O_RDONLY), tetris) != 0)
		return (error("error"));
	else
		printf("success");
	return (0);
}
