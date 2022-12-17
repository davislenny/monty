#include "monty.h"
/**
 * _nop - literally does nothing
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * _pchar - prints a character at the top of stack
 * @stack: points to linked list stack_t
 * @line_number: line opcode occurs
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty", line_number);
		error_exit(stack);
	}
	else if (!isprint((*stack)->n))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range", line_number);
		error_exit(stack);
	}
	printf("%c\n", (*stack)->n);
}
/**
 * _pstr - prints a string stored in stack
 * @stack: poins to linked list stack_t
 * @line_number: line opcode occurs
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	while (*stack != NULL)
	{
		if ((*stack)->n == 0 || !isprint((*stack)->n))
			break;
		putchar((*stack)->n);
		*stack = (*stack)->next;
	}
	putchar('\n');
	putchar ('0');
	putchar('\n');
}
