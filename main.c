/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:20:46 by hes-saou          #+#    #+#             */
/*   Updated: 2025/01/24 22:21:38 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		count;
	char	**args;

	if (ac >= 2)
	{
		count = count_args(ac, av);
		if (count < 0)
		{
			ft_printf("ERROR\n");
			free_args(av);
			exit(1);
		}
		args = alloc_args(count, ac, av);
		if (!args || check_errors(args))
			exit(1);
		else
		{
			
		}
	}
	return (0);
}
