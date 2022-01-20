/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:57:42 by briffard          #+#    #+#             */
/*   Updated: 2022/01/20 15:45:32 by briffard         ###   ########.fr       */
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
			pieces[ret] = '\0';
			tetriminos = push_back_list(tetriminos, pieces);
		}
	print_list(tetriminos);
}