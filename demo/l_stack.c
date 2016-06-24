/**
 * 一个用链表实现的堆栈，这个堆栈没有长度限制
 */

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#define FALSE 0

/**
 * 定义堆栈元素结构
 */
typedef struct stack_node{
    STACK_TYPE  value;
    struct  struct_node *next;
} StackNode;

//指向第一个结点的指针
static  StackNode   *stack;

/**
 * create_stack
 */
void create_stack(size_t size){}

/**
 * destroy_stack
 */
void destroy_stack(void){
    while(!is_empty()){
        pop();
    }
}

/**
 * push
 */
void push(STACK_TYPE value){
    StackNode *node = malloc(sizeof(StackNode));
    assert(node != NULL);
    node->value = value;
    node->next = stack;
    stack = node;
}

/**
 * pop
 */
STACK_TYPE pop(void){
    assert(!is_empty());
    StackNode *first = stack;
    stack = first->next;
    STACK_TYPE res = fisrt->value;
    return res;
}

/**
 * top
 */
STACK_TYPE top(void){
    assert(!is_empty());
    return stack->value;
}

/**
 * is_empty
 */
int is_empty(void){
    return stack == NULL;
}

/**
 * is_full
 */
int is_full(void){
    return FALSE;
}
