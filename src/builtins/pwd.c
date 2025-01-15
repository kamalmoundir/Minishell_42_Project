/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:48:04 by kmoundir          #+#    #+#             */
/*   Updated: 2025/01/15 11:09:51 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"
#include <linux/limits.h>

int pwd(int number_arg)
{
    char *cwd;
    int error_num;
    
    if(number_arg == 0)
    {
        cwd = getcwd(NULL,PATH_MAX);
        if(!cwd)
        {
            error_num = errno;
            ft_putstr_fd("pwd:",2);
            ft_putstr_fd(strerror(error_num), 2);
            ft_putstr_fd("\n",2);                    
        }
        else
        {
            printf("%s\n", cwd);
            free(cwd);
        }
    }
    else
        ft_putstr_fd("Too many arguments\n", 2);

    return 0;
}