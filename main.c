/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:38:41 by itkimura          #+#    #+#             */
/*   Updated: 2022/01/18 14:20:48 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	valid(char *buf, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{

	}
}

int	error(char *str)
{
	ft_putendl(str);
	return (1);
}

int	main(int	argc, char	**argv)
{
	if (argc != 2)
		return (error("usage: fillit input_file"));

	return (0);
}
