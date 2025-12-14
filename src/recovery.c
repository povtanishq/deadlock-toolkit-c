#include <stdio.h>
#include "recovery.h"

int chooseVictim(int n, int m, int alloc[10][10]){
    int maxRes = -1, victim = 0;
    for(int p=0;p<n;p++){
        int sum = 0;
        for(int r=0;r<m;r++) sum += alloc[p][r];
        if(sum > maxRes){
            maxRes = sum;
            victim = p;
        }
    }
    return victim;
}

void recoverTermination(int n, int m, int alloc[10][10], int avail[10], int victim){
    for(int r=0;r<m;r++){
        avail[r] += alloc[victim][r];
        alloc[victim][r] = 0;
    }
}