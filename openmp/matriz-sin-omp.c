#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	float A[32][32];
	float B[32][32];
	float C[32][32];
	for (int i = 0; i < 32; ++i) {
		for (int j = 0; j < 32; ++j) {
			A[i][j] = 8.0;
			B[i][j] = 6.0;
		}
	}


		for (int i = 0; i < 32; ++i) {
			for (int j = 0; j < 32; ++j) {
				C[i][j] = A[i][j] + B[i][j];
			}
		}


	for (int i = 0; i < 32; ++i) {
		for (int j = 0; j < 32; ++j) {
			printf("C[%d][%d] = %f \n", i, j, C[i][j]);
		}
	}

	return 0;
}
