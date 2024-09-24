/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalembe <msalembe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:59:22 by msalembe          #+#    #+#             */
/*   Updated: 2024/09/24 18:18:56 by msalembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_cd(char *path)
{
	char	*home;

	home = getenv("HOME");
	if (path == NULL || ft_strcmp(path, "") == 0 || ft_strcmp(path, " ") == 0)
	{
		if (chdir(home) != 0)
			printf("cd: %s\n", strerror(errno));
	}
	else if (chdir(path) != 0)
		printf("cd: %s\n", strerror(errno));
}

void	axuiliary_utils(char *argv[], char **str, int print_newline)
{
	argv[0] = "echo";
	if (!print_newline)
	{
		argv[1] = "-n";
		argv[2] = *str;
		argv[3] = NULL;
	}
	else
	{
		argv[1] = *str;
		argv[2] = NULL;
	}
}

void	auxiliary_echo(char **str, char **input, char *argv[], t_env *env)
{
	int	print_newline;

	*str = NULL;
	print_newline = 1;
	if (input[1] && ft_strcmp(input[1], "-n") == 0 && input[2])
	{
		print_newline = 0;
		env->has_flag_echo = 1;
		*str = convert_full_string(input + 2);
	}
	else
	{
		*str = convert_full_string(input + 1);
		env->has_flag_echo = 0;
	}
	axuiliary_utils(argv, str, print_newline);
}

void	ft_echo(char **input, t_env *env)
{
	char	*str;
	char	*argv[4];
	pid_t	pid;

	auxiliary_echo(&str, input, argv, env);
	if (str)
	{
		pid = fork();
		if (pid == 0)
		{
			execve("/bin/echo", argv, NULL);
			printf("execve: %s\n", strerror(errno));
		}
		else if (pid > 0)
			wait(NULL);
		else
		{
			free(str);
			perror("Error forking the process echo");
		}
		free(str);
	}
	else
		show_error_exit("Erro ao alocar memória");
}
