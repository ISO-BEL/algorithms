#if !defined STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void push(int n);
int pop(void);
void clear(void);

void dupe(int dupes); 
void print(void);

bool check_full(void); 
bool check_empty(void); 

extern int *stack;
extern int top; 
extern int size;

#endif

