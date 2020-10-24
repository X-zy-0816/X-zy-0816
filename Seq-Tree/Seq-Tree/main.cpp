//
//  main.cpp
//  Seq-Tree
//
//  Created by 徐致远 on 2019/11/12.
//  Copyright © 2019 徐致远. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Seq-Tree.hpp"
void TestTree(){
    SeqTree tree;
    printf("输入根节点:\n");
    CreateSeqTree(tree, 0);
}
int main(){
    TestTree();
    return 0;
}
