#include "monty.h"

/**
 * pall - function to print stack's elements
 * @stack: pointer to the head of the doubly linked list
 * @line_number: will not be used, we use attribute not void
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL)
		return;

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}