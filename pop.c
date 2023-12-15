#include "monty.h"

/**
 * pop - removes the last inserted element from the stack
 * @stack: pointer to the pointer to the head
 * @line_number: number of lines in the file
 * Return: void, exit with -1 on failure
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *to_remove;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	to_remove = *stack;
	*stack = (*stack)->next;
	free(to_remove);
}