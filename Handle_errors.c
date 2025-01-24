/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:39:50 by hes-saou          #+#    #+#             */
/*   Updated: 2025/01/24 22:21:16 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verify_number(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if ((str[i][j] == '-' || str[i][j] == '+') && str[i][j + 1] != '\0')
			j++;
		while (str[i][j])
		{
			if (str[i][j] < '0' || str[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	verify_number_max(char **str)
{
	int		i;
	long	num;

	i = 0;
	while (str[i])
	{
		num = convert(str[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

int	is_repeated(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_strcmp(str[i], str[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_errors(char **str)
{
	if (verify_number(str) == 1
		|| verify_number_max(str) == 1
		|| is_repeated(str) == 1)
	{
		ft_putstr("ERROR\n");
		free_args(str);
		return (1);
	}
	return (0);
}
