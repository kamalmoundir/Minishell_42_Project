/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:22:12 by kmoundir          #+#    #+#             */
/*   Updated: 2025/02/13 23:44:24 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 we can use a global variable to store the env or just use var in structs
*/

#include "minishell.h"

void	ft_unset(char *var, char **env)
{
	int	i;
	int	len;

	if (!var)
	{
		ft_putstr_fd(RED "unset: not enough arguments\n" RESET, 2);
		return ;
	}
	len = ft_strlen(var);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], var, len) == 0 && env[i][ft_strlen(var)] == '=')
		{
			free(env[i]);
			while (env[i])
			{
				env[i] = env[i + 1];
				i++;
			}
			env[i] = NULL;
			return ;
		}
		i++;
	}
}
