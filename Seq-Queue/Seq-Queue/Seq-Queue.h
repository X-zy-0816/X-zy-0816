//
//  Seq-Queue.h
//  Seq-Queue
//
//  Created by 徐致远 on 2019/11/5.
//  Copyright © 2019 徐致远. All rights reserved.
//

#ifndef Seq_Queue_h
#define Seq_Queue_h

#include "ElementType.h"
#define STATE_OK 1
#define STATE_FAILD -1

typedef int State;      //表示状态

typedef struct {
    int front;          //队头指针
    int rear;           //队尾指针
    int length;
    ElementType data[MAX_SIZE];
}SeqQueue;

/**初始化队列*/
void InitSeqQueue(SeqQueue * seqQueue);

/**入队*/
State OfferSeqQueue(SeqQueue * seqQueue, ElementType element);

/**出队*/
State PollSeqQueue(SeqQueue * seqQueue, ElementType * element);

/**队列是否为空（以TRUE/FALSE方式返回）*/
State IsSqeQueueEmp(SeqQueue * seqQueue);

/**队列是否为满（以TRUE/FALSE方式返回）*/
State IsSqeQueueFull(SeqQueue * seqQueue);


#endif /* Seq_Queue_h */
