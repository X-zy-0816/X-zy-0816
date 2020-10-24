//
//  Head-String.cpp
//  Heap-String
//
//  Created by 徐致远 on 2019/11/7.
//  Copyright © 2019 徐致远. All rights reserved.
//

#include "Head-String.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 255
/**初始化堆字符串*/
void InitHeapString(HString * str){
    str->ch = NULL;
    str->length = 0;
}

/**为str赋值*/
State HeapStringAssign(HString * str, char * chars){
    int len = strlen(chars);
    if(!len){
        return STATE_FAILD;
    }
    InitHeapString(str);
    str->ch = (char *)malloc(len * sizeof(char));
    if(!str->ch){
        printf("error: 空间已满\n");
    }
    for(int i = 0; i < len; i++){
        str->ch[i] = chars[i];
    }
    str->length = len;
    return STATE_OK;
}

/**复制字符串*/
State HeapStringCopy(HString * str, HString * targetStr){
    InitHeapString(targetStr);
    if(!str->length){
        printf("error: 空\n");
        return STATE_FAILD;
    }
    targetStr->ch = (char *)malloc(str->length * sizeof(char));
    if(!targetStr->ch){
        return STATE_FAILD;
    }
    for(int i = 0 ; i < str->length; i++){
        targetStr->ch[i] = str->ch[i];
    }
    targetStr->length = str->length;
    
    return STATE_OK;
}


/**打印串*/
void PrintHeapString(HString * str){
    if(!str->length){
        printf("error: 串为空\n");
        return;
    }
    for(int i = 0 ; i < str->length; i++){
        printf("%c",str->ch[i]);
    }
}


/**（KMP算法）Next函数 */
void Get_Next(HString * str, int * next){
    int i = 0;
    int j = -1;
    next[0] = -1;
    while(i < str->length){
        if(j == -1 || str->ch[i] == str->ch[j]){
            ++i;
            ++j;
            next[i] = j;
        }else{
            j = next[j];
        }
    }
}

/** KMP算法 */
void KMP_Algorithm(HString * father, HString * child, int pos){//pos为位置，不是下标
    int i = pos - 1;
    int j = 0;
    int next[MAX_SIZE];
    Get_Next(child, next);
    while(i < father->length && j < child->length){
        if(j == -1 || father->ch[i] == child->ch[j]){
            ++i;
            ++j;
        }else{
            j = next[j];
        }
    }
    if(j == child->length){
        printf("%d\n",i - j + 1);
    }else{
        printf("error: 无匹配串\n");
    }
}
