//
//  AdjListGraph.cpp
//  Graph
//
//  Created by 徐致远 on 2019/12/5.
//  Copyright © 2019 徐致远. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AdjListGraph.h"

/** 用邻接表表示法创建无向图  */
void CreateUDG_AdjList(AdjListGraph * G){
    G->kind = UDG;
    printf("输入顶点数量:");
    scanf("%d",&G->vexCount);
    printf("输入边的数量:");
    scanf("%d",&G->edgeCount);
    printf("输入顶点的信息:");
    for(int i = 0; i < G->vexCount; i++){
        scanf("%s",&G->vexes[i].vex);
        G->vexes[i].firstEdge = NULL;
    }
    printf("输入顶点和邻接点信息，构建邻接表\n");
    for(int i = 0; i < G->edgeCount; i++){
        VertexType vex1, vex2;
        printf("顶点:");
        scanf("%s",&vex1);
        printf("邻接点:");
        scanf("%s",&vex2);
        int x = LocateVex_AdjList(G, vex1);
        int y = LocateVex_AdjList(G, vex2);
        EdgeNode * edgeNode1 = (EdgeNode *)malloc(sizeof(EdgeNode));
        edgeNode1->adjVex = y;
        edgeNode1->weight = 0;
        edgeNode1->nextEdge = G->vexes[x].firstEdge;
        G->vexes[x].firstEdge = edgeNode1;
        
        EdgeNode * edgeNode2 = (EdgeNode *)malloc(sizeof(EdgeNode));
        edgeNode2->adjVex = x;
        edgeNode2->weight = 0;
        edgeNode2->nextEdge = G->vexes[y].firstEdge;
        G->vexes[y].firstEdge = edgeNode2;
    }
}

/** 初始化有向图邻接表 */
void CreateDG_AdjList(AdjListGraph * G){
    G->kind = UDG;
    printf("输入顶点数量:");
    scanf("%d",&G->vexCount);
    printf("输入弧的数量:");
    scanf("%d",&G->arcCount);
    printf("输入顶点的信息:");
    for(int i = 0; i < G->vexCount; i++){
        scanf("%s",&G->vexes[i].vex);
        G->vexes[i].firstArc = NULL;
    }
    printf("输入顶点和邻接点，构建邻接表:\n");
    for(int i = 0; i < G->arcCount; i++){
        VertexType vex1, vex2;
        printf("顶点:");
        scanf("%s",&vex1);
        printf("邻接点:");
        scanf("%s",&vex2);
        int x = LocateVex_AdjList(G, vex1);
        int y = LocateVex_AdjList(G, vex2);
        ArcNode * arcNode = (ArcNode *)malloc(sizeof(ArcNode));
        arcNode->adjVex = y;
        arcNode->weight = 0;
        arcNode->nextArc = G->vexes[x].firstArc;
        G->vexes[x].firstArc = arcNode;
    }
}

/** 初始化无向网邻接表 */
void CreateUDN_AdjList(AdjListGraph * G){
    G->kind = UDN;
    printf("输入顶点数量:");
    scanf("%d",&G->vexCount);
    printf("输入边的数量:");
    scanf("%d",&G->edgeCount);
    printf("输入顶点的信息:");
    for(int i = 0; i < G->vexCount; i++){
        scanf("%s",&G->vexes[i].vex);
        G->vexes[i].firstEdge = NULL;
    }
    printf("输入顶点和邻接点信息，构建邻接表\n");
    for(int i = 0; i < G->edgeCount; i++){
        VertexType vex1, vex2;
        printf("顶点:");
        scanf("%s",&vex1);
        printf("邻接点:");
        scanf("%s",&vex2);
        int weight;
        printf("输入权值:");
        scanf("%d",&weight);
        int x = LocateVex_AdjList(G, vex1);
        int y = LocateVex_AdjList(G, vex2);
        EdgeNode * edgeNode1 = (EdgeNode *)malloc(sizeof(EdgeNode));
        edgeNode1->adjVex = y;
        edgeNode1->weight = weight;
        edgeNode1->nextEdge = G->vexes[x].firstEdge;
        G->vexes[x].firstEdge = edgeNode1;
        
        EdgeNode * edgeNode2 = (EdgeNode *)malloc(sizeof(EdgeNode));
        edgeNode2->adjVex = x;
        edgeNode2->weight = weight;
        edgeNode2->nextEdge = G->vexes[y].firstEdge;
        G->vexes[y].firstEdge = edgeNode2;
    }
}

/** 初始化有向网邻接表 */
void CreateDN_AdjList(AdjListGraph * G){
    G->kind = DN;
    printf("输入顶点数量:");
    scanf("%d",&G->vexCount);
    printf("输入弧的数量:");
    scanf("%d",&G->arcCount);
    printf("输入顶点的信息:");
    for(int i = 0; i < G->vexCount; i++){
        scanf("%s",&G->vexes[i].vex);
        G->vexes[i].firstArc = NULL;
    }
    printf("输入顶点和邻接点信息，构建邻接表\n");
    for(int i = 0; i < G->arcCount; i++){
        VertexType vex1, vex2;
        printf("顶点:");
        scanf("%s",&vex1);
        printf("邻接点:");
        scanf("%s",&vex2);
        int weight;
        printf("输入权值:");
        scanf("%d",&weight);
        int x = LocateVex_AdjList(G, vex1);
        int y = LocateVex_AdjList(G, vex2);
        ArcNode * arcNode = (ArcNode *)malloc(sizeof(ArcNode));
        arcNode->adjVex = y;
        arcNode->weight = weight;
        arcNode->nextArc = G->vexes[x].firstArc;
        G->vexes[x].firstArc = arcNode;
    }
    
}

/** 打印无向邻接表的内容 */
void Print_AdjListUD(AdjListGraph * G){
    printf("邻接表为:\n");
    for(int i = 0; i < G->vexCount; i++){
        printf("%s ",G->vexes[i].vex);
        EdgeNode * edgeNode = (EdgeNode *)malloc(sizeof(EdgeNode));
        edgeNode = G->vexes[i].firstEdge;
        while(edgeNode){
            printf(" -> %d(%d) ",edgeNode->adjVex, edgeNode->weight);
            edgeNode = edgeNode->nextEdge;
        }
        printf("\n");
    }
}

/** 打印有向邻接表的内容 */
void Print_AdjListD(AdjListGraph * G){
    printf("邻接表为:\n");
    for(int i = 0 ; i < G->vexCount; i++){
        printf("%s ",G->vexes[i].vex);
        ArcNode * arcNode = (ArcNode *)malloc(sizeof(ArcNode));
        arcNode = G->vexes[i].firstArc;
        while(arcNode){
            printf(" -> %d(%d) ",arcNode->adjVex,arcNode->weight);
            arcNode = arcNode->nextArc;
        }
        printf("\n");
    }
}

/**定位*/
int LocateVex_AdjList(AdjListGraph *G, VertexType vex){
    int index = 0;
    for(int i = 0; i < G->vexCount; i++){
        if(strcmp(G->vexes[i].vex, vex) == 0){
            index = i;
            break;
        }
    }
    return index;
}
