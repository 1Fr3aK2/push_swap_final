/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 02:14:55 by rafael            #+#    #+#             */
/*   Updated: 2024/10/19 04:49:39 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    sort_four(r_list **a_stack, r_list **b_stack)
{
    int distance;
    int median;
    
    if (!(*a_stack) || !(a_stack))
        return ;
    distance = find_distance(a_stack, low_number(*a_stack)->number);
    median = ft_lstsize((t_list *)*a_stack) / 2;
    while(distance)
    {
        if(distance > median)
        {
            rra(a_stack);
            distance = 0;
        }
        else
        {
            ra(a_stack);
            distance--;
        }
    }
    if (verify(*a_stack) == 0)
        return ;
    pb(a_stack, b_stack);
    sort_three(a_stack);
    pa(b_stack, a_stack);
    /* printf("sort_four donne\n"); */
}
