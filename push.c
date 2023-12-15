#include "monty.h"
#include <string.h>

/**
 * push - adds a new node to the stack
 * @stack: pointer to a pointer to the doubly linked list
 * @n: string representing the integer to be pushed
 * @line_number: line where there is an error
 * Return: void, exit with -1 on failure
 */
void push(stack_t **stack, char *n, unsigned int line_number)
{
	stack_t *new = NULL;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (n == NULL || !is_valid_integer(n))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new->n = atoi(n);
	new->prev = NULL;
	new->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new;

	*stack = new;
}

/**
 * is_valid_integer - checks if a string is a valid integer
 * @str: string to be checked
 * Return: 1 if valid, 0 otherwise
 */
int is_valid_integer(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[0] == '-' && i == 0)
			continue;

		if (str[i] < '0' || str[i] > '9')
			return 0;
	}

	return 1;
}