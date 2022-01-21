/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:57:42 by briffard          #+#    #+#             */
/*   Updated: 2022/01/21 15:15:36 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fillit.h"

/*newlist creation*/
List	newlist(void)
{
	return (NULL);
}

/*Created a new element and put at the end of the list*/
List	push_back_list(List li, char *shape)
{
	t_tetri_list	*element;
	t_tetri_list	*temp;
	
	element = malloc(sizeof(*element));
	if (!element)
	{
		ft_putstr_fd("Error: problem with dynamic allocation memory\n", 2);
		exit(EXIT_FAILURE);
	}
	element->tetriminos = ft_strdup(shape);
	element->next = NULL;
	if (!li)
		return (element);
	temp = li;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = element;
	return (li);
}

/*PRINT LIST*/
void	print_list(List li)
{
	if (!li)
	{
		ft_putstr("Nothing to print, the list is empty.\n");
		return;
	}
	while (li != NULL)
	{
		ft_putstr(li->tetriminos);
		li = li->next;
	}
	ft_putchar('\n');
}
 
int	main(int argc, char **argv)
{
	List			tetriminos;
	char			pieces[MAX_SIZE + 1];
	int				fd;
	int				ret;

	tetriminos = newlist();
	if (argc != 2)
		ft_putstr("Error// print usage message\n");
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		ft_putstr("Error: open file.\n");
	while((ret = read(fd, pieces, MAX_SIZE)))
		{
			pieces[ret] = '\0';//pieces[ret -1] = \n || ret - 2 = \n || except for the last tetriminos
			printf("%s%c%s\n",GREEN, pieces[ret - 3],NORMAL);
			if (is_valid(pieces))//we can remove  extra \n after checker if pices are valide
				tetriminos = push_back_list(tetriminos, pieces);
			else
			{
				ft_putstr_fd("Error: Not a valid tetriminos.\nEnd of the programm\n", 2);
				break;
			}
		}
	close(fd);
//	print_list(tetriminos);
	int count = 0;
	while (tetriminos)
	{:
		if (count == 5)
			printf("%s%s%s", RED, tetriminos->tetriminos, NORMAL);
		tetriminos = tetriminos->next;
		count++;
	}
}