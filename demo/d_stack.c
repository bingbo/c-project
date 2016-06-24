/**
 * 一个用动态数组实现的堆栈
 */

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

//指向堆栈的指针
static      STACK_TYPE      *stack;
//堆栈大小
static      size_t          stack_size;
//堆栈头元素指针
static      int             top_element = -1;

/**
 * create_stack
 */
void create_stack(size_t size){
    assert(stack_size == 0);
    stack_size = size;
    stack = malloc(stack_size * sizeof(STACK_TYPE));
    assert(stack != NULL);
}

/**
 * destroy_stack
 */
void destroy_stack(void){
    assert(stack_size > 0);
    stack_size = 0;
    free(stack);
    stack = NULL;
}

/**
 * push
 */
void push(STACK_TYPE value){
    assert(!is_full());
    stack[++top_element] = value;
}

/**
 * pop
 */
STACK_TYPE pop(void){
    assert(!is_empty());
    return stack[top_element--];
}

/**
 * top
 */
STACK_TYPE top(void){
    assert(!is_empty());
    return stack[top_element];
}

/**
 * is_empty
 */
int is_empty(void){
    assert(stack_size > 0);
    return top_element == -1;
}

/**
 * is_full
 */
int is_full(void){
    assert(stack_size > 0);
    return top_element == stack_size -1;
}
