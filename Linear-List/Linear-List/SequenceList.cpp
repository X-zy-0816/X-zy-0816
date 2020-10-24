//
//  SequenceList.cpp
//  Linear-List
//
//  Created by 徐致远 on 2019/9/17.
//  Copyright © 2019 徐致远. All rights reserved.
//

#include "SequenceList.h"

/*
 * 初始化顺序表
 * @param seqList    要初始化的顺序表
 * @param elemArray  初始化时要添加的元素内容数组
 * @param length     初始化时添加的元素个数
 */
void InitList(SeqList * seqList, ElementType * elemArray, int length)
{
    if(length > MAX_SIZE){
        printf("error: 超出了最大容量\n");
    }
    for(int i = 0; i < length; i++){
        InsertElement(seqList, i, elemArray[i]);
    }
}

/*
 * 在顺序表中插入新元素
 * @param seqList    要插入的的顺序表
 * @param index      插入位置的下标
 * @param element    要插入的元素
 */
void InsertElement(SeqList * seqList, int index, ElementType element)
{
    //1.验证插入后的元素空间是否小于MAX_SIZE
    //2.index的值是否合法[0, MAX_SIZE - 1]
    if(seqList->length + 1 >= MAX_SIZE){
        printf("error: 数组已满\n");
        return;
    }
    if(index < 0 || index > MAX_SIZE - 1){
        printf("error: 下标越界, [%d, %d]\n",0, MAX_SIZE - 1);
        return;
    }
    if(index > seqList->length){
        printf("error: 插入的下标超过了数组的最大长度 - 1， 插入失败\n");
        return;
    }
    for(int i = seqList->length - 1; i >= index; i--){
        seqList->datas[i + 1] = seqList->datas[i];
    }
    //插入元素
    seqList->datas[index] = element;
    //顺序表长度+1
    seqList->length += 1;
    
}

/*
 * 在顺序表中删除元素
 * @param seqList    要操作的的的顺序表
 * @param index      删除位置的下标
 */
void  DeleteElement(SeqList * seqList, int index){
    if(index > MAX_SIZE- 1 || index < 0){
        printf("error: 下标越界\n");
        return;
    }
    if(index > seqList->length - 1){
        printf("error: 删除的位置为空\n");
        return;
    }
    for(int i = index; i < seqList->length; i++){
        seqList->datas[i] = seqList->datas[i + 1];
    }
    seqList->length--;
}

/*
 *查找元素
 */
void SearchList(SeqList * seqList, int index){
    if(index > seqList->length || index < 0){
        printf("error: 无下标错误\n");
        return;
    }
    printf("%d\t%s\n",seqList->datas[index].id,seqList->datas[index].name);
}

/*
 *打印顺序表
 */
void PrintList(SeqList * seqList){
    for(int i = 0; i < seqList->length; i++){
        printf("%d\t %s\n",seqList->datas[i].id, seqList->datas[i].name);
    }
}

