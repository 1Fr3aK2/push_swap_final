/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/07/02 21:20:32 by marvin            #+#    #+#             */
/*   Updated: 2024/07/02 21:20:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


static void	swap(r_list **stack)
{
	r_list *temp;
	int temp_index;

	if (!(*stack) || !(*stack)->next)
		return ;

	temp = (*stack);
	(*stack) = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	(*stack)->prev = NULL;
	temp->prev = (*stack);
	if (temp->next)
		temp->next->prev = temp;

	temp_index = (*stack)->index;  //-> temp_index = 2 (node 1, antigo 2)
	(*stack)->index = temp->index; // -> (node 1 antigo 2,guarda o index do novo 2 antigo 1)
	temp->index = temp_index;      //(novo 2 antigo 1 guarda o index do 1 );
}

void	sa(r_list **a_stack)
{
	swap(a_stack);
	ft_printf("sa\n");
}

void	sb(r_list **b_stack)
{
	swap(b_stack);
	ft_printf("sb\n");
}

void	ss(r_list **a_stack, r_list **b_stack)
{
	swap(a_stack);
	swap(b_stack);
	ft_printf("ss\n");
}