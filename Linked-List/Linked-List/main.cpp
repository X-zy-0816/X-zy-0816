//
//  main.cpp
//  Linked-List
//
//  Created by 徐致远 on 2019/9/19.
//  Copyright © 2019 徐致远. All rights reserved.
//
/*
 * 链表包括数据域和指针域
 * 指针域指向下一个节点（结构体指针指向下一个结构体）
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

ElementType dataArray[] = {
    {1, "A"},
    {2, "B"},
    {3, "C"}
};

void TestLinkedList(){
    LinkList linkList;
    InitLinkList(&linkList, dataArray,  sizeof(dataArray)/sizeof(dataArray[0]));
    printf("链表为：\n");
    PrintLinkList(&linkList);
//    插入元素
//    InsertLinkList(&linkList, 1, {99, "NB"});
//    倒置
    printf("倒置后为：\n");
  InversionLinkList(&linkList);
//    元素查找
//   ElementType a = GetElement(&linkList, 3);
//   printf("%d\t%s\n",a.id, a.name);
//
//    删除结点
//    DeleteLinkListElement(&linkList, 2);
    PrintLinkList(&linkList);
}
int main()
{
    TestLinkedList();
    return 0;
}
