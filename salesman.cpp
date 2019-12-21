#include<bits/stdc++.h>
using namespace std;
#define L 1000

    int StartingVertex();
    int VertexFinder();
    void MinPathFinder(int t,int flag);
    void PrintMatrix();
    void flash ();
    void cost (int l);
    void push(int x);

    int A[L][L];
    int dont[L];
    int path[L];
    int path_cost[L];
    int top=-1;
    int c_top=0;
    FILE *P,*Q;
    int iteration,vertex;
    int v1,v2,source,weight;
    int edge,mi;
    int temp_1,temp_2;
    int min_1=INT_MAX;
    int maximum=0;
    int sum=0;

int StartingVertex()
{
    int i;
    for(i=1;i<=c_top;i++)
    {
            if(min_1>path_cost[i])
            {
                mi=i;
                min_1=path_cost[i];
            }
             if(maximum<path_cost[i])
            {
                maximum=path_cost[i];
            }
    }
    printf("Minimum cost is  : %d km\n",min_1);
    printf("Maximum cost is  : %d km\n",maximum);
    return mi;

}

int VertexFinder()
{
    int i;
    P=fopen("read.txt","r");
    fscanf(P,"%d",&edge);

    for(i=0;i<edge;i++)
    {
        fscanf(P,"%d %d %d",&v1,&v2,&weight);
        A[v1][v2]=weight;
        A[v2][v1]=weight;
        vertex=(max(vertex,max(v1,v2)));
    }
    return vertex;
}

void MinPathFinder(int t,int flag)
    {
    int i,j;
    iteration=vertex;
    sum=0;
    source=t;
    temp_1=source;
    if(flag!=0)
    {
        push(source);
    }
    flash();
    while(1)
    {
        int minimum=INT_MAX;
        temp_2=temp_1;
        dont[temp_2]=1;
        for(j=1;j<=vertex;j++)
        {
            if(dont[j]!=0)
            {

            }else{
                if(temp_2==j)
                {

                }else{
                    if(minimum>A[temp_2][j])
                        {
                          minimum=A[temp_2][j];
                          temp_1=j;
                        }
                }
                }
                if(j==vertex)
                {   sum=sum+minimum;
                      if(flag!=0)
                        {
                            push(temp_1);
                        }
                }
            }
            iteration--;
            if(iteration==1)
            {
                if(flag!=0)
                {
                    push(source);
                }
                sum=sum+A[temp_1][source];
                cost(sum);
                break;
            }
        }

    }

void PrintMatrix()
{
        int i,j;
        printf("WEIGHT MATRIX:\n");
        printf("==============\n");
         printf(" \n \n |");
        for(i=1;i<=vertex;i++)
        {
            printf("\t%d",i);
        }
        printf("\n_|__________________________________________________");
        printf("\n |\n |\n");
        for(i=1;i<=vertex;i++)
        {   printf("%d|\t",i);
            for(j=1;j<=vertex;j++)
            {
                printf("%d\t",A[i][j]);
            }
            printf("\n |\n");
        }
        printf("\n\n");
}

void flash ()
{
    int i;
    for(i=0;i<=vertex;i++)
    {
        dont[i]=0;
    }
}

void cost (int l)
{
    c_top++;
    path_cost[c_top]=l;
    return;
}

void push(int x)
{
    top++;
    path[top]=x;
    return;
}

void PrintPath()
{
    int i;
    printf("Shortest path is :");
    for(i=0;i<=top;i++)
    {
        if(i==top)
        {
            printf("%d ",path[i]);
        }
        else{
            printf(" %d ->",path[i]);
        }
     }
}

int main()
{
    int i,j,t;
    vertex=VertexFinder();
    A[vertex][vertex];
    dont[vertex];
    PrintMatrix();
    for(t=1;t<=vertex;t++)
    {
        MinPathFinder(t,0);
    }
    mi=StartingVertex();

    MinPathFinder(mi,1);
    PrintPath();

    Q=fopen("print.txt","w");
    fprintf(Q,"Shortest path is :");
    for(i=0;i<=top;i++)
    {
         if(i==top)
         {
             fprintf(Q,"%d ",path[i]);
         }
         else{
             fprintf(Q," %d ->",path[i]);
         }
    }
    printf("\n\n\n\n");
    return 0;
}




