//
//  Seq-Stack.h
//  Seq-Stack
//
//  Created by 徐致远 on 2019/10/26.
//  Copyright © 2019 徐致远. All rights reserved.
//

#ifndef Seq_Stack_h
#define Seq_Stack_h

#include "ElementType.h"
#include <stdio.h>
#include <stdlib.h>

/** 定义栈的顺序存储方式*/
typedef struct SeqStack{
    ElementType elemens[MAX_SIZE];  //顺序栈中存放数据元素的数组
    int top;                        //栈顶(数组中的下标)，若为-1则为空
    int length;                     //栈的元素个数
}SeqStack;

/** 初始化栈*/
void InitSeqStack(SeqStack * seqStack);

/**入栈 返回压入的结果*/
int PushSeqStack(SeqStack * seqStack, ElementType element);
#endif /* Seq_Stack_h */

/**出栈 指针方式返回出栈的远元素*/
int PopSeqStack(SeqStack * seqStack, ElementType * element);

/**清空栈*/
void ClearSeqStack(SeqStack * seqStack);

/**栈是否为空*/
void IsEmpty(SeqStack * seqStack);
