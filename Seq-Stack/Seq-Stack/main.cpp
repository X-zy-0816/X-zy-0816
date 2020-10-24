//
//  main.cpp
//  Seq-Stack
//
//  Created by 徐致远 on 2019/10/26.
//  Copyright © 2019 徐致远. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Seq-Stack.h"

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
    SeqStack * seqStack = (SeqStack *)malloc(sizeof(SeqStack));
    ElementType * element = (ElementType *)malloc(sizeof(ElementType));
    InitSeqStack(seqStack);
    for(int i = 0; i < 4; i++){
        printf("当前入栈元素: %d %s\n",datas[i].id, datas[i].name);
        PushSeqStack(seqStack, datas[i]);
    }
    PopSeqStack(seqStack, element);
    printf("当前出栈元素: %d %s\n",element->id, element->name);
    
    for(int i = 0; i < seqStack->length; i++){
        printf("当前栈内元素: %d %s\n",seqStack->elemens[i].id, seqStack->elemens[i].name);
    }
    free(seqStack);
}

