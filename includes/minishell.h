/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:22:34 by shrimech          #+#    #+#             */
/*   Updated: 2025/06/18 04:13:52 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include "parsing.h"
#include "execution.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/wait.h>



/* flags pour indiquer le genre du mots
- 1 if command
- 2 if option
- 3 if pipe
- 4 if redirection
- 5 if a simple word
*/
#define COMM 1
#define OPTI 2
#define PIPE 3
#define REDI 4
#define WORD 5






#endif