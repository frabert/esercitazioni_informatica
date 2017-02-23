#include <stdio.h>
#include <stdlib.h>

// Funzioni da implementare
int *leggiInput(int *dim);
int *eliminaDup(int *vect, int dim, int *dim_nodup);
int ugualeASomma(int *vect, int dim);
int *maggioreDeiSuccessivi(int *vect, int dim);

int *leggiInput(int *dim) {
	int *arr, i;
	scanf("%d", dim);
	arr = malloc(sizeof(int) * (*dim));
	for(i = 0; i < (*dim); i++) {
		scanf("%d", &arr[i]);
	}
	
	return arr;
}

int find(int x, int *arr, int dim) {
	int i;
	for(i = 0; i < dim; i++) {
		if(arr[i] == x) {
			return 1;
		}
	}
	return 0;
}

int *eliminaDup(int *vect, int dim, int *dim_nodup) {
	int *newArr = malloc(sizeof(int) * dim), i, newDim;
	newDim = 0;
	for(i = 0; i < dim; i++) {
		if(!find(vect[i], newArr, newDim)) {
			newArr[newDim] = vect[i];
			newDim++;
		}
	}
	newArr = realloc(newArr, sizeof(int) * newDim);
	*dim_nodup = newDim;
	return newArr;
}

int ugualeASomma(int *vect, int dim) {
	int somma = 0, i, j;
	
	for(i = 0; i < dim; i++) {
		
		somma = 0;
		for(j = 0; j < dim; j++) {
			if(j != i) {
				somma += vect[j];
			}
		}
		
		if(vect[i] == somma) {
			return 1;
		}
	}
	return 0;
}

int *maggioreDeiSuccessivi(int *vect, int dim) {
	int *res = malloc(sizeof(int) * dim), i, j;
	for(i = 0; i < dim; i++) {
		int cond = 1;
		
		for(j = i + 1; j < dim && cond; j++) {
			cond = vect[i] > vect[j] ? 1 : 0;
		}
		res[i] = cond;
	}
	return res;
}

int main() {
	int *input, *nodup, *results;
	int dim, dim_nodup, i;
	
	// Legge l'input
	input = leggiInput(&dim);
	printf("Stampa dei valori in input: (%d valori)\n", dim);
	for(i = 0; i < dim; i++) {
		printf("%d\n", input[i]);
	}
	
	// Elimina i duplicati
	nodup = eliminaDup(input, dim, &dim_nodup);
	printf("Stampa dei valori senza duplicati: (%d valori)\n", dim_nodup);
	for(i = 0; i < dim_nodup; i++) {
		printf("%d\n", nodup[i]);
	}
	
	// Esegue ugualeASomma
	printf("Risultato di ugualeASomma: %d\n", ugualeASomma(nodup, dim_nodup));
	
	// Esegue maggioreDeiSuccessivi
	results = maggioreDeiSuccessivi(nodup, dim_nodup);
	printf("Risultato maggioreDeiSuccessivi:\n");
	for(i = 0; i < dim_nodup; i++) {
		printf("%d\n", results[i]);
	}
	
	return 0;
}