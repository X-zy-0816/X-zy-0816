//
//  main.cpp
//  Graph
//
//  Created by 徐致远 on 2019/12/2.
//  Copyright © 2019 徐致远. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "MatrixGraph.h"

#include "AdjListGraph.h"

void TestMatrixGraph(MatrixGraph * G){
    CreateDG(G);
    CreateUDG(G);
    CreateDN(G);
    CreateUDN(G);
    PrintMatrixGraph(G);
}

void TestAdjListGraph(AdjListGraph * G){
    CreateDG_AdjList(G);
    CreateUDG_AdjList(G);
    CreateDN_AdjList(G);
    CreateUDN_AdjList(G);
    Print_AdjListD(G);
    Print_AdjListUD(G);
    
    
}

int main(){
    MatrixGraph G;
    AdjListGraph GG;
    CreateUDN_AdjList(&GG);
    Print_AdjListUD(&GG);

    return 0;
}
