#include <stdio.h>
#include "bankers.h"
#include "rag.h"
#include "recovery.h"

int main(){
    int n, m;
    int alloc[10][10], max[10][10], avail[10], req[10][10]={0};

    printf("Number of processes: ");
    scanf("%d",&n);
    printf("Number of resources: ");
    scanf("%d",&m);

    printf("Allocation Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);

    printf("Max Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&max[i][j]);

    printf("Available:\n");
    for(int j=0;j<m;j++) scanf("%d",&avail[j]);

    while(1){
        int ch;
        printf("\n1.Safe State\n2.Request Resource\n3.Detect Deadlock(RAG)\n4.Recover\n0.Exit\n");
        scanf("%d",&ch);

        if(ch==1){
            int safeSeq[10];
            if(isSafe(n,m,alloc,max,avail,safeSeq)){
                printf("SAFE: ");
                for(int i=0;i<n;i++) printf("P%d ",safeSeq[i]);
            } else printf("UNSAFE\n");
        }

        else if(ch==2){
            int pid, rv[10];
            printf("Enter process ID:");
            scanf("%d",&pid);

            printf("Enter request vector:");
            for(int j=0;j<m;j++) scanf("%d",&rv[j]);

            int res = requestResources(n,m,alloc,max,avail,pid,rv);

            if(res==1) printf("Request Granted\n");
            else if(res==0) printf("Unsafe State. Request Denied.\n");
            else printf("Invalid Request.\n");
        }

        else if(ch==3){
            int graph[20][20]={0}, nodes[20];
            buildRAG(n,m,alloc,req,graph,nodes);
            if(detectCycle(graph,n+m))
                printf("Deadlock DETECTED\n");
            else
                printf("No Deadlock\n");
        }

        else if(ch==4){
            int victim = chooseVictim(n,m,alloc);
            recoverTermination(n,m,alloc,avail,victim);
            printf("Recovered by killing P%d\n",victim);
        }

        else if(ch==0) break;
    }
    return 0;
}