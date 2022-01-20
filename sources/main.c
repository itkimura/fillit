/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:31:48 by briffard          #+#    #+#             */
/*   Updated: 2022/01/19 14:20:29 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*CHECK FOR VALID PIECES
 * lookink for invalid character
 * wrong lenght line(\n position)
 * number of # (must to be 4)
 * check for \n a end of piece
 * every valid piece have 6 total sides touching
*
*/

/*Check for NL position. Every 5 from 19 to 0*/
int	check_nl(const char *str)
{
	int i = MAX_SIZE - 1;

	while (i > 0)
	{
		if (str[i] != NEWLINE)
			return (-1);
		i -= 5;
	}
	if (str[MAX_SIZE] != NEWLINE || str[MAX_SIZE] != '\0')
		return (-1);
	return (0);
}

/*check for all possibility of tetriminos*/
//int	tetricount(int tetricount)
//{
//	checker si le count ne depasse pas le nombre maximunde tetrimnos existant
//}

/*Reads tetriminos 1 by 1 from argv, adding to an array of struct or linked
 * list*/

t_list *read_tetriminos(int fd)
{
	char	*tetriminos;
	int		count;

	count = 0;
	tetriminos = ft_strnew(MAX_SIZE + 1);
	while(read(fd, &teriminos, (MAX_SIZE + 1)))
	{
		if (check_nl(tetriminos) == -1 || tetricount(count) == -1)
			return (NULL);
		tetriminos[MAX_SIZE] = '\0';

		add le tetriminos dans lst add.ou au tableau de de struct
		ft_bzero(tetriminos, (MAX_SIZE + 1));
		count++;
	}
	ft_strdel(tetriminos);
	//si le tetricount == 0
	//	on returne (NULL)
	return ();
}


int	main(int argc, char **argv)
{
	int						fd;
	int						i;
	struct s_tetriminos		arr_tetriminos[20];

	i = 0;
	if (argc != 2)
		ft_putstr("usage: ./fillit source_file");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (-1);
		while (i < 20)
		{
			arr_tetriminos[i] = read_tetriminos(fd);
			if (!arr_tetriminos[i])
				close(fd);
					if (close(fd) == -1)
						return error
				return (error);
		}
	}
	devra retouner le tetriminos_list ou arr;
	return (0);
}