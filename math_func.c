#include "monty.h"
/**
 * _add - adds top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		error_exit(stack);
	}
	(*stack)->next->n += (*stack)->n;
	_pop(stack, line_number);
}

/**
 * _sub - subtracts top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		error_exit(stack);
	}
	(*stack)->next->n -= (*stack)->n;
	_pop(stack, line_number);
}
/**
 * _div -  divides the second top element by the top
 * @stack: points to linked list stack_t
 * @line_number: line opcode occurs
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		error_exit(stack);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		error_exit(stack);
	}
	(*stack)->next->n /= (*stack)->n;
	_pop(stack, line_number);
}
/**
 * _mul -  multiplies the second top element with top
 * @stack: points to linked list stack_t
 * @line_number: line opcode occurs
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		error_exit(stack);
	}
	(*stack)->next->n *= (*stack)->n;
	_pop(stack, line_number);
}
/**
 * _mod - computes the rest of the division of the second top and top
 * @stack: points to linked list stack_t
 * @line_number: line opcode occurs
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		error_exit(stack);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		error_exit(stack);
	}
	(*stack)->next->n %= (*stack)->n;
	_pop(stack, line_number);
}
