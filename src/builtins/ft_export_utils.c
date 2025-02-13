/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:20:30 by rjaada            #+#    #+#             */
/*   Updated: 2025/02/13 15:51:25 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_env_var(char **env, const char *var)
{
	int	i;
	int	len;

	if (!var || !env)
		return (-1);
	len = ft_strlen(var);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], var, len) == 0 && env[i][len] == '=')
			return (i);
		i++;
	}
	return (-1);
}

char	*create_env_entry(const char *name, const char *value)
{
	char	*entry;
	size_t	len;

	if (!name)
		return (NULL);
	len = ft_strlen(name);
	if (value)
		len += ft_strlen(value) + 1;
	entry = (char *)malloc(sizeof(char) * (len + 1));
	if (!entry)
		return (NULL);
	ft_strlcpy(entry, name, len + 1);
	if (value)
	{
		ft_strlcat(entry, "=", len + 1);
		ft_strlcat(entry, value, len + 1);
	}
	return (entry);
}
