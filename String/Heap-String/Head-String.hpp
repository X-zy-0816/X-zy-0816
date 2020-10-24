//
//  Head-String.hpp
//  Heap-String
//
//  Created by 徐致远 on 2019/11/7.
//  Copyright © 2019 徐致远. All rights reserved.
//

#ifndef Head_String_hpp
#define Head_String_hpp

#define STATE_OK 1
#define STATE_FAILD -1

typedef int State;      //表示状态

#include <stdio.h>
#include <stdlib.h>

//定义堆串(heap string)
typedef struct {
    char * ch;
    int length;
}HString;

/**初始化堆字符串*/
void InitHeapString(HString * str);

/**为str赋值*/
State HeapStringAssign(HString * str, char * chars);

/**打印串*/
void PrintHeapString(HString * str);

/**复制字符串*/
State HeapStringCopy(HString * str, HString * targetStr);

/**（KMP算法）Next函数*/
void Get_Next(HString * str, int * next);

/**KMP算法*/
void KMP_Algorithm(HString * father, HString * child, int pos);
#endif /* Head_String_hpp */
