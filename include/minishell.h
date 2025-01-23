/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:02:40 by kmoundir          #+#    #+#             */
/*   Updated: 2025/01/23 14:55:44 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libraries/libft/libft.h"
# include "builtins.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

extern char	**g_env;

// structs

typedef struct s_data
{
	char	**env;
}			t_data;

// utils
int			is_special_char(char c);
void		checker_input(char *input, int *i);
int			process_quoted_string(char *input, int i);
int			process_token(char *input, int i);
int			process_quote_content(char *input, int *i, char quote);

// tokenization
void		tokenization_input(char *input);
int			handle_redirection(char *input, int i);
int			handle_variable(char *input, int i);
int			handle_quotes(char *input, int i);
char		*expand_variable(const char *token);

// error handling
int			error_input(char quote);
int			is_exit(char *input);

// signal handle
void		handle_sigint(int sig);
void		handle_sigquit(int sig);

#endif
