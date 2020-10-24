//
//  main.cpp
//  Linked-Stack
//
//  Created by 徐致远 on 2019/10/27.
//  Copyright © 2019 徐致远. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

ElementType datas[] = {
    {1, "A"},
    {2, "B"},
    {3, "C"},
    {4, "D"},
    {5, "E"}
};

void TextSeqStack();

int main(){
    
    TextSeqStack();
    return 0;
}

void TextSeqStack(){
    LinkedStack * linkedStack = (LinkedStack *)malloc(sizeof(LinkedStack));
    ElementType * element = (ElementType *)malloc(sizeof(ElementType));
    InitLinkedStack(linkedStack);
    for(int i = 0; i < 5; i++){
        PushLinkedStack(linkedStack, datas[i]);
        printf("入栈元素%d %s\n",datas[i].id, datas[i].name);
    }
    PopLinkedStack(linkedStack, element);
    printf("%d, %s",element->id, element->name);
    
//    DestroyLinkedStack(linkedStack);
//    printf("%s",linkedStack->top);
}
