//
//  Linked-Tree.cpp
//  Linked-Tree
//
//  Created by 徐致远 on 2019/11/18.
//  Copyright © 2019 徐致远. All rights reserved.
//

#include "Linked-Tree.hpp"
#include <stdio.h>
#include <stdlib.h>

/**创建树*/
void CreateTree(BinaryTree &T){
    char c;
    c = getchar();
    if(c == '#'){
        T = NULL;
    }else{
        T = new BinaryNode;
        T->ch = c;
        CreateTree(T->LN);
        CreateTree(T->RN);
    }
}

/**先序遍历 TLR*/
void PreOrder(BinaryTree T){
    if(T){
        printf("%c",T->ch);
        PreOrder(T->LN);
        PreOrder(T->RN);
    }
}
/**中序遍历 LTR*/

void InOrder(BinaryTree T){
    if(T){
        PreOrder(T->LN);
        printf("%c",T->ch);
        PreOrder(T->RN);
    }
}

/**后序遍历 LRT*/
void PostOrder(BinaryTree T){
    if(T){
        PreOrder(T->LN);
        PreOrder(T->RN);
        printf("%c",T->ch);
    }
}
    
