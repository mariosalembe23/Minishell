/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalembe <msalembe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:42:10 by msalembe          #+#    #+#             */
/*   Updated: 2024/09/20 10:42:24 by msalembe         ###   ########.fr       */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>

typedef struct s_env
{
	char			*current_path;
	char			*initial_string;
	int				has_flag_echo;
}					t_env;

typedef struct s_var
{
	char			*name;
	char			*value;
	struct s_var	*next;
}					t_var;

char				**ft_split(char const *s, char c);
char				*ft_strdup(const char *s1);
int					ft_strlen(const char *s);
void				show_error_exit(const char *str);
int					find_current_path(t_env *env);
int					ft_strcmp(char *s1, char *s2);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*convert_full_string(char **input);
void				add_new_var(t_var **var, char *name, char *value);
void				ft_export_func(char **mtr, char *input, t_var **var);
char				*ft_strchr(const char *s, int c);
void				show_envs(t_var **var);
void	free_vars(t_var *var);

// ACTIONS
void				ft_cd(char *path);
void				ft_echo(char **input, t_env *env);

#endif