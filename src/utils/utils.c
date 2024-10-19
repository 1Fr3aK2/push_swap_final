/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 04:03:43 by marvin            #+#    #+#             */
/*   Updated: 2024/07/12 04:03:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

long ft_atol(const char *str)
{
	long number;
	int sign;

	number = 0;
	sign = 1;
	while((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if(*str == '+' || *str == '-')
	{
		if(*str == '-')
			sign = -1;
		str++;
	}
	while(*str >= 48 && *str <= 57)
	{
		number *= 10;
		number += *str - 48;
		str++;
	}
	return (number *sign);
}

int verify(r_list *stack)
{
	if(!stack)
		return (1);
	while(stack -> next)
	{
		if(stack->number > stack->next->number)
			return (1);
		stack = stack->next;
	}
	return(0);
}

r_list *high_number(r_list *stack) 
{
    r_list *highest_number;
	
	highest_number = stack;

    if (!stack)
        return(NULL);
    while (stack) 
	{
        if (stack->number > highest_number->number)
            highest_number = stack;
        stack = stack->next;
    }
    return(highest_number);
}

r_list *low_number(r_list *stack)
{
	r_list *lowest_number;

	lowest_number = stack;

	if(!stack)
		return(NULL);
	while(stack)
	{
		if(stack->number < lowest_number->number)
			lowest_number = stack;
		stack = stack->next;
	}
	return(lowest_number);
}

void free_split(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

int		find_distance(r_list **stack, int index)
{
	r_list	*current;
	int		distance;

	if(!(*stack) || !(stack))
		return (-1);
	
	current = (*stack);
	distance = 0;
	while(current)
	{
		if (current->index == index)
			return (distance);
		else
		{
			distance++;
			current = current->next;
		}
	}
	return (distance);
}

int		low_index(t_list **stack, int nb)
{
	r_list *current;
	int		lowest;

	if (!(*stack) || !(stack))
		return (-1);
	
	lowest = (*stack)->index;
	current = (*stack)->next;
	while(current)
	{
		if ((current->index < lowest) && (current->index != nb))
			lowest = current->index;
		current = current->next;
	}
	return (lowest);
}