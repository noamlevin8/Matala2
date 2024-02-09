#include <stdio.h>
#include <string.h>
#include "my_mat.h"

int main(){
    int selected[S];
    char items[S][21];
    int value[S];
    int weight[S];
    int i, j = 0;
    char result[S][21];

    for (i = 0; i < S; i++)
    {
        scanf("%20s", items[i]);
        scanf("%d", &value[i]);
        scanf("%d", &weight[i]);
        selected[i] = 0;
    }

    int maxValue = KnapSack(weight,value, selected);
    printf("Maximum profit: %d\n", maxValue);
    printf("Selected items:");

    for (i = 0; i < S; i++)
    {
        if (selected[i] == 1)
        {
            strcpy(result[j], items[i]);
            j++;
        }
        
    }
    
    for (i = 0; i < j; i++)
    {
        printf(" %s", result[i]);
    } 
}


