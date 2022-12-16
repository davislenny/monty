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
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty", line_number);
		error_exit(stack);
	}
	else if (!isprint((*stack)->n))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range", line_number);
		error_exit(stack);
	}
	printf("%c\n", (*stack)->n);
}
/**
 * _pstr - prints a string stored in stack
 * @stack: poins to linked list stack_t
 * @line_number: line opcode occurs
 */
/*void _pstr(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
		putchar('\n');
	while ((*stack)->next)
	{
		printf("%c", (*stack)->n);
		if ((*stack)->next->n == 0 || !isprint((*stack)->next->n))
			break;
	}
	putchat('\n');
*/
