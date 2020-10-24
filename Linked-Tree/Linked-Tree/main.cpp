//
//  main.cpp
//  Linked-Tree
//
//  Created by 徐致远 on 2019/11/18.
//  Copyright © 2019 徐致远. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Linked-Tree.hpp"
int main(){
    BinaryTree T;
    CreateTree(T);
    printf("前序遍历:\n");
    PreOrder(T);
    printf("\n中序遍历:\n");
    InOrder(T);
    printf("\n后序遍历:\n");
    PostOrder(T);
    return 0;
}
