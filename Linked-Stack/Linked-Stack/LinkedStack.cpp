//
//  LinkedStack.cpp
//  Linked-Stack
//
//  Created by 徐致远 on 2019/10/27.
//  Copyright © 2019 徐致远. All rights reserved.
//

#include <stdio.h>
#include "LinkedStack.h"

/**初始化链栈*/
void InitLinkedStack(LinkedStack * linkedStack){
    linkedStack->length = 0;
    linkedStack->top = NULL;
}

/**入栈*/
void PushLinkedStack(LinkedStack * linkedStack, ElementType element){
    StackNode * node = (StackNode *)malloc(sizeof(StackNode));
    node->data = element;
    node->next = linkedStack->top;
    linkedStack->top = node;
    linkedStack->length++;
}

/**出栈*/
void PopLinkedStack(LinkedStack * linkedStack, ElementType * element){
    if(linkedStack->top == NULL){
        printf("error: 空栈\n");
        return;
    }
    //返回出栈元素
    * element = linkedStack->top->data;
    //临时指针
    StackNode * tempNode = linkedStack->top;
    linkedStack->top = linkedStack->top->next;
    free(tempNode);
    linkedStack->length--;
}

/**清空栈-遍历栈中的每个元素并释放空间*/
void ClearLinkedStack(LinkedStack * linkedStack){
    StackNode * tempNode;
    while(linkedStack->top != NULL){
        tempNode = linkedStack->top;
        linkedStack->top = linkedStack->top->next;
        free(tempNode);
        linkedStack->length--;
    }
}

/**销毁栈*/
void DestroyLinkedStack(LinkedStack * linkedStack){
    ClearLinkedStack(linkedStack);
    free(linkedStack);
    linkedStack = NULL;
}
