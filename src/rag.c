#include <stdio.h>
#include "rag.h"

void buildRAG(int n, int m, int alloc[10][10], int req[10][10],
              int graph[20][20], int *nodes){
    for(int i=0;i<n;i++) nodes[i] = i;
    for(int r=0;r<m;r++) nodes[n+r] = n+r;

    for(int p=0;p<n;p++){
        for(int r=0;r<m;r++){
            if(alloc[p][r] > 0)
                graph[n+r][p] = 1;
            if(req[p][r] > 0)
                graph[p][n+r] = 1;
        }
    }
}

int detectCycle(int graph[20][20], int nodes){
    // Simple detection: if any link both ways → cycle
    for(int i=0;i<nodes;i++)
        for(int j=0;j<nodes;j++)
            if(graph[i][j] && graph[j][i])
                return 1;
    return 0;
}