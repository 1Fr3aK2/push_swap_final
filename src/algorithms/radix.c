/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:05:11 by rafael            #+#    #+#             */
/*   Updated: 2024/10/19 20:30:54 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static      get_bits(r_list **a_stack)
{
    int max_bits;
    int max_nb;
    
    if (!(*a_stack) || !(a_stack))
        return ;
    max_nb = high_number((*a_stack)->number);
    max_bits = 0;
    while((max_nb >> max_bits) != 0)
        max_bits++;
    return (max_bits); 
}



void    radix(r_list **a_stack, r_list  **b_stack)
{
    r_list  *current;
    
    if (!(*a_stack) || !(a_stack))
        return ;
    
}