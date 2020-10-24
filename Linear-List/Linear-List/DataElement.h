//
//  DataElement.h
//  Linear-List
//
//  Created by 徐致远 on 2019/9/17.
//  Copyright © 2019 徐致远. All rights reserved.
//

#ifndef DataElement_h
#define DataElement_h

#define MAX_SIZE 255

//1.定义数据元素
typedef struct {
    int id;
    char * name;
}ElementType;

//2.定义顺序表结构
typedef struct {
    ElementType datas[MAX_SIZE];    //顺序表中的数据元素集合
    int length;                     //顺序表中的元素个数
}SeqList;

#endif /* DataElement_h */
