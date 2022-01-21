/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:56:36 by briffard          #+#    #+#             */
/*   Updated: 2022/01/21 15:15:19 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		sidechecker(char *tetriminos,int index)
{
	int communside;

	communside = 0;

	if (tetriminos[index] == tetriminos[index - 1])
		communside += 1;
	if (tetriminos[index] == tetriminos[index - 5])
		communside += 1;
	if (tetriminos[index] == tetriminos[index + 5])
		communside += 1;
	if (tetriminos[index] == tetriminos[index + 1])
		communside += 1;
	return (communside);
	/*NEED PROTECTION WHEN THE RESULT > 18 and result < 0*/
}


t_bool	is_valid(char *tetriminos)
{
	int	index;
	int	counter;
	int	countside;

	index = 0;
	counter = 0;
	countside = 0;
	while (tetriminos[index] != '\0')
	{
		if (tetriminos[index] != EMPTY && tetriminos[index] != BLOCK && tetriminos[index] != NEWLINE)
			return (false);
		if ((index % 5) == 8)
			if (tetriminos[index] != '\n')
				return (false);
		if (tetriminos[index] == '#')
		{
			counter += 1;
			countside += sidechecker(tetriminos, index);
		}
		index++;
	}
	printf("%s", tetriminos);
	printf("%sCOMMUN SIDE: %d%s ||\n",GREEN, countside, NORMAL);
	printf("%sNUMBER OF #: %d%s ||\n",RED, counter, NORMAL);
	printf("%sINDEX: %d%s ||\n", CYAN, index, NORMAL);
	printf("%s=========================================%s\n", YELLOW, NORMAL);
	if (countside != 6 && countside != 8)
		return (false);
	/*last tetriminos index is equal to 20 when all the rest are equal to 21.*/
//	if (index != 21)
//		return(false);
	if(tetriminos[index] != '\0' && tetriminos[index] != '\n')
		return(false);
	if (counter > 4 || counter < 4)
		return (false);
	return (true);
}