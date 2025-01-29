/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:09:37 by kmoundir          #+#    #+#             */
/*   Updated: 2025/01/28 14:14:01 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// i should be crerate struct shell with env or use g_env
//and add in struct shell fd_in and fd_out  to use it in ft_putstr_fd
int ft_env(char **arg, int fd)
{
    int i;

    i = 0;
    if(arg == NULL)
    {
        return (0);   
    }
    while(arg[i])
    {
        ft_putstr_fd(arg[i], fd);
        i++;
    }
    return (1);    
}