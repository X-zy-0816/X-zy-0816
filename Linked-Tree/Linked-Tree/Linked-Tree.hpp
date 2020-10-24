//
//  Linked-Tree.hpp
//  Linked-Tree
//
//  Created by 徐致远 on 2019/11/18.
//  Copyright © 2019 徐致远. All rights reserved.
//

#ifndef Linked_Tree_hpp
#define Linked_Tree_hpp

#include <stdio.h>
#include <stdlib.h>

/**声明树节点，根节点*/
typedef struct TNode{
    struct TNode * LN;
    struct TNode * RN;
    char ch;
}BinaryNode, * BinaryTree;

/**创建树*/
void CreateTree(BinaryTree &T);
/**先序遍历 TLR*/
void PreOrder(BinaryTree T);
/**中序遍历 LTR*/
void InOrder(BinaryTree T);
/**后序遍历 LRT*/
void PostOrder(BinaryTree T);

#endif /* Linked_Tree_hpp */
