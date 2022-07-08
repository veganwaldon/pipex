/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwaldon <vwaldon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:50:02 by vwaldon           #+#    #+#             */
/*   Updated: 2022/06/01 21:38:22 by vwaldon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	if (*envp == 0)
		show_error("Path error");
	return (*envp + 5);
}

void	here_doc(char *limiter)
{
	int		hd_fd[2];
	char	*line;

	if (pipe(hd_fd) == -1)
		show_error("Pipe error");
	line = NULL;
	while (1)
	{
		write(1, "> ", 2);
		if (get_next_line(&line) < 0)
			exit (1);
		if (!ft_strncmp(limiter, line, ft_strlen(limiter) + 1))
			break ;
		write(hd_fd[1], line, ft_strlen(line));
		write(hd_fd[1], "\n", 1);
		free(line);
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
	dup2(hd_fd[0], 0);
	close(hd_fd[0]);
	close(hd_fd[1]);
}

void	parse_cmds(char **argv, t_pipex	*pipex)
{
	int	i;
	int	j;

	j = 0;
	i = 2;
	if (pipex->here_doc == 1)
		i = 3;
	pipex->cmds[0] = NULL;
	while (j < pipex->cmd_num)
	{
		pipex->cmds[j] = malloc (sizeof(t_cmds));
		if (!pipex->cmds[j])
			ft_printf("malloc error");
		pipex->cmds[j]->cmd_args = NULL;
		pipex->cmds[j]->cmd_args = ft_strdup(argv[i]);
		pipex->cmds[j]->cmd = ft_split(argv[i], ' ');
		j++;
		i++;
	}
}

void	parse_args(int argc, char **argv, char **envp, t_pipex *pipex)
{
	if (argv[1] && !ft_strncmp(argv[1], "here_doc", 9) && argc >= 6)
		pipex->here_doc = 1;
	else if (argc < 5)
	{
		print_error("Invalid number of arguments\n");
		exit(1);
	}
	else
		pipex->here_doc = 0;
	pipex->path = find_path(envp);
	pipex->path_cmd = ft_split(pipex->path, ':');
	pipex->cmd_num = argc - 3 - pipex->here_doc;
	parse_cmds(argv, pipex);
	return ;
}
