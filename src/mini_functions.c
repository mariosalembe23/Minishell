/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalembe <msalembe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:58:15 by msalembe          #+#    #+#             */
/*   Updated: 2024/09/24 18:18:46 by msalembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*ptr;

	ptr = dest;
	while (*ptr != '\0')
		ptr++;
	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dest);
}

char	*convert_full_string(char **input)
{
	size_t	total_length;
	size_t	count;
	size_t	i;
	char	*result;

	total_length = 0;
	count = 0;
	i = 0;
	while (input[count])
	{
		total_length += ft_strlen(input[count]) + 1;
		count++;
	}
	result = malloc(total_length);
	if (!result)
		return (NULL);
	result[0] = '\0';
	while (i < count)
	{
		ft_strcat(result, input[i]);
		if (i < count - 1)
			ft_strcat(result, " ");
		i++;
	}
	return (result);
}

void	show_envs(t_var **var)
{
	t_var	*tmp;

	tmp = *var;
	if (tmp == NULL)
	{
		printf("No environment variables set.\n");
		return ;
	}
	while (tmp != NULL)
	{
		printf("%s=%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
}

void	add_new_var(t_var **var, char *name, char *value)
{
	t_var	*new;

	new = (t_var *)malloc(sizeof(t_var));
	if (!new)
		show_error_exit("error allocating memmory");
	new->name = ft_strdup(name);
	new->value = ft_strdup(value);
	new->next = *var;
	*var = new;
}
