#include "monty.h"

/**
 * swap_opcode - swaps the top two elements of the stack.
 *@stack: double pointer to linked list
 *@line_number: line number
 *Return: Nothing.
 */
void swap_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int a, b;

	if (dlistint_len(*stack) < 2)
	{
		global.verif = -11;
		err_exit_f(line_number);
	}
	tmp = *stack;
	a = tmp->n;
	b = tmp->next->n;
	tmp->n = b;
	tmp->next->n = a;
}
/**
 * rotr_opcode - rotates the stack to the bottom.
 *@stack: double pointer to linked list
 *@line_number: line number
 *Return: Nothing.
 */
void rotr_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *tmp2;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	tmp = *stack;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp2 = tmp->prev;
	tmp2->next = NULL;
	tmp->prev = NULL;
	tmp->next = *stack;
	*stack = tmp;
}
/**
 * rotl_opcode - swaps the top two elements of the stack.
 *@stack: double pointer to linked list
 *@line_number: line number
 *Return: Nothing.
 */
void rotl_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (*stack == NULL)
		return;
	tmp = *stack;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp = (*stack)->next;
	(*stack)->next = NULL;
	*stack = tmp;
	(*stack)->prev = NULL;
}
