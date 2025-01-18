#include "stack.h"

void push(int n)	
{
	if(top < size)
	{
	stack[top] = n;
	top++;
	}
	else
		printf("\npush failed check if stack is full");	
}
int pop(void)
{
	if(top == 0)
	{
		printf("\npop failed, check if stack is empty");
		return -1;
	}
	else
	{
	//set postion to 0 before returning (pop out) extra and probably not needed
	int store = stack[top];
	stack[top] = 0;
	top--; 
	return store;
	}
}
void clear(void)
{
	for(; top > 0; top--)
		stack[top] = 0;
}
void dupe(int dupes)
{
	//requested to many dupes
	int dupe_value;
	if(top + dupes > size)
	{
		printf("\nrequested to many dupes for size\n");
	}
	else
	{
		dupe_value = stack[top - 1];
		while(dupes > 0)
		{
			stack[top++] = dupe_value;
			dupes--;
		}
	}
}
void print(void)
{
	for(int i = top; i >= 0; i--)
	{
		if(i == top)
		{
			printf("\n[x]");
		}
		else
			printf("\n[%d]", stack[i]);
	}
	
	printf("\ntop of stack is position %d", top);
}
bool check_full(void)
{
	if(top == size)
	{ 
		return true;
	}
	else 
	{ 
		printf("\nyou are [%d] positions away from full\n", size - 1 - top);
		return false;
	}
}
bool check_empty(void)
{
	if(top == 0)
	{
		return true;
	}
	else
	{
		printf("\nyou are [%d] positions away from empty\n", top);
		return false;
	}
}
