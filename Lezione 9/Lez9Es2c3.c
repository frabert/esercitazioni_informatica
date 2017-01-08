#include <stdio.h>
#include <stdlib.h>

// Funzioni da implementare
int *leggiInput(int *dim);
int *eliminaNeg(int *vect, int dim, int *new_dim);
float *mediaEstremi(int *vect, int dim);

int *leggiInput(int *dim) {
	int *arr = malloc(sizeof(int) * 20), input;
	*dim = 0;
	scanf("%d", &input);
	while(input != 0) {
		arr[*dim] = input;
		(*dim)++;
		scanf("%d", &input);
	}
	return realloc(arr, sizeof(int) * (*dim));
}

int *eliminaNeg(int *vect, int dim, int *new_dim) {
	*new_dim = dim;
	int i;
	for(i = 0; i < dim; i++) {
		if(vect[i] < 0) {
			vect[i] = -vect[i];
			vect = realloc(vect, sizeof(int) * (*new_dim + 1));
			vect[*new_dim] = vect[i];
			(*new_dim)++;
		}
	}
	return vect;
}

float *mediaEstremi(int *vect, int dim) {
	int arrDim = dim % 2 == 0 ? dim / 2 : dim / 2 + 1;
	float *arr = malloc(sizeof(float) * arrDim);
	int i;
	for(i = 0; i < arrDim; i++) {
		arr[i] = (float)(vect[i] + vect[dim - i - 1]) / 2.0;
	}
	return arr;
}

int main() {
	int *input, *noneg;
	float *results;
	int dim, dim_noneg, i;
	
	// Legge l'input
	input = leggiInput(&dim);
	printf("Stampa dei valori in input: (%d valori)\n", dim);
	for (i = 0; i < dim; i++) {
		printf("%d\n", input[i]);
	}
	
	// Elimina i negativi
	noneg = eliminaNeg(input, dim, &dim_noneg);
	printf("Stampa dei valori senza negativi: (%d valori)\n", dim_noneg);
	for(i = 0; i < dim_noneg; i++) {
		printf("%d\n", noneg[i]);
	}
	
	// Esegue media degli estremi
	results = mediaEstremi(noneg, dim_noneg);
	
	// Calcolo dimensionale dell'array results
	dim = dim_noneg % 2 == 0 ? dim_noneg / 2 : dim_noneg / 2 + 1;
	printf("Risultato di mediaEstremi:\n");
	for(i = 0; i < dim; i++) {
		printf("%3.2f\n", results[i]);
	}
	
	return 0;
}