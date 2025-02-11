/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:10:37 by hes-saou          #+#    #+#             */
/*   Updated: 2025/02/11 19:02:31 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_args(char **argv)
{
	int	i;

	i = 0;
	if (!argv)
		exit(1);
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

int	is_empty(char *str)
{
	int	j;

	if (!str)
		return (1);
	j = 0;
	while (str[j])
	{
		if (!(str[j] >= 9 && str[j] <= 13) && str[j] != 32)
			return (0);
		j++;
	}
	return (1);
}

int	count_args(int argc, char **argv)
{
	char	**args;
	int		count_args;
	int		j;
	int		i;

	i = 1;
	count_args = 0;
	while (i < argc)
	{
		if (is_empty(argv[i]))
			return (-1);
		args = ft_split(argv[i], ' ');
		if (!args)
			return (-1);
		j = 0;
		while (args[j])
		{
			count_args++;
			j++;
		}
		free_args(args);
		i++;
	}
	return (count_args);
}

char	**alloc_args(int count_args, int argc, char **argv)
{
	char	**args;
	char	**all_args;
	int		i;
	int		j;
	int		k;

	i = 1;
	k = 0;
	all_args = (char **)malloc((count_args + 1) * sizeof(char *));
	if (!all_args)
		return (NULL);
	while (i < argc)
	{
		j = 0;
		args = ft_split(argv[i], ' ');
		if (!args)
			return (NULL);
		while (args[j])
			all_args[k++] = ft_strdup(args[j++]);
		free_args(args);
		i++;
	}
	all_args[k] = NULL;
	return (all_args);
}
