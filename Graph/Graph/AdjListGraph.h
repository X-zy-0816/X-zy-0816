//
//  AdjListGraph.h
//  Graph
//
//  Created by 徐致远 on 2019/12/5.
//  Copyright © 2019 徐致远. All rights reserved.
//

#ifndef AdjListGraph_h
#define AdjListGraph_h

#include "GraphModel.h"
#include <stdio.h>
#include <stdlib.h>

/** 边/弧的结点 */
typedef struct node{
    int adjVex;                 //该边指向这条边邻接点的下标
    struct node * nextEdge;     //指向下一条边节点的指针
    struct node * nextArc;      //指向下一条弧节点的指针
    ArcType weight;             //权重
}EdgeNode, ArcNode;

/** 顶点结点 */
typedef struct vexNode{
    VertexType vex;             //顶点值
    EdgeNode * firstEdge;        //指向第一条边的指针
    ArcNode * firstArc;         //指向第一条弧的指针
}VexNode, AdjList[MAX_VERTEX];

/** 用邻接表表示法创建无向图  */
typedef struct adjGraph{
    AdjList vexes;              //顶点数组
    int vexCount;               //顶点数量
    int edgeCount;              //边的数量
    int arcCount;               //弧的数量
    GraphKind kind;             //图的类型
}AdjListGraph;

/** 初始化无向图邻接表 */
void CreateUDG_AdjList(AdjListGraph * G);

/** 初始化有向图邻接表 */
void CreateDG_AdjList(AdjListGraph * G);

/** 初始化无向网邻接表 */
void CreateUDN_AdjList(AdjListGraph * G);

/** 初始化有向网邻接表 */
void CreateDN_AdjList(AdjListGraph * G);

/** 打印无向邻接表的内容 */
void Print_AdjListUD(AdjListGraph * G);

/** 打印有向邻接表的内容 */
void Print_AdjListD(AdjListGraph * G);

/**定位*/
int LocateVex_AdjList(AdjListGraph *G, VertexType vex);

#endif /* AdjListGraph_h */
