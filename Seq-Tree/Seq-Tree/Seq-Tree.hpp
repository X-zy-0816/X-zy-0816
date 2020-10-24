//
//  Seq-Tree.hpp
//  Seq-Tree
//
//  Created by 徐致远 on 2019/11/12.
//  Copyright © 2019 徐致远. All rights reserved.
//

#ifndef Seq_Tree_hpp
#define Seq_Tree_hpp

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_SIZE 255
/**定义顺序树类型*/
typedef char SeqTree[MAX_SIZE];

/**初始化二叉树*/
void InitSeqTree(SeqTree tree);

/**创建树*/
void CreateSeqTree(SeqTree tree, int i);

#endif /* Seq_Tree_hpp */
