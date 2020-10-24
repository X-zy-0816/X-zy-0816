//
//  GraphModel.h
//  Graph
//
//  Created by 徐致远 on 2019/12/2.
//  Copyright © 2019 徐致远. All rights reserved.
//

#ifndef GraphModel_h
#define GraphModel_h

#define OK 1
#define ERROR 0
#define MAX_VERTEX 255

/** 设置顶点类型为字符 */
typedef char VertexType[20];

/** 设置权值类型为int  */
typedef int ArcType;

bool visited[MAX_VERTEX];

typedef enum{
    DG,   //Directed Graph 有向图
    UDG,  //Undirected Graph 无向图
    DN,   //Directed Network 有向网
    UDN,  //Undirected Network 无向网
}GraphKind;


#endif /* GraphModel_h */
