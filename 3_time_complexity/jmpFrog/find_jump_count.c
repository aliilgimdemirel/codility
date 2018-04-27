#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int solution(int X, int Y, int D) {
    // write your code in C99 (gcc 6.2.0)
    int num_jumps = (int)ceil( (double)(Y - X) / (double)D );   

/*
    double num_jumps_req_f =  (double)(Y - X) / (double)D;
	printf("req jumps float is: %f\n", num_jumps_req_f);   
    double distance_to_zero = num_jumps_req_f - (int)num_jumps_req_f;
	printf("dist_2_0 is: %f\n",distance_to_zero);   

    int num_jumps;
    if ( 0 < distance_to_zero){
        num_jumps = (int)ceil(num_jumps_req_f);
    } else {
		num_jumps = (int)num_jumps_req_f;
	}
*/  
    
    return num_jumps;
}


int main()
{
	int X = 5;
	int Y = 105;
	int D = 3;

	printf("Solution should be 34 and is:%d\n", solution(X, Y, D));
	X = 10;
	Y = 85;
	D = 30;

	printf("Solution should be 3 and is:%d\n", solution(X, Y, D));

	return 0;
}
