#include "monty.h"

/**
 * f_push - Pushes an element to the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number where the opcode appears.
 */
void f_push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node;
    int num;

    if (bus.arg == NULL)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    num = atoi(bus.arg);
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = num;
    new_node->next = *stack;
    *stack = new_node;
}
