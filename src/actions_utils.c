/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalembe <msalembe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:14:33 by msalembe          #+#    #+#             */
/*   Updated: 2024/09/24 18:19:43 by msalembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int	check_create_env(char **mtr)
{
	int	i;

	i = 0;
	while (mtr[i])
		i++;
	return (i == 2);
}

static void	ft_export_utils(char *input, t_var **var)
{
	char	*equal_sign;
	char	*name;
	char	*value;

	equal_sign = ft_strchr(input, '=');
	if (equal_sign)
	{
		*equal_sign = '\0';
		name = input;
		value = equal_sign + 1;
		if (ft_strlen(name) == 0)
		{
			printf("zsh: bad assignment: variable name cannot be empty\n");
			return ;
		}
		add_new_var(var, name, value);
	}
	else
		printf("export: not valid in this context\n");
}

void	ft_export_func(char **mtr, char *input, t_var **var)
{
	if (input == NULL || ft_strcmp(input, " ") == 0)
	{
		show_envs(var);
		return ;
	}
	if (!check_create_env(mtr))
	{
		printf("zsh: bad assingment\n");
		return ;
	}
	ft_export_utils(input, var);
}
