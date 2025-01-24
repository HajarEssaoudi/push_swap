/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:29:11 by hes-saou          #+#    #+#             */
/*   Updated: 2025/01/24 22:17:47 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

//utils
long	convert(char *str);
int		ft_strcmp(const char *s1, const char *s2);

//Handle args
void	free_args(char **argv);
int		count_args(int argc, char **argv);
char	**alloc_args(int count_args, int argc, char **argv);
int		check_errors(char **str);
#endif