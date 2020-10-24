//
//  main.cpp
//  Seq-Queue
//
//  Created by 徐致远 on 2019/11/5.
//  Copyright © 2019 徐致远. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Seq-Queue.h"

ElementType dataArray[] = {
    {1, "A"},
    {2, "B"},
    {3, "C"},
    {4, "D"},
    {5, "E"}
};

void TestSeqQueue(){
    SeqQueue * seqQueue = (SeqQueue *)malloc(sizeof(SeqQueue));
    InitSeqQueue(seqQueue);
    OfferSeqQueue(seqQueue, dataArray[0]);
    OfferSeqQueue(seqQueue, dataArray[1]);
    OfferSeqQueue(seqQueue, dataArray[2]);
    for(int i = 0; i < seqQueue->length; i++){
        printf("%d\t%s\n",seqQueue->data[i].id, seqQueue->data[i].name);
    }
    ElementType * element = (ElementType *)malloc(sizeof(ElementType));
    PollSeqQueue(seqQueue, element);
    printf("打印出队元素:\n");
    printf("%d\t%s\n",element->id, element->name);
    printf("出队后：\n");
    for(int i = seqQueue->front; i < seqQueue->rear; i++){
        printf("%d\t%s\n",seqQueue->data[i].id, seqQueue->data[i].name);
    }
    
}
int main(){
    TestSeqQueue();
    
    return 0;
}
