/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:51:31 by kmoundir          #+#    #+#             */
/*   Updated: 2025/02/13 15:43:04 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

// builtins
int		echo(int ac, char **av, int fd);
int		pwd(int number_arg);
int		ft_env(char **arg, int fd, char **env);
int		is_exit(char *input);
int		ft_cd(char *path);
void	ft_unset(char *var, char **env);
int		ft_export(char **args, char **env);

// export utils
int		is_valid_identifier(const char *str);
int		find_env_var(char **env, const char *var);
char	*create_env_entry(const char *name, const char *value);

#endif