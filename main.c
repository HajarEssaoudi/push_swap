/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:20:46 by hes-saou          #+#    #+#             */
/*   Updated: 2025/01/25 18:30:42 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		count_arg;
	char	**args;
	Stack	*a;
	Stack	*b;

	if (ac >= 2)
	{
		count_arg = count_args(ac, av);
		if (count_arg < 0)
		{
			ft_printf("ERROR\n");
			free_args(av);
			exit(1);
		}
		args = alloc_args(count_arg, ac, av);
		if (!args || check_errors(args))
			exit(1);
		else
		{
			a = init_a(count_arg, args);
			free_args(args);
			b = create_stack();
			print_a(a);
		}
	}
	return (0);
}
