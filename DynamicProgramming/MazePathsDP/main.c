#include<stdlib.h>
#include<stdio.h>
 
int PossiblePaths(int m,int n){
    int Table[m+1][n+1];
    int i,j;
     
    for(i=0;i<=m; i++){
        Table[i][0] =1;
    }
    for(i=0;i<=n; i++){
        Table[0][i] =1;
    }
    for(i=1; i<=m; i++ ){
        for(j=1; j<=n; j++){
            printf("%d %d\n", i, j);
            Table[i][j] = Table[i-1][j] + Table[i][j-1];
        }
    }
    return Table[m][n];
}
 
int main(){
   printf("%d",PossiblePaths(7,6));
   return 0;
}



/*
// Space optimization
#include<stdlib.h>
#include<stdio.h>
  
int PossiblePaths(int m,int n){
    int Table[n+1];
  
    for(int i=0;i<=n; i++){
        Table[i] = 1;
    }
    for(int i=1; i<=m; i++ ){
        for(int j=1; j<=n; j++){
            int temp = Table[j];
            Table[j] = Table[j] +  Table[j-1];
        }
    }
    return Table[n];
}
  
int main(){
   printf("%d",PossiblePaths(4,4));
   return 0;
}
*/