#include <math.h>
#include <stdlib.h>
#include <stdio.h>


int solution(int A[], int N) {

	int L_sum = 0;
	int R_sum = 0;

	int *L_cursor = &A[0];
	int *R_cursor = &A[N-1];

	//printf("L_cursor is%d\n", *L_cursor);
	//printf("R_cursor is%d\n", *R_cursor);

	int *L_sum_array = calloc(N, sizeof(int));
	int *R_sum_array = calloc(N, sizeof(int));

	for (int i = 0; i < N-1; i++)	{
		//printf("L_cursor is%d\n", *L_cursor++);
		//printf("L_cursor is%d\n", *L_cursor);

		// single line trial :D
		//L_sum_array[i] = *L_cursor + *++L_cursor;
		//R_sum_array[N-i-1] = *R_cursor + *--R_cursor;
	
		/* Working version */
		L_sum = L_sum + *L_cursor++;
		L_sum_array[i] = L_sum;
         
		//printf("R_cursor is%d\n", *R_cursor--);
		//printf("R_cursor is%d\n", *R_cursor);

		/* Working version */
		R_sum = R_sum + *R_cursor--;
		R_sum_array[N-i-1] = R_sum;

		//printf("@index %d: sum is%d\n",N-i-1, R_sum_arry[i]);
	}

	int *diff_array = calloc(N-1, sizeof(int));


	L_cursor = &L_sum_array[0];
	R_cursor = &R_sum_array[1];

	int min_diff = 2001;
	
	for (int i = 0; i < N-1; i++)	{
		//printf("L_cursor is%d\n", *L_cursor);
		//printf("R_cursor is%d\n", *R_cursor);
		diff_array[i] = abs(*L_cursor++ - *R_cursor++);
		//printf("@index %d: diff is%d\n",i, diff_array[i]);
		
		if (abs(min_diff) > abs(diff_array[i]) ) {
			min_diff = diff_array[i];
		}
	}

	free(L_sum_array);
	free(R_sum_array);
	free(diff_array);

    return abs(min_diff);
}


int main() 
{
    int A[2] = {1,5};
    printf("Solution is=%d\n",solution(A,2));
    
	int A2[4] = {1,3,5,-2};
    printf("Solution is=%d\n",solution(A2,4));

    int B[5] = {3,1,2,4,3};
    printf("Solution is=%d\n",solution(B,5));

    int C[8] = {3,3,3,9,3,3,3,3};
    printf("Solution is=%d\n",solution(C,8));

    int D[12] = {2,2,2,-6,3,1,1,1,-3,1,1,1};
    printf("Solution is=%d\n",solution(D,12));

    return 0;
}

