//
//  LinkedStack.h
//  Linked-Stack
//
//  Created by 徐致远 on 2019/10/27.
//  Copyright © 2019 徐致远. All rights reserved.
//

#ifndef LinkedStack_h
#define LinkedStack_h
#include "ElementType.h"
#include <stdio.h>
#include <stdlib.h>

/**定义链栈的节点*/
typedef struct StackNode{
    ElementType data;
    struct StackNode * next;    //下一个节点
}StackNode;

/**定义链栈结构*/
typedef struct {
    StackNode * top;    //栈顶指针
    int length;
}LinkedStack;

/**初始化链表*/
void InitLinkedStack(LinkedStack * linkedStack);

/**入栈*/
void PushLinkedStack(LinkedStack * linkedStack, ElementType element);

/**出栈*/
void PopLinkedStack(LinkedStack * linkedStack, ElementType * element);

/**清空栈-遍历栈中的每个元素并释放空间*/
void ClearLinkedStack(LinkedStack * linkedStack);

/**销毁栈*/
void DestroyLinkedStack(LinkedStack * linkedStack);
#endif /* LinkedStack_h */
