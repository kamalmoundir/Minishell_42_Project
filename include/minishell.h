/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:08:22 by rjaada            #+#    #+#             */
/*   Updated: 2025/01/17 12:41:58 by rjaada           ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/wait.h>

extern char	**g_env;

// structs

typedef struct s_data
{
	char	**env;
}			t_data;

// utils
int			is_special_char(char c);
void		checker_input(char *input, int *i);

// tokenization
void		tokenization_input(char *input);
int			handle_redirection(char *input, int i);
int			handle_variable(char *input, int i);
int			handle_quotes(char *input, int i);
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
