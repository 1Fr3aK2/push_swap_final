#include <stdio.h>
#include <stdlib.h>

// Estrutura da lista ligada (exemplo simplificado)
typedef struct s_r_list {
    int number;
    struct s_r_list *next;
} r_list;

// Função para encontrar o maior número na pilha
int high_number(r_list *stack) {
    int highest = stack->number;

    while (stack) {
        if (stack->number > highest)
            highest = stack->number;
        stack = stack->next;
    }
    return (highest);
}

// Função para calcular o número de bits necessários
int get_bits(r_list **a_stack) {
    int max_bits;
    int max_nb;

    if (!(*a_stack) || !(a_stack))
        return (0);
    max_nb = high_number(*a_stack);  // Encontrar o maior número
    max_bits = 0;
    while ((max_nb >> max_bits) != 0)  // Contar os bits
        max_bits++;
    return (max_bits);
}

// Função para criar um novo nó da lista
r_list *new_node(int number) {
    r_list *new = (r_list *)malloc(sizeof(r_list));
    if (!new)
        return NULL;
    new->number = number;
    new->next = NULL;
    return new;
}

// Função principal (main)
int main() {
    // Criar alguns nós na pilha (a_stack)
    r_list *a_stack = new_node(3);
    a_stack->next = new_node(7);
    a_stack->next->next = new_node(50);
    a_stack->next->next->next = new_node(1);

    // Calcular o número de bits necessários para o maior número
    int bits = get_bits(&a_stack);

    // Exibir o resultado
    printf("O número de bits necessários para representar o maior número: %d\n", bits);

    // Limpar a memória
    while (a_stack) {
        r_list *temp = a_stack;
        a_stack = a_stack->next;
        free(temp);
    }

    return 0;
}
