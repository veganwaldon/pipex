/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwaldon <vwaldon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:14:51 by vwaldon           #+#    #+#             */
/*   Updated: 2022/06/01 21:38:44 by vwaldon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	free_child(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->path_cmd[i])
	{
		free(pipex->path_cmd[i]);
		i++;
	}
	free(pipex->path_cmd);
}

void	free_parent(t_pipex *pipex)
{
	int	i;
	int	j;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->path_cmd[i])
	{
		free(pipex->path_cmd[i]);
		i++;
	}
	i = 0;
	j = 0;
	while (pipex->cmds[j])
	{
		while (pipex->cmds[j]->cmd[i])
		{
			free(pipex->cmds[j]->cmd[i]);
			i++;
		}
		j++;
	}
	free(pipex->path_cmd);
	free(pipex->cmds[j]);
}
