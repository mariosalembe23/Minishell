/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalembe <msalembe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:56:12 by msalembe          #+#    #+#             */
/*   Updated: 2024/09/24 18:16:58 by msalembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static void	ft_process(const char *input_line, t_env *env, t_var **var)
{
	char	**full_cmd;
	int		i;

	i = 0;
	full_cmd = ft_split(input_line, ' ');
	if (!full_cmd)
		show_error_exit("Error splitting the command");
	while (full_cmd[i])
	{
		if (ft_strcmp(full_cmd[i], "cd") == 0)
			ft_cd(full_cmd[i + 1]);
		else if (ft_strcmp(full_cmd[i], "echo") == 0)
			ft_echo(full_cmd, env);
		else if (ft_strcmp(full_cmd[i], "pwd") == 0)
			find_current_path(env);
		else if (ft_strcmp(full_cmd[i], "export") == 0)
			ft_export_func(full_cmd, full_cmd[i + 1], var);
		i++;
	}
	i = -1;
	while (full_cmd[++i])
		free(full_cmd[i]);
	free(full_cmd);
}

static void	ft_prcess_init(t_env *env)
{
	if (env->has_flag_echo)
		env->initial_string = ft_strdup("\033[1;36m\nminishell> \033[0m");
	else
		env->initial_string = ft_strdup("\033[1;36mminishell> \033[0m");
}

static void	ft_loop_operation(t_env *env, t_var **var)
{
	char	*input;

	while (1)
	{
		ft_prcess_init(env);
		input = readline(env->initial_string);
		if (input)
		{
			ft_process(input, env, &var);
			free(input);
		}
		else
		{
			free(env->current_path);
			free(env);
			show_error_exit("Error reading the line");
		}
	}
}

int	main(void)
{
	t_env	*env;
	t_var	*var;

	var = NULL;
	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		show_error_exit("error allocating struture");
	env->has_flag_echo = 0;
	ft_loop_operation(env, &var);
	free(env->current_path);
	free(env->initial_string);
	free_vars(var);
	free(env);
	return (0);
}
