#ifndef BANKERS_H
#define BANKERS_H

int isSafe(int n, int m, int alloc[10][10], int max[10][10], int avail[10], int safeSeq[10]);
int requestResources(int n, int m, int alloc[10][10], int max[10][10], int avail[10], int pid, int req[]);

#endif