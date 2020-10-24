//
//  main.cpp
//  Linear-List
//
//  Created by 徐致远 on 2019/9/17.
//  Copyright © 2019 徐致远. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include "SequenceList.h"

/*
 ADT
    线性表(List)
 Data
    线性表的数据对象集合为{a1,a2,a3,…,an},每个元素的类型均为 DataType。其中
    除了第一个元素a1外,每个元素有且只有一个直接前驱元素;
    除了最后一个元素an外,每个元素有且只有一个直接后继元素;
    数据元素之间的关系是一对一的关系
 Operation
    InitList(L)
        初始化线性表,建立一个空的线性表L
    IsEmpty(L)
        若线性表为空,返回TRUE,否则返回 FALSE
    ClearList(*L):
        将线性表清空
    GetElem(L, i *e):
        将线性表L中第i个位置的数据元素返回给e
    ExsitElem(L,e):
        在线性表L中査找是否存在数据元素e,存在则返回该元素在表中的下标不存在返回-1
    InsertElem(*L,i,e):
        在线性表L中第i个位置插入新元素e
    Deleteelem(*L,i,*e):
        删除线性表L中第i个位置的元素,并用e返回其值
    GetLength(L):
        返回线性表L中的元素个数
endADT
 
 */

ElementType dataArray[] = {
    {1, "A"},
    {2, "B"},
    {3, "C"},
    {4, "D"},
    {5, "E"}
};

void TestSequenceList();

void TestSequenceList(){
    SeqList seqList;
    InitList(&seqList, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
    printf("顺序表为：\n");
    
  //  InsertElement(&seqList, 2, {999, "NB"});
  //  DeleteElement(&seqList, 3);
  //  SearchList(&seqList, 3);
    PrintList(&seqList);
}

int main(){
    TestSequenceList();
    
    return 0;
}
