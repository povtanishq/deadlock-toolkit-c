#ifndef RECOVERY_H
#define RECOVERY_H

int chooseVictim(int n, int m, int alloc[10][10]);
void recoverTermination(int n, int m, int alloc[10][10], int avail[10], int victim);

#endif