//
//  LinkedList.h
//  Linked-List
//
//  Created by 徐致远 on 2019/9/19.
//  Copyright © 2019 徐致远. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"

/*
 *定义链表的结点（数据域和指针域）
 */
typedef struct Node{
    ElementType data;       //数据域
    struct Node * next;     //指针域
}Node;

/*
 * 定义链表的头结点
 */
typedef struct LinkList{
    Node * next;
    int length;             //链表的长度
}LinkList;

/*
 * 初始化链表
 */
void InitLinkList(LinkList * linkList, ElementType * dataArray, int length);

/*
 * 插入元素(尾插法)
 * @parm postion插入元素的位置
 */
void InsertLinkList(LinkList * linkList, int position, ElementType element);

/*
 *倒置单链表
 */
void InversionLinkList(LinkList * linkList);

/*
 *删除元素
 */
void DeleteLinkListElement(LinkList * linkList, int position);

/*
 *返回查找位置的元素
 */
ElementType GetElement(LinkList * linkList, int position);

/*
 * 打印结点
 */
void PrintLinkList(LinkList * linkList);

#endif /* LinkedList_h */
