/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:28:41 by rjaada            #+#    #+#             */
/*   Updated: 2025/02/13 23:45:31 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static char	*join_chars(char *str, char c)
{
	char	*temp;
	char	*result;

	temp = str;
	result = ft_strjoin(str, (char[]){c, '\0'});
	free(temp);
	return (result);
}

static char	*get_var_name(char *str, int *i)
{
	int		start;
	char	*name;

	(*i)++;
	start = *i;
	while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
		(*i)++;
	name = ft_substr(str, start, *i - start);
	return (name);
}

static char	*join_var_value(char *result, char *var_value)
{
	char	*temp;

	temp = result;
	if (var_value)
		result = ft_strjoin(result, var_value);
	else
		result = ft_strjoin(result, "");
	free(temp);
	return (result);
}

static char	*get_shell_var_value(char **env, const char *var_name)
{
	int		var_index;
	char	*value;
	char	*eq_pos;

	if (!var_name || !env)
		return (NULL);
	var_index = find_env_var(env, var_name);
	if (var_index < 0)
		return (NULL);
	eq_pos = ft_strchr(env[var_index], '=');
	if (!eq_pos)
		return (NULL);
	value = ft_strdup(eq_pos + 1);
	return (value);
}

char	*expand_shell_vars(char *str, char **env)
{
	int		i;
	char	*result;
	char	*var_name;
	char	*var_value;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			var_name = get_var_name(str, &i);
			if (!var_name)
				return (NULL);
			var_value = get_shell_var_value(env, var_name);
			free(var_name);
			result = join_var_value(result, var_value);
			free(var_value);
			if (!result)
				return (NULL);
		}
		else
		{
			result = join_chars(result, str[i]);
			if (!result)
				return (NULL);
			i++;
		}
	}
	return (result);
}

char	*expand_env_vars(char *str)
{
	int		i;
	char	*result;
	char	*var_name;
	char	*var_value;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			var_name = get_var_name(str, &i);
			if (!var_name)
				return (NULL);
			var_value = getenv(var_name);
			free(var_name);
			result = join_var_value(result, var_value);
			if (!result)
				return (NULL);
		}
		else
		{
			result = join_chars(result, str[i]);
			if (!result)
				return (NULL);
			i++;
		}
	}
	return (result);
}
