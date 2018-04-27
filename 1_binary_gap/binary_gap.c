#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(int N) 
{
    // write your code in C99 (gcc 6.2.0)
    
    char *bin_str = malloc(sizeof(char) * 32);
    bin_str[31] = '\0';
    
    for(int i = 31; i-- > 0;) {
		// printf("%d\n",i);
        int temp = N >> i;
        if (temp != 0) {
            N = N - pow(2,i);
            bin_str[30-i] = '1';
        } else {
          bin_str[30-i] = '0';
        }
    }

    //printf("%s\n", bin_str);

	char one = '1';
	int counter = 0;
	short int *index = malloc(sizeof(short int) * 30);
	for(int i = 0; i < 32; i++) {
		if (bin_str[i] == one ) {
			index[counter] = (short int)i;
			counter++;
		}
	}

	free(bin_str);

	int gap = 0;
	for( int i = 0; i < counter-1; i++) {
		int diff = index[i+1] - index[i] - 1;
		if ( diff > gap ) {
			gap = diff;
		}

	}

	free(index);
    return gap;
}

int main()
{
	int N;
	N = 1041;
	printf("Result of 1041 is: %d\n", solution(N));
	N = 5;
	printf("Result of 5 is: %d\n", solution(N));
	N = 66561;
	printf("Result of 66561 is: %d\n", solution(N));
	N = 6291457;
	printf("Result of 6291457 is: %d\n", solution(N));
	//N = 1041;
	//printf("Result is: %d\n", solution(N));

//	for (int i = 5; i-- > 0;) {
//
//		printf("%d\n", i);
//	}



	return 0;

}
