/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:51:31 by kmoundir          #+#    #+#             */
/*   Updated: 2025/02/05 21:27:19 by rjaada           ###   ########.fr       */
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
#endif