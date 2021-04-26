/*
The objective of this exercise is to compute a Fibonacci sequence up 
to a target number of elements, saving the sequence as an array.

Two methods:

Iterative, using a for loop and computing values in order
Recursive, using dynamic programming technique (memoization) to improve efficiency
*/

int fibonacci(int n);
void iterativeFibonacci(int* resultsArray, int n);
int recursiveFibonacci(int *cache, int n);
void printArray(int *array, int n);

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20
static size_t countRecursive = 0;
static size_t countFibonacci = 0;


int main(){
    int array[MAX_SIZE];

    iterativeFibonacci(array, MAX_SIZE);
    printArray(array, MAX_SIZE);


    // Initialise an array of N elements, each element set to -1
	// Note that this is a GNU extension to the GCC compiler
    int cache[MAX_SIZE] = {[0 ... MAX_SIZE-1] = -1};
    // Set the first two elements in the sequence, which are known
	cache[0] = 0;
	cache[1] = 1;

    recursiveFibonacci(cache, MAX_SIZE-1);
    printArray(cache, MAX_SIZE);

    fibonacci(MAX_SIZE);

    printf("The recursiveFibonacci() was called %lu times.\n", countRecursive);
    printf("The fibonacci() was called %lu times.\n", countFibonacci);


    return 0;
}




/*
    Fibonacci without optimization
*/
int fibonacci(int n){
    countFibonacci++;
    if(n<=2)
        return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}


/*
* The iterative method is straightforward - loop from zero up to the target,
* setting the current element to:
*
* 0 if the current element is at index 0.
* 1 if the current element is at index 1.
* The sum of the elements at the previous two adjacent indices otherwise.
*/
void iterativeFibonacci(int* resultsArray, int n){
    for(int i=0; i<n; i++){
        resultsArray[i] = (i == 0 || i ==1) ? i: (resultsArray[i-1] + resultsArray[i-2]);
    }
}

/*
* Simple recursive calls (in a tree structure) would involve multiple repeat calls 
* performing the same calculation.
*
* Memoization
* This can be implemented by using an array to hold successive numbers in the sequence.
* For each recursive call, we check to see if the value has already been computed by 
* looking in the cache. If has been previously computed, we return this value. Otherwise,
* we perform the computation and add this to the cache.
*/
int recursiveFibonacci(int *cache, int n){
    countRecursive++;

    if(cache[n]==-1){
        cache[n] = recursiveFibonacci(cache, n-1) + recursiveFibonacci(cache, n-2);
    }
    return cache[n];
}


void printArray(int *array, int n){
    for(int i=0; i<n; i++){
        printf(i==0 ? "[ %d" :", %d", array[i]);
    }
    puts("]\n");
}

