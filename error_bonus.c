/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwaldon <vwaldon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 21:32:47 by vwaldon           #+#    #+#             */
/*   Updated: 2022/06/01 21:39:37 by vwaldon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	print_error(char *error)
{
	write(2, error, ft_strlen(error));
	return (1);
}

void	show_error(char *error)
{
	write(2, "/pipex: ", 8);
	perror(error);
	exit (1);
}
