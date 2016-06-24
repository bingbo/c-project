/**
 * 一个队列模块的接口
 */

#include <stdlib.h>

//队列元素类型
#define QUEUE_TYPE  int

/**
 * create_queue
 * 创建一个队列，参数指定队列的最大数量
 */
void create_queue(size_t size);

/**
 * destroy_queue
 * 销毁一个队列，这个函数只适用于链式和动态分配数组的队列
 */
void destroy_queue(void);

/**
 * insert
 * 向队列插入一个元素
 */
void insert(QUEUE_TYPE value);

/**
 * delete
 * 删除一个元素
 */
void delete(void);

/**
 * first
 * 返回第一个元素
 */
QUEUE_TYPE first(void);

/**
 * is_empty
 * 是否为空
 */
int is_empty(void);

/**
 * is_full
 * 是否已满
 */
int is_full(void);
