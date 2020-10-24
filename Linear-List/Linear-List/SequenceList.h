//
//  SequenceList.h
//  Linear-List
//
//  Created by 徐致远 on 2019/9/17.
//  Copyright © 2019 徐致远. All rights reserved.
//

#ifndef SequenceList_h
#define SequenceList_h

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"
/*
 * 初始化顺序表
 * @param seqList    要初始化的顺序表
 * @param elemArray  初始化时要添加的元素内容数组
 * @param length     初始化时添加的元素个数
 */
void InitList(SeqList * seqList, ElementType * elemArray, int length);

/*
 * 在顺序表中插入新元素
 * @param seqList    要插入的的顺序表
 * @param index      插入位置的下标
 * @param element    要插入的元素
 */
void InsertElement(SeqList * seqList, int index, ElementType element);

/*
 * 在顺序表中删除元素
 * @param seqList    要操作的的的顺序表
 * @param index      删除位置的下标
 */
void  DeleteElement(SeqList * seqlist, int index);

/*
 *打印顺序表
 */
void PrintList(SeqList * seqList);

/*
 *查找元素
 */
void SearchList(SeqList * seqList, int index);
#endif /* SequenceList_h */
