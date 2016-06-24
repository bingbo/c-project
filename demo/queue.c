/**
 * 一个用静态数组实现的队列，数组长度通过#define来调整
 */

#include "queue.h"
#include <stdio.h>
#include <assert.h>

//队列中元素的最大数量
#define QUEUE_SIZE  100
//数组的长度
#define ARRAY_SIZE  (QUEUE_SIZE + 1)

//存储队列元素的数组
static  QUEUE_TYPE  queue[ARRAY_SIZE];
//队头指针
static  size_t  front = 1;
//队尾指针
static  size_t  rear = 0;

/**
 * insert
 */
void insert(QUEUE_TYPE value){
    assert(!is_full());
    rear = (rear + 1) % ARRAY_SIZE;
    queue[rear] = value;
}

/**
 * delete
 */
void delete(void){
    assert(!is_empty());
    front = (front + 1) % ARRAY_SIZE;
}

/**
 * first
 */
QUEUE_TYPE first(void){
    assert(!is_empty());
    return queue[front];
}

/**
 * is_empty
 */
int is_empty(void){
    return (rear + 1) % ARRAY_SIZE == front;
}

/**
 * is_full
 */
int is_full(void){
    return (rear + 2) % ARRAY_SIZE == front;
}
