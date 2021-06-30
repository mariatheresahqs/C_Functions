#include <stdio.h>

int main(){


    int line, column;
    line = 4;
    column = 5;

    int array[4][5] ={  {-20, 0, -20, 0, 0},
                        {0, -10, -10, -10, -10},
                        {-20, 0, 0, 0, +20},
                        {0, 0, -10, 0, 0}};

    // Inverted matrix
    for(int i =1; i<=line; i++){
        for(int j =1; j<=column; j++){
            printf("%d ", array[line-i][column- j]);
        }
        printf("\n");
    }
    return 0;
}