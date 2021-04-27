#include <stdio.h>
#include <stdlib.h>

#define LINE 10
#define COLUMN 5
#define SIZE 10000000

int matrix[SIZE] = {[0 ... SIZE-1] = 0};
int count = 0;
int gridTraveler(int line, int column, int matrix[]);


int main(){
    
    printf("%d ",gridTraveler(LINE, COLUMN, matrix));
    // printf("\n%d", count);
    return 0 ;
}

int gridTraveler(int line, int column, int matrix[]){
    count++;
    if(matrix[count]!=0) return matrix[count];
    if(line==1 && column==1) return 1;
    if(line ==0 || column==0) return 0;
    matrix[count] = gridTraveler(line-1, column, matrix) + gridTraveler(line, column-1, matrix);
    return matrix[count];
}