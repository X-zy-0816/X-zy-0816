//
//  Seq-Stack.cpp
//  Seq-Stack
//
//  Created by 徐致远 on 2019/10/26.
//  Copyright © 2019 徐致远. All rights reserved.
//

#include <stdio.h>
#include "Seq-Stack.h"

/** 初始化栈*/
void InitSeqStack(SeqStack * seqStack){
    seqStack->top = -1; //栈顶指向-1的下标
    seqStack->length = 0;
}

/**入栈 返回压入的结果*/
int PushSeqStack(SeqStack * seqStack, ElementType element){
    if(seqStack->top == MAX_SIZE - 1){
        printf("error: 满栈\n");
        return FALSE;
    }
    seqStack->top++;
    seqStack->elemens[seqStack->top] = element;
    seqStack->length++;
    return TRUE;
}

/**出栈 指针方式返回出栈的远元素*/
int PopSeqStack(SeqStack * seqStack, ElementType * element){
    if(seqStack->top == -1){
        printf("error: 空栈\n");
        return FALSE;
    }
    *element = seqStack->elemens[seqStack->top];    //返回栈顶元素
    seqStack->top--;
    seqStack->length--;
    return TRUE;
}

 /**清空栈*/
void ClearSeqStack(SeqStack * seqStack){
    seqStack->top = -1;
    seqStack->length = 0;
}

/**栈是否为空*/
void IsEmpty(SeqStack * seqStack){
    if(seqStack->top == -1){
        printf("栈为空\n");
    }else{
        printf("栈不为空\n");
    }
}
