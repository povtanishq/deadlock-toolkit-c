#ifndef RAG_H
#define RAG_H

void buildRAG(int n, int m, int alloc[10][10], int req[10][10], int graph[20][20], int *nodes);
int detectCycle(int graph[20][20], int nodes);

#endif