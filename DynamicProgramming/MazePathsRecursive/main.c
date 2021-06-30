// Recursive implementation 
#include <stdio.h>
 
int PossiblePaths(int i,int j, int m, int n){
    if(i > m || j > n) return 0; 
     
    if(i == m && j == n) return 1;
     
    return PossiblePaths(i+1,j, m,n) 
            + PossiblePaths(i, j+1, m,n) 
            + PossiblePaths(i+1, j+1,m,n);
}
 
int main(void) {
     
    int m = 7;
    int n = 6;
    printf("\n Number of paths in maze : %d",PossiblePaths(0,0,m,n) );
    return 0;
}