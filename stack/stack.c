#include "funcdefinitions.h"

#define STACK_SIZE 100
int stack[STACK_SIZE];
int top = 0;


void push(int number)
{
	if(top < STACK_SIZE){
		stack[top] = number;
		top++;
		return;
	}
	printf("stack is full\n");
}

int pop(void)
{
	if(top == 0)
	{
		printf("stack is empty\n");
		return -1;
	}
	else
	{
	top--;
	return stack[top];
	}
}

bool check_empty(void)
{
	if(top == -1)
	{
		return true; 
	}
	else { return false; }
}

bool check_full(void)
{
	if(top >= STACK_SIZE - 1)
	{
		return true;
	}
	else { return false; }
}

void clear(void)
{
	for(top; top >= 0; top--)
	{
		stack[top] = 0;		
	}
	return;
}

void stack_print(void)
{
	U8 spaces_remaining = STACK_SIZE - top;

	int i = top - 1;
	while(i >= 0)
	{
		printf("[ %d ]\n", stack[i]);
		i--;	
	}

	printf("stack spaces left:: %d\n", spaces_remaining);
	return;
}
