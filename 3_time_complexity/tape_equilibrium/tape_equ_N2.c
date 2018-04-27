#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int findDifference(int* array0, int* array1, int P, int N){ 

    int sum0 = 0;
    int sum1 = 0;
        
    //array0
    for (int i = 0; i < P; i++){
        sum0 += array0[i];
    }   
        
    //array1
    for (int i = 0; i < N-P; i++){
        sum1 += array1[i];    
    }   
        
    return abs(sum0-sum1);
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)

    int *array0 = &A[0];
    int *array1 = NULL; 

    int min_diff = 2001;
    for (int P = 1; P < N; P++) {
        array1 = &A[P];
        int diff_at_index = findDifference(array0, array1, P, N); 
        if( diff_at_index < min_diff ) { 
            min_diff = diff_at_index;
        }   
    }    

    return min_diff;
}


int main() 
{
	int A[2] = {1,5};

	printf("Solution is=%d\n",solution(A,2));

	return 0;
}





