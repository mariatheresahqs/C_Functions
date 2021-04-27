
long long int fibonacci(int n, int* array);
void printArray(int *array, int n);

#include <stdio.h>
#include <stdlib.h>

void showFibonacci(int n,int* memo);
long long int fibonacci(int n, int* memo);

int main(){
    int tam;
    int array[tam];

    tam = 6;
    array[tam];
    printf("%lld\n", fibonacci(tam, array));

    tam = 7;
    array[tam];
    printf("%lld\n", fibonacci(tam, array));

    tam = 8;
    array[tam];
    printf("%lld\n", fibonacci(tam, array));
    showFibonacci(tam, array);

    // tam = 45;
    // array[tam];
    // printf("%lld\n", fibonacci(tam, array));

    return 0;
}


/*
    Fibonacci without optimization
*/
long long int fibonacci(int n, int* memo){
    if(memo[n]) return memo[n];
    if(n<=2) return 1;
    memo[n] = fibonacci(n-1, memo) + fibonacci(n-2, memo);
    return memo[n];
}

void showFibonacci(int n, int*memo){
    printf("1 1 ");
    for(int i=3;i<=n;i++){
        printf("%d ", memo[i]);
    }
}