#include <stdio.h>
#include <stdlib.h>

typedef struct r_list {
    int number;               // Valor do nó
    struct r_list *next;     // Ponteiro para o próximo nó
} r_list;



void ra(r_list **stack) {
    if (!(*stack) || !(*stack)->next) return;
    r_list *temp = *stack;
    *stack = (*stack)->next;
    temp->next = NULL;

    r_list *current = *stack;
    while (current->next) {
        current = current->next;
    }
    current->next = temp;
    printf("ra\n");
}

int find_distance(r_list *stack, r_list *lowest) {
    int distance = 0;
    while (stack) {
        if (stack == lowest)
            return distance;
        distance++;
        stack = stack->next;
    }
    return -1; // Em caso de erro
}


r_list* low_number(r_list *stack) {
    r_list *lowest_number = stack;

    if (!stack)
        return NULL;
    while (stack->next) {
        stack = stack->next;
        if (stack->number < lowest_number->number)
            lowest_number = stack;
    }
    return lowest_number;
}


int ft_lstsize(r_list *stack) {
    int size = 0;
    while (stack) {
        size++;
        stack = stack->next;
    }
    return size;
}

void append(r_list **head, int new_number) {
    r_list *new_node = (r_list *)malloc(sizeof(r_list));
    r_list *last = *head;

    new_node->number = new_number;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    while (last->next) {
        last = last->next;
    }
    last->next = new_node;
}








void rra(r_list **stack) {
    if (!(*stack) || !(*stack)->next) return;

    r_list *current = *stack;
    while (current->next->next) {
        current = current->next;
    }
    r_list *last = current->next;
    current->next = NULL;
    last->next = *stack;
    *stack = last;
    printf("rra\n");
}

void    sort_four(r_list **a_stack, r_list **b_stack)
{
    int distance;
    int lst_size;
    int median;
    
    if (!(*a_stack) || !(a_stack))
        return ;
    
    distance = find_distance(*a_stack, low_number(*a_stack));
    lst_size = ft_lstsize(*a_stack);
    median = lst_size / 2;
    
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
    
}

int main() {
    r_list *a_stack = NULL;
    r_list *b_stack = NULL;

    // Adicionando alguns números à pilha A
    append(&a_stack, 598);
    append(&a_stack, 22);
    append(&a_stack, 8);
    append(&a_stack, 33);

    // Exibindo a pilha A antes da ordenação
    printf("Pilha A antes da ordenação:\n");
    r_list *temp = a_stack;
    while (temp) {
        printf("%d -> ", temp->number);
        temp = temp->next;
    }
    printf("NULL\n");

    // Ordenando os números
    sort_four(&a_stack, &b_stack);

    // Exibindo a pilha A após a ordenação
    printf("Pilha A após a ordenação:\n");
    temp = a_stack;
    while (temp) {
        printf("%d -> ", temp->number);
        temp = temp->next;
    }
    printf("NULL\n");

    // Liberar a memória
    while (a_stack != NULL) {
        r_list *next = a_stack->next;
        free(a_stack);
        a_stack = next;
    }

    return 0;
}
