//
//  MatrixGraph.cpp
//  Graph
//
//  Created by 徐致远 on 2019/12/3.
//  Copyright © 2019 徐致远. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <stack>
#include "MatrixGraph.h"

using namespace std;
/**创建无向图*/
void CreateUDG(MatrixGraph * G){
    printf("创建无向图\n");
    G->kind = UDG;
    printf("输入顶点的个数:");
    scanf("%d",&G->vertexCount);
    printf("输入边的个数:");
    scanf("%d",&G->arcCount);
    printf("输入顶点信息:");
    for(int i = 0; i < G->vertexCount; i++){
        scanf("%s",&G->vertex[i]);
    }
    for(int i = 0; i < G->vertexCount; i++){
        for(int j = 0; j < G->vertexCount; j++){
            G->arcs[i][j] = 0;
        }
    }
    printf("输入顶点及邻接点，构建邻接矩阵\n");
    for(int i = 0; i < G->arcCount; i++){
        VertexType vex1, vex2;
        printf("顶点:");
        scanf("%s",&vex1);
        printf("邻接点:");
        scanf("%s",&vex2);
        int x = LocateMatrix(G, vex1);
        int y = LocateMatrix(G, vex2);
        G->arcs[x][y] = 1;
        G->arcs[y][x] = 1;
    }
}

/**创建有向图*/
void CreateDG(MatrixGraph * G){
    printf("创建有向图\n");
    G->kind = DG;
    printf("输入顶点的个数:");
    scanf("%d",&G->vertexCount);
    printf("输入弧的个数:");
    scanf("%d",&G->arcCount);
    printf("输入顶点信息:");
    for(int i = 0; i < G->vertexCount; i++){
        scanf("%s",&G->vertex[i]);
    }
    for(int i = 0; i < G->vertexCount; i++){
        for(int j = 0; j < G->vertexCount; j++){
            G->arcs[i][j] = 0;
        }
    }
    printf("输入顶点以及邻接点，构造邻接矩阵\n");
    for(int i = 0; i < G->arcCount; i++){
        VertexType vex1, vex2;
        printf("顶点:");
        scanf("%s",&vex1);
        printf("邻接点:");
        scanf("%s",&vex2);
        int x = LocateMatrix(G, vex1);
        int y = LocateMatrix(G, vex2);
        G->arcs[x][y] = 1;
    }
}

/**创建有向网*/
void CreateDN(MatrixGraph * G){
    printf("创建有向网\n");
    G->kind = DN;
    printf("输入顶点的个数:");
    scanf("%d",&G->vertexCount);
    printf("输入弧的个数:");
    scanf("%d",&G->arcCount);
    printf("输入顶点信息:");
    for(int i = 0; i < G->vertexCount; i++){
        scanf("%s",&G->vertex[i]);
    }
    for(int i = 0; i < G->vertexCount; i++){
        for(int j = 0; j < G->vertexCount; j++){
            G->arcs[i][j] = -1;
        }
    }
    printf("输入顶点以及邻接点，构造邻接矩阵\n");
    for(int i = 0; i < G->arcCount; i++){
        VertexType vex1, vex2;
        printf("顶点:");
        scanf("%s",&vex1);
        printf("邻接点:");
        scanf("%s",&vex2);
        int x = LocateMatrix(G, vex1);
        int y = LocateMatrix(G, vex2);
        int num;
        printf("输入权值:");
        scanf("%d",&num);
        G->arcs[x][y] = num;
    }
}

/**创建无向网*/
void CreateUDN(MatrixGraph * G){
    printf("创建无向网\n");
       G->kind = DN;
       printf("输入顶点的个数:");
       scanf("%d",&G->vertexCount);
       printf("输入弧的个数:");
       scanf("%d",&G->arcCount);
       printf("输入顶点信息:");
       for(int i = 0; i < G->vertexCount; i++){
           scanf("%s",&G->vertex[i]);
       }
       for(int i = 0; i < G->vertexCount; i++){
           for(int j = 0; j < G->vertexCount; j++){
               G->arcs[i][j] = -1;
           }
       }
       printf("输入顶点以及邻接点，构造邻接矩阵\n");
       for(int i = 0; i < G->arcCount; i++){
           VertexType vex1, vex2;
           printf("顶点:");
           scanf("%s",&vex1);
           printf("邻接点:");
           scanf("%s",&vex2);
           int x = LocateMatrix(G, vex1);
           int y = LocateMatrix(G, vex2);
           int num;
           printf("输入权值:");
           scanf("%d",&num);
           G->arcs[x][y] = num;
           G->arcs[y][x] = num;
       }
}

/** BFS 广度优先搜索 */
void BFS(MatrixGraph * G){
    printf("调用BFS:\n");
    memset(visited, false, MAX_VERTEX);
    queue<int> Q;
    for(int i = 0; i < G->vertexCount; i++){
        if(!visited[i]){
            visited[i] = true;
            printf(" %s ",G->vertex[i]);
            Q.push(i);
            while(!Q.empty()){
                int m = Q.front();
                Q.pop();
                for(int j = 0; j < G->vertexCount; j++){
                    if(G->arcs[m][j] != 0 && !visited[j]){
                        printf(" %s ",G->vertex[j]);
                        Q.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
    }
    printf("\n");
}

/** DFS 深度优先搜索  */
void DFS(MatrixGraph * G){
    printf("调用DFS:\n");
    memset(visited, false, MAX_VERTEX);
    stack<int> S;
    for(int i = 0; i < G->vertexCount; i++){
        if(!visited[i]){
            S.push(i);
            visited[i] = true;
            printf(" %s ",G->vertex[i]);
            bool hasNext = false;
            while(!S.empty()){
                int m = S.top();
                hasNext = false;
                for(int j = 0; j < G->vertexCount; j++){
                    if(!visited[j] && G->arcs[m][j] != 0){
                        S.push(j);
                        visited[j] = true;
                        hasNext = true;
                        printf(" %s ",G->vertex[j]);
                        break;
                    }
                }
                if(hasNext == false){
                    S.pop();
                }
            }
        }
    }
    printf("\n");
}

/**打印图的邻接矩阵*/
void PrintMatrixGraph(MatrixGraph * G){
    printf("图的顶点为:");
    for(int i = 0; i < G->vertexCount; i++){
        printf("%s ",G->vertex[i]);
    }
    printf("\n邻接矩阵为:\n");
    for(int i = 0 ; i < G->vertexCount; i++){
        for(int j = 0; j < G->vertexCount; j++){
            printf("%d\t",G->arcs[i][j]);
        }
        printf("\n");
    }
}

/**定位顶点在邻接矩阵中的位置*/
int LocateMatrix(MatrixGraph * G, VertexType vex){
    int index = 0;
    for( ; index < G->vertexCount; index++){
        if(strcmp(G->vertex[index], vex) == 0) break;
    }
    return index == G->vertexCount ? -1 : index;
}
