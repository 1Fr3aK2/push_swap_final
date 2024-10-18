/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 04:43:50 by marvin            #+#    #+#             */
/*   Updated: 2024/07/11 04:43:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void init_stack(r_list **stack, char **argv, int argc) 
{   
    r_list *last = NULL;
    r_list *node;
    long number;
    int index;
    int i;

    i = 0;
    index = 0;
    while (i < argc)
    {
        // Verifica se há erros de escrita antes de converter
        if (writing_errors(argv[i]))
        {
            /* ft_printf("Error of syntax!\n"); */
            write(2, "Error\n", 6);
            free_stack(stack);
            exit(1);
        }

        // Converte o argumento para número e verifica se está dentro dos limites
        number = ft_atol(argv[i]);
        if (number > INT_MAX || number < INT_MIN)
        {
            /* ft_printf("Error, the number is outside of Integer limits!\n"); */
            write(2, "Error\n", 6);
            free_stack(stack);
            exit(2);
        }

        // Verifica se o número já está na stack
        if (duplicate(*stack, (int)number))
        {
            /* ft_printf("Error, duplicated numbers!\n"); */
            write(2, "Error\n", 6);
            free_stack(stack);
            exit(3);
        }

        // Cria um novo node
        node = (r_list *)ft_lstnew(number, &index); // Usando ft_lstnew corretamente
        if (!node)
        {
            /* ft_printf("Malloc failed\n"); */
            write(2, "Error\n", 6);
            free_stack(stack);
            exit(4);
        }
        ft_lstadd_back((t_list **)stack, (t_list **)&last, (t_list *)node);
        i++;
    }   
}



