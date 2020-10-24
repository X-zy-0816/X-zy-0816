//
//  MatrixGraph.h
//  Graph
//
//  Created by 徐致远 on 2019/12/2.
//  Copyright © 2019 徐致远. All rights reserved.
//

#ifndef MatrixGraph_h
#define MatrixGraph_h

#include <stdio.h>
#include <stdlib.h>
#include "GraphModel.h"

/**图的邻接矩阵存储表示*/
typedef struct {
    VertexType vertex[MAX_VERTEX];           //顶点数组
    ArcType arcs[MAX_VERTEX][MAX_VERTEX];    //邻接数组
    int vertexCount;                         //顶点数
    int arcCount;                            //边(弧)数
    GraphKind kind;                          //图的种类
}MatrixGraph;

/**创建无向图*/
void CreateUDG(MatrixGraph * G);

/**创建有向图*/
void CreateDG(MatrixGraph * G);

/**创建有向网*/
void CreateDN(MatrixGraph * G);

/**创建无向网*/
void CreateUDN(MatrixGraph * G);

/** BFS 广度优先搜索 */
void BFS(MatrixGraph * G);

/** DFS 深度优先搜索  */
void DFS(MatrixGraph & G);

/**定位顶点在邻接矩阵中的位置*/
int LocateMatrix(MatrixGraph * G, VertexType vex);

/**打印图的邻接矩阵*/
void PrintMatrixGraph(MatrixGraph * G);
#endif /* MatrixGraph_h */
