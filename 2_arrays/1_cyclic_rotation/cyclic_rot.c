struct Results {
  int * A;
  int N; // Length of the array
};

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

struct Results solution(int A[], int N, int K) {
    struct Results result;
    // write your code in C99 (gcc 6.2.0)
    result.A = A;
    result.N = N;

    int rotation = K;
    if(rotation == 0) {return result;}
    else if (N == 0) {return result;}
    else if (N <= K) { 
        rotation = K%N;
        // No need for rotating!
        if (!rotation) { return result;}
    }
    
    int temp[rotation];
    for (int i = 0; i < rotation; i++){
        temp[i] = A[N-(rotation-i)  ];
    }
    
    
    for (int i = N; i-- >0; ) {
        A[i] = A[i-rotation];
    }
    
    for (int i = 0; i < rotation; i++) {
        A[i] = temp[i];
    }
    
    result.A=A;
    
     return result;
}

int main() 
{

	int array[5] = {1,1,2,3,5}	;
	struct Results rez = {.A = array, .N = 5};

	

	return 0;
}
