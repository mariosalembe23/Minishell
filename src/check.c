/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalembe <msalembe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:58:45 by msalembe          #+#    #+#             */
/*   Updated: 2024/09/24 18:18:39 by msalembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	show_error_exit(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	free_vars(t_var *var)
{
	t_var	*tmp;

	while (var)
	{
		tmp = var;
		var = var->next;
		free(tmp->name);
		free(tmp->value);
		free(tmp);
	}
}
