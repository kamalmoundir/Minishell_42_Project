/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:08:22 by rjaada            #+#    #+#             */
/*   Updated: 2025/01/15 14:09:07 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libraries/libft/libft.h"
# include "builtins.h"
# include <errno.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

extern char ** g_env;

// utils
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);

// parser
void	tokenization_input(char *input);
char	*expand_variable(const char *token);

// error handling
int		error_input(char quote);

// builtins
int		echo(int ac, char **av, int fd);
int		pwd(int number_arg);

#endif
