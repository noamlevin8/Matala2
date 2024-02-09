#include <stdio.h>
#include "my_mat.h"

int main(){
    int matrix[N][N];
    char c;

    scanf("%c", &c);

    while (c != 'A'){
        scanf(" %c", &c);
    }
    
    buildMatrix(matrix);

    scanf(" %c", &c);

    while (c != 'D' && c != EOF){
        if(c == 'A'){
            buildMatrix(matrix); 
        }
        if(c == 'B'){
            exists(matrix);
        }
        if(c == 'C'){
            shortest(matrix);
        }
        
        scanf(" %c", &c);
    }  
}