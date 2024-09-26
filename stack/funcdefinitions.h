#if !defined FUNCDEFINITIONS_H
#define FUNCDEFINITIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t	 U8;
typedef uint16_t U16;
typedef uint32_t U32;
typedef uint64_t U64;

typedef int8_t  S8;
typedef int16_t S16;
typedef int32_t S32;
typedef int64_t S64;

/* -------------------------- */

void push(int number);
int pop(void);
bool check_empty(void);
bool check_full(void);
void clear(void);
void stack_print(void);

#endif



