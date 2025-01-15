/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:08:22 by rjaada            #+#    #+#             */
/*   Updated: 2025/01/15 15:36:53 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libraries/libft/libft.h"
# include <errno.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

extern char	**g_env;

// utils
int			is_special_char(char c);

// parser
void		tokenization_input(char *input);
char		*expand_variable(const char *token);

// error handling
int			error_input(char quote);

// builtins
int			echo(int ac, char **av, int fd);
int			pwd(int number_arg);

// signal handle
void		handle_sigint(int sig);
void		handle_sigquit(int sig);

#endif
