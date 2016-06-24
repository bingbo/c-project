

/**
 * 静态数组实现方式，数组的长度只能通过修改#define定义
 */

#include "stack.h"
#include <assert.h>

//堆栈中值的最大限制
#define     STACK_SIZE      100

//堆栈数组
static      STACK_TYPE      stack[STACK_SIZE];
//堆栈顶部元素指针
static      int             top_element = -1;          

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
    return static[top_element];
}

/**
 * is_empty
 */
int is_empty(void){
    return top_element == -1;
}

/**
 * is_full
 */
int is_full(void){
    return top_element == STACK_SIZE - 1;
}
