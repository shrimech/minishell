/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:22:34 by shrimech          #+#    #+#             */
/*   Updated: 2025/06/15 00:34:39 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include "../libft/libft.h"
#include "execution.h"
#include "parsing.h"
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