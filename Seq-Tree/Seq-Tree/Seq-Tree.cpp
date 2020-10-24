//
//  Seq-Tree.cpp
//  Seq-Tree
//
//  Created by 徐致远 on 2019/11/12.
//  Copyright © 2019 徐致远. All rights reserved.
//

#include "Seq-Tree.hpp"
/**初始化二叉树*/
void InitSeqTree(SeqTree tree){
    for(int i = 0; i < MAX_SIZE; i++){
        tree[i] = '\0';
    }
}

/**创建树   此处i表示数组下标*/
void CreateSeqTree(SeqTree tree, int i){
    char ch;
    ch = getchar();
    fflush(stdin);
    if(ch == '^'){
        return;
    }
    tree[i] = ch;
    printf("左孩子节点:");
    CreateSeqTree(tree, 2 * i + 1);
    printf("右孩子节点:");
    CreateSeqTree(tree, 2 * (i + 1));
}
