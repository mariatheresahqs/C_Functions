// #include <stdio.h>
// #include <malloc.h>

// int minPathSum(int** grid, int gridRowSize, int gridColSize);
// int main() {
//     int **grid=(int**)malloc(8* sizeof(int*));
//     int i,j;
//     for(i=0;i<8;i++){
//         for(j=0;j<8;j++){
//             grid[i]=(int*)malloc(8* sizeof(int));
//             grid[i][j]=i+j;
//             printf("%d  ",grid[i][j]);
//         }
//         printf("\n");
//     }
//     int result=minPathSum(grid, 8, 8);
//     printf("%d",result);
//     return 0;
// }
// int minPathSum(int** grid, int gridRowSize, int gridColSize) {
//     int i,j;
//     for(i=0;i<gridRowSize;i++){
//         for(j=0;j<gridColSize;j++){
//             if(i==0&&j!=0){
//                 grid[i][j]=grid[i][j-1]+grid[i][j];
//             }
//             else if(i!=0&&j==0){
//                 grid[i][j]=grid[i-1][j]+grid[i][j];
//             }
//             else if(i>0&&j>0){
//                 grid[i][j] = (grid[i - 1][j] < grid[i][j - 1] ? grid[i - 1][j] : grid[i][j - 1])+grid[i][j];
//             }
//         }
//     }
//     return grid[gridRowSize-1][gridColSize-1];
// }


//============================================================================================================


// #include <stdio.h>
// #include <stdlib.h>

// int minPathSum(int** grid, int gridRowSize, int gridColSize) {
//     int *t = (int*)malloc(sizeof(int)*gridColSize);
//     t[0] = grid[0][0];
//     printf("%d ", t[0]);
//     for (int j = 1; j < gridColSize; j++) {
//         t[j] = t[j-1] + grid[0][j];
//         printf("%d ", t[j]);
//     }
//     printf("\n");

//     for (int i = 1; i < gridRowSize; i++) {
//         t[0] = t[0] + grid[i][0];
//         printf("%d ", t[0]);
//         for (int j = 1; j < gridColSize; j++) {
//             t[j] = (t[j-1] > t[j] ? t[j-1] : t[j]) + grid[i][j];
//             printf("%d ", t[j]);
//         }
//         printf("\n");
//     }
//     printf("\n");
//     return t[gridColSize-1];
// }

// int main(int arg, char *argv[]) {
//     // insert code here...
//     printf("LeetCode 064 Minimum Path Sum, C ...\n\n");

//     int a[] = {
//         -20, 0, -20, 0, 0,
//         0, -10, -10, -10, -10,
//         -20, 0, 0, 0, +20,
//         0, 0, -10, 0, 0
//     };

//     int gridRowSize = 4;
//     int gridColSize = 5;
//     int **grid = (int**)malloc(sizeof(int*)*gridRowSize);
//     for (int i = 0; i < gridRowSize; i++) {
//         grid[i] = (int*)malloc(sizeof(int)*gridColSize);
//         for (int j = 0; j < gridColSize; j++) {
//             grid[i][j] = a[gridColSize*i+j];
//             printf("%d ", grid[i][j]);
//         }
//         printf("\n");
//     }
//     printf("\n");

//     int r = minPathSum(grid, gridRowSize, gridColSize);
//     printf("%d\n", r);

//     return 0;
// }
//============================================================================================================


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct _Point{
    int x;
    int y;
} Point;

Point newPoint(int x, int y){
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

int compmin(int a, int b){
    return a < b ? b : a;
}

int minPathSum(int gridSize, int gridColSize,int grid[gridSize][gridColSize]){
    // assume each line is the same size.
    int **visited = (int **)malloc(sizeof(int *) * gridSize);
    for (int i = 0; i < gridSize; i++){
        visited[i] = (int *)malloc(sizeof(int) * gridColSize);
        memset(visited[i], 0, sizeof(int) * gridColSize);
    }
    int **sum = (int **)malloc(sizeof(int *) * gridSize);
    for (int i = 0; i < gridSize; i++){
        sum[i] = (int *)malloc(sizeof(int) * gridColSize);
        memset(sum[i], 0, sizeof(int) * gridColSize);
    }
    int **inQ = (int **)malloc(sizeof(int *) * gridSize);
    for (int i = 0; i < gridSize; i++){
        inQ[i] = (int *)malloc(sizeof(int) * gridColSize);
        memset(inQ[i], 0, sizeof(int) * gridColSize);
    }
    Point *queue = (Point *)malloc(sizeof(Point) * (gridColSize * gridSize));
    memset(queue, 0, sizeof(Point) * (gridColSize * gridSize));

    int front, rear;
    front = rear = 0;
    queue[rear++] = newPoint(0, 0);
    sum[0][0] = grid[0][0];
    visited[0][0] = 1;
    while (front != rear){
        Point p = queue[front];
        if ((p.x + 1) < gridSize && visited[p.x + 1][p.y] == 0){
            if (!inQ[p.x + 1][p.y]){
                queue[rear++] = newPoint(p.x + 1, p.y);
                inQ[p.x + 1][p.y] = 1;
            }if (sum[p.x + 1][p.y] == 0){
                sum[p.x + 1][p.y] = sum[p.x][p.y] + grid[p.x + 1][p.y];
            }else{
                sum[p.x + 1][p.y] = compmin(sum[p.x + 1][p.y], sum[p.x][p.y] + grid[p.x + 1][p.y]);
            }
        }
        if ((p.y + 1) < gridColSize && visited[p.x][p.y + 1] == 0){
            if (!inQ[p.x][p.y + 1]){
                queue[rear++] = newPoint(p.x, p.y + 1);
                inQ[p.x][p.y + 1] = 1;
            }if (sum[p.x][p.y + 1] == 0){
                sum[p.x][p.y + 1] = sum[p.x][p.y] + grid[p.x][p.y + 1];
            }else{
                sum[p.x][p.y + 1] = compmin(sum[p.x][p.y + 1], sum[p.x][p.y] + grid[p.x][p.y + 1]);
            }
        }
        visited[p.x][p.y] = 1;
        front++;
    }
    free(inQ);
    free(queue);
    free(visited);
    return sum[gridSize - 1][gridColSize - 1];
}



int main()
{
    int array[4][5] ={  {-20, 0, -20, 0, 0},
                        {0, -10, -10, -10, -10},
                        {-20, 0, 0, 0, +20},
                        {0, 0, -10, 0, 0}};
    printf("%d\n", minPathSum(4, 5, array));

    return 0;
}


//============================================================================================================


// #include <stdio.h>
// #include <stdlib.h>

// int mins(int a,int b) {
//     if (a<b) {
//         return b;
//     }else {
//         return a;
//     }
// }

// //print all sum from top left to bottom right
// // int minPathSum(int** grid, int gridRowSize, int gridColSize) {
// int minPathSum(int row, int col, int grid[row][col]) {
//     int dp[row][col];
//     int i,j;
//     dp[0][0] = grid[0][0];
//     for (i=1;i<col;i++) {
//         dp[0][i] = grid[0][i] + dp[0][i-1];
//     }

//     for (j=1;j<row;j++) {
//         dp[j][0] = grid[j][0] + dp[j-1][0];
//     }
//     for (i=1;i<row;i++) {
//         for (j=1;j<col;j++) {
//             dp[i][j] = mins(dp[i-1][j],dp[i][j-1]) + grid[i][j];
//         }
//     }
//     // return dp[1][0];
//     return dp[row-1][col-1];
// }


// int main()
// {
//     int row,col,i,j,val,minSum;
//     // int **array;
//     // puts("linhas:");
//     // scanf("%d",&row);
//     // puts("colunas: ");
//     // scanf("%d",&col);
//     row = 4;
//     col = 5;
//     // array=(int**)malloc(row*sizeof(int*));
//     // for(i=0;i<row;i++) {
//     //     array[i] = (int*)malloc(col*sizeof(int));
//     //     for (j=0;j<col;j++) {
//     //         printf("array[%d][%d]",i,j);
//     //         scanf("%d",&val);
//     //         array[i][j] = val;
//     //     }
//     // }

//     int array[4][5] ={  {-20, 0, -20, 0, 0},
//                         {0, -10, -10, -10, -10},
//                         {-20, 0, 0, 0, +20},
//                         {0, 0, -10, 0, 0}};
//     minSum = minPathSum(row,col, array);
//     printf("%d\n",minSum);
//     return 0;
// }



//============================================================================================================


// #include <stdio.h>
// #include <stdlib.h>
// int minPathSum(int **grid, int gridSize, int *gridColSize)
// {
//     int n = gridSize;
//     int m = *gridColSize;
//     int *pathSum = (int *)malloc(sizeof(int) * m);

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (i < 1 && j < 1)
//             {
//                 pathSum[j] = *((int *)grid + i * m + j);
//                 continue;
//             }
//             if (i == 0)
//             {

//                 pathSum[j] = *((int *)grid + i * m + j) + pathSum[j - 1];
//                 continue;
//             }
//             if (j == 0)
//             {
//                 pathSum[j] = *((int *)grid + i * m + j) + pathSum[j];
//                 continue;
//             }
//             pathSum[j] = *((int *)grid + i * m + j) + (pathSum[j] < pathSum[j+1] ? pathSum[j+1] : pathSum[j+1]);
//         }
//     }

//     return pathSum[m - 1];
// }

// int main()
// {
//     int array[4][5] = { {-20, 0, -20, 0, 0},
//                         {0, -10, -10, -10, -10},
//                         {-20, 0, 0, 0, +20},
//                         {0, 0, -10, 0, 0}};
//     int col = 5;
//     printf("%d\n", minPathSum((int **)array, 4, &col));
//     return 0;
// }



















// dp
// int minPathSum(int **grid, int gridSize, int *gridColSize)
// {
//     int **dp = grid;
//     dp[0][0] = grid[0][0];
//     for (int i = 1; i < gridSize; i++)
//     {
//         dp[i][0] = dp[i - 1][0] + grid[i][0];
//     }
//     for (int i = 1; i < gridColSize[0]; i++)
//     {
//         dp[0][i] = dp[0][i - 1] + grid[0][i];
//     }
//     for (int i = 1; i < gridSize; i++)
//     {
//         for (int j = 1; j < gridColSize[0]; j++)
//         {
//             dp[i][j] = fmin(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
//         }
//     }
//     return dp[gridSize - 1][gridColSize[0] - 1];
// }