#include <stdio.h>
#include "bankers.h"

void calcNeed(int n, int m, int alloc[10][10], int max[10][10], int need[10][10]){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            need[i][j] = max[i][j] - alloc[i][j];
}

int isSafe(int n, int m, int alloc[10][10], int max[10][10], int avail[10], int safeSeq[10]){
    int need[10][10];
    calcNeed(n, m, alloc, max, need);

    int finish[10] = {0};
    int work[10];
    for(int i=0;i<m;i++) work[i] = avail[i];

    int count = 0;
    while(count < n){
        int found = 0;
        for(int p=0;p<n;p++){
            if(!finish[p]){
                int j;
                for(j=0;j<m;j++)
                    if(need[p][j] > work[j]) break;

                if(j == m){
                    for(int k=0;k<m;k++)
                        work[k] += alloc[p][k];
                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }
        if(!found) return 0;
    }
    return 1;
}

int requestResources(int n, int m, int alloc[10][10], int max[10][10],
                     int avail[10], int pid, int req[]){
    int need[10][10];
    calcNeed(n, m, alloc, max, need);

    for(int i=0;i<m;i++){
        if(req[i] > need[pid][i])
            return -1;
        if(req[i] > avail[i])
            return -2;
    }

    for(int i=0;i<m;i++){
        avail[i] -= req[i];
        alloc[pid][i] += req[i];
        need[pid][i] -= req[i];
    }

    int safeSeq[10];
    if(!isSafe(n, m, alloc, max, avail, safeSeq))
        return 0;

    return 1;
}