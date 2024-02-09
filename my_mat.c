#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my_mat.h"

int dist[N][N];

void buildMatrix(int mat[][N])
{
    
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &mat[i][j]);
            dist[i][j] = mat[i][j];
        }
    }

    for(k = 0; k < N; k++)
    {
        for(i = 0; i < N; i++)
        {
            for(j = 0; j < N; j++)
            {
                if (dist[i][k] != 0 && dist[k][j] != 0)
                {
                    if(dist[i][j] > (dist[i][k] + dist[k][j]) || dist[i][j] == 0)
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void exists(int mat[][N])
{
    int n1, n2;

    scanf("%d", &n1);
    scanf("%d", &n2);

    if(dist[n1][n2] != 0 && n1 != n2)
      printf("True\n");
    
    else
        printf("False\n");
 }

 void shortest(int mat[][N])
 {
    int n1, n2;

    scanf("%d", &n1);
    scanf("%d", &n2);

    if(dist[n1][n2] == 0 || n1 == n2)
        printf("-1\n");
    else
        printf ("%d\n", dist[n1][n2]);
 }

 int max(int n1, int n2){
    if(n1 > n2)
        return n1;
    return n2;
 }
 
 int KnapSack(int weight[], int value[], int selected_boll[]){
    int i, j;
    int K[S+1][W+1];

    for (i = 0; i <= S; i++)
    {
        for (j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
               K[i][j] = 0;
            else if (weight[i-1] <= j){
                K[i][j] = max(value[i-1] + K[i-1][j-weight[i-1]], K[i-1][j]);
            }
            else
                K[i][j] = K[i-1][j];
        }
    }

    i = S;
    j = W;
    while (j > 0 && i > 0)
    {
        while (i > 0 && K[i][j] == K[i-1][j])
        {
            i--;
        }
        selected_boll[i-1] = 1;
        j -= weight[i-1];
        i--;
    }
    return K[S][W];
 }

 