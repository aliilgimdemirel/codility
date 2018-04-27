#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int solution(int A[], int N);

int solution(int A[], int N)
{
	// self explanotary 
	if (N == 1) { return A[0]; }

	// we need max_val for malloc or we have to take the upperbound = 10^9
	int max_val = 1;
	for (int i = 0; i < N; i++ ) {
		if (max_val < A[i]) {
			max_val = A[i];
		}
	}
	
	if (max_val < N ) { 
		max_val = N;
	}

	int *sorted = malloc(sizeof(int) * max_val);	
	
	if(!sorted) { 
		printf("malloc failed!\n");
		return 0;
	} 

	// init sorted	
	for (int i = 1; i <= max_val; i++ ) {
		sorted[i-1] = 0;
	}

	sorted[0] = 9999;

	// check A's values, and increment sorted's index == value
	for (int i = 1; i <= N; i++ ) {
		sorted[ A[i-1] ] = sorted[ A[i-1] ] + 1;

	}

	int val_element = 0;
	for (int i = 1; i <= max_val; i++) {
		if ( sorted[i] % 2 == 1 ) {
			val_element = i;
		}
	}

	free(sorted);

	return val_element;
}

int main() {
	
	int A[17] = {2, 2, 3, 3, 4, \
			    4, 5, 5, 5, 5, \
				 30000, 30000, 999, 999, 75, \
			    75, 8};
	int elemA = solution(A, 17);

	printf("elem should be 8 and is: %d\n", elemA);


	int B[3] = {999999000, 2, 2};
	int elemB = solution(B, 3);

	printf("elem should be 999999000 and is: %d\n", elemB);


	return 0;
}
