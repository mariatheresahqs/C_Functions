#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n);

int main(){
    int value;

    printf("Enter number of the sequence that you want to know from the Fibonacci series: ");
    scanf("%d", &value);
    printf("The %d element of the Fibonacci series is: %d\n", value, fibonacci(value));

    return 0;
}

int fibonacci(int n){
    if(n<=2)
        return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}
