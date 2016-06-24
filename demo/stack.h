/**
 * 堆栈模块接口
 */

//堆栈存储类型
#define STACK_TYPE int

/**
 * push
 * 把一个元素压入堆栈中
 */
void push(STACK_TYPE value);

/**
 * pop
 * 从堆栈中弹出一个值
 */
STACK_TYPE pop(void);

/**
 * top
 * 返回堆栈顶部的元素，但不对其进行修改
 */
STACK_TYPE top(void);

/**
 * is_empty
 * 堆栈是否为空
 */
int is_empty(void);

/**
 * is_full
 * 堆栈是否已满
 */
int is_full(void);


/**
 * 动态数组方式实现堆栈
 */

/**
 * create_stack
 * 创建堆栈，参数可以指定多少个元素
 */
void create_stack(size_t size);

/**
 * destroy_stack
 * 销毁堆栈，释放堆栈所使用的内存
 */
void destroy_stack(void);
