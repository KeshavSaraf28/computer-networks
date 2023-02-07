#include<stdio.h>
#include <stdlib.h>
#define SIZE 20
struct node
{
	unsigned dist[SIZE];
	unsigned nexthop[SIZE];
};

int main()
{
	int n,e;
	printf("\nEnter the number of nodes : ");
	scanf("%d",&n);
    int costmat[n][n];
    for(int i=0;i<n;i++)
    {

        for(int j=0;j<n;j++)
            costmat[i][j]=__INT_MAX__;
        costmat[i][i]=0;
    }
    struct node* rt=malloc(sizeof(struct node)*n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            rt[i].dist[j]=__INT_MAX__;
            rt[i].nexthop[j]=-1;
        }
        rt[i].dist[i]=0;
        rt[i].nexthop[i]=i;
    }
	printf("\nEnter the Total Number of edges:");
    scanf("%d",&e);
    for(int i=0;i<e;i++)
    {
        int from ,to,cost;
	    printf("\nEnter the From ,To and Cost for edge %d:",i+1);
        scanf("%d %d %d",&from,&to,&cost);
        from--;to--;
        rt[to].dist[from]=cost;
        rt[to].nexthop[from]=from;
        rt[from].dist[to]=cost;
        rt[from].nexthop[to]=to;
        costmat[from][to]=cost;
        costmat[to][from]=cost;
    }
    for(int i=0;i<n;i++)
    {
        printf("\n    Router %d\n",i+1);
        printf("Node Cost Hop\n");
        for(int j=0;j<n;j++)
        {
            printf("%4d %4d %3d\n",j+1,rt[i].dist[j],rt[i].nexthop[j]+1);

            
        }

    }
    printf("--------------------------------------------------------------------------\n");
    int count=0;
    do// Bellman Ford's Algorithm 
        {
            count=0;
            for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])
                {//We calculate the minimum distance
                    rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                    rt[i].nexthop[j]=k;
                    count++;
                }
        }while(count!=0);
    for(int i=0;i<n;i++)
    {
        printf("\n    Router %d\n",i+1);
        printf("Node Cost Hop\n");
        for(int j=0;j<n;j++)
        {
            printf("%4d %4d %3d\n",j+1,rt[i].dist[j],rt[i].nexthop[j]+1);

            
        }

    }

}
