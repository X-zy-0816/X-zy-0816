//
//  LinkedList.cpp
//  Linked-List
//
//  Created by 徐致远 on 2019/9/19.
//  Copyright © 2019 徐致远. All rights reserved.
//

#include <stdio.h>
#include "LinkedList.h"

/*
 * 初始化链表
 */
void InitLinkList(LinkList * linkList, ElementType * dataArray, int length){
    for(int i = 0; i < length; i++){
        InsertLinkList(linkList, i + 1, dataArray[i]);
    }
}

/*
 * 插入元素(尾插法)
 * @parm postion插入元素的位置
 */
void InsertLinkList(LinkList * linkList, int position, ElementType element){
    //1.创建空结点(malloc)并为数据域赋值
    Node * node = (Node *)malloc(sizeof(Node));
    node->data = element;
    node->next = NULL;
    
    //2.找到插入位置的结点
    if(position == 1){//如果插入的是第一个结点
        node->next = linkList->next;
        linkList->next = node;
        linkList->length++;
        return;
    }
    Node * currNode = linkList->next;//声明临时变量
    for(int i = 1; i < position - 1 && currNode; i++){//临时变量后移
        currNode = currNode->next;
    }
    
    //3.结点的插入和对接前面的结点
    if(currNode){
        node->next = currNode->next;
        currNode->next = node;
        linkList->length++;
    }
}

/*
 *倒置单链表
 */
void InversionLinkList(LinkList * linkList){
    Node * p;
    Node * q;
    p = linkList->next;
    linkList->next = NULL;
    while(p){
        q = p->next;
        p->next = linkList->next;
        linkList->next = p;
        p = q;
    }
}

/*
 *删除元素
 */
void DeleteLinkListElement(LinkList * linkList, int position){
    Node * node = linkList->next;
    if(position == 1){
        linkList->next = node->next;
        node = NULL;
        free(node);
        linkList->length--;
        return;
    }
    Node * preNode = NULL;//前置结点
    for(int i = 1; i < position && node; i++){
        preNode = node;
        node = node->next;
    }
    if(node){
        preNode->next = node->next;
        free(node);
        linkList->length--;
    }
}

/*
 *返回查找位置的元素
 */
ElementType GetElement(LinkList * linkList, int position){
    Node * node = linkList->next;
    for(int i = 1; i < position && node; i++){
        node = node->next;
    }
    return node->data;
}

/**打印链表*/
void PrintLinkList(LinkList * linkList){
    Node * node = linkList->next;
    if(!node){
        printf("error: 链表为空\n");
        linkList->length = 0;
        return;
    }
    for(int i = 0; i < linkList->length; i++){
        printf("%d\t%s\n",node->data.id, node->data.name);
        node = node->next;
    }
}
