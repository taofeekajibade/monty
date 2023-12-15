#include "monty.h"

/**
 * swap - swaps the value of the top two elements on the stack
 * @stack: pointer to the stack
 * @line_number: line number of the instruction
 * Return: void, exit with -1 on failure
 **/
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *current;

	if (len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}