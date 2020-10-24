//
//  Seq-Queue.cpp
//  Seq-Queue
//
//  Created by 徐致远 on 2019/11/5.
//  Copyright © 2019 徐致远. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Seq-Queue.h"

/**初始化队列*/
void InitSeqQueue(SeqQueue * seqQueue){
    if(seqQueue == NULL){
        seqQueue = (SeqQueue *)malloc(sizeof(SeqQueue));
    }
    seqQueue->front = 0;
    seqQueue->rear = 0;
    seqQueue->length = 0;
}

/**入队*/
State OfferSeqQueue(SeqQueue * seqQueue, ElementType element){
    if(IsSqeQueueFull(seqQueue)){
        return STATE_FAILD;
    }
    seqQueue->data[seqQueue->rear] = element;
    seqQueue->rear = (seqQueue->rear + 1) % MAX_SIZE;
    seqQueue->length++;
    return STATE_OK;
}

/**出队*/
State PollSeqQueue(SeqQueue * seqQueue, ElementType * element){
    if(IsSqeQueueEmp(seqQueue)){
        return STATE_FAILD;
    }
    * element = seqQueue->data[seqQueue->front];
    seqQueue->front = (seqQueue->front + 1) % MAX_SIZE;
    seqQueue->length--;
    return STATE_OK;
}

/**队列是否为空（以TRUE/FALSE方式返回）*/
State IsSqeQueueEmp(SeqQueue * seqQueue){
    return seqQueue->front == seqQueue->rear ? TRUE : FALSE;
}

/**队列是否为满（以TRUE/FALSE方式返回）*/
State IsSqeQueueFull(SeqQueue * seqQueue){
    if((seqQueue->rear + 1) % MAX_SIZE == seqQueue->front){
        return TRUE;
    }
    return FALSE;
}
