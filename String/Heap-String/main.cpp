//
//  main.cpp
//  Heap-String
//
//  Created by 徐致远 on 2019/11/7.
//  Copyright © 2019 徐致远. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Head-String.hpp"
void testHeapString(){
    HString str, Tstr;
    HeapStringAssign(&str, "abcdefg");
    HeapStringCopy(&str, &Tstr);
    PrintHeapString(&str);
    printf("\n复制后:\n");
    PrintHeapString(&Tstr);
    
}

void KMPtest(){
    HString father, child;
    HeapStringAssign(&father, "ABCDEF");
    HeapStringAssign(&child, "A");
    KMP_Algorithm(&father, &child, 1);
    
}
int main(){
   // testHeapString();
    //  KMPtest();
    HString s;
    HeapStringAssign(&s, "abcaabbcabcaabdab");
    int next[100];
    memset(next, -9, 100);
    Get_Next(&s, next);
    for(int i = 0; i < 17; i++){
        printf("%d ",next[i] + 1);
    }
    return 0;
}
