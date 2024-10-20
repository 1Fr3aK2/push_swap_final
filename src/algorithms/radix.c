/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:05:11 by rafael            #+#    #+#             */
/*   Updated: 2024/10/20 02:44:07 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static  int     get_bits(r_list **a_stack)
{
    r_list  *number_bits;
    int max_bits;
    int max_nb;
    
    if (!(*a_stack) || !(a_stack))
        return (-1);
    number_bits = high_number((*a_stack));
    max_nb = number_bits->number;
    max_bits = 0;
    while((max_nb >> max_bits) != 0)
        max_bits++;
    return (max_bits); 
}



void    radix(r_list **a_stack, r_list  **b_stack)
{
    r_list  *current;
    int     i;
    int     j;
    int     lst_size;
    int     max_bits;
    
    if (!(*a_stack) || !(a_stack))
        return ;
    lst_size = ft_lstsize((t_list *)*a_stack);
    max_bits = get_bits(a_stack);
    current = (*a_stack);
    i = 0;
    while(i < max_bits)
    {
        j = 0;
        while(j++ < lst_size)
        {
            current = (*a_stack);
            if (((current->number >> i) & 1) == 1)
                ra(a_stack);
            else
                pb(a_stack, b_stack);
        }
        while (ft_lstsize((t_list *)*b_stack) != 0)
            pa(b_stack, a_stack);
        i++;
    }
}