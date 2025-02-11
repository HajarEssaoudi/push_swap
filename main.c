/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:20:46 by hes-saou          #+#    #+#             */
/*   Updated: 2025/02/11 21:11:14 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	is_empty_arg(char **args);

int	main(int ac, char **av)
{
	int		count_arg;
	char	**args;
	t_stack	*a;
	t_stack	*b;

	if (ac >= 2)
	{
		count_arg = count_args(ac, av);
		if (count_arg < 0)
		{
			ft_putstr_fd("ERROR\n", 2);
			exit(1);
		}
		args = alloc_args(count_arg, ac, av);
		if (!args || check_errors(args))
			exit(1);
		a = init_a(count_arg, args);
		free_args(args);
		b = create_stack();
		sort_a(a, b);
		printf("--------------stak a--------: \n");
		print_a(a);
		printf("-----------stak b-----------: \n");
		print_a(b);
		free_stack(a);
		free_stack(b);
	}
	return (0);
}
