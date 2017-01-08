#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int tempi[10]; /* Tempi misurati ogni 100 metri */
	char nome[20]; /* Nome dell'atleta */
} corridore;

/* Funzioni da implementare */
corridore *leggi_input(int *dim);
int trova_vincitore(corridore *vect, int dim);
int *tempi_to_intervalli(corridore c);
int *trova_sprint(corridore c);

corridore *leggi_input(int *dim) {
	scanf("%d", dim);
	corridore *arr = malloc(sizeof(corridore) * (*dim));
	int i, j;
	for(i = 0; i < *dim; i++) {
		scanf("%s", arr[i].nome);
		for(j = 0; j < 10; j++) {
			scanf("%d", &(arr[i].tempi[j]));
		}
	}
	return arr;
}

int trova_vincitore(corridore *vect, int dim) {
	int min_tempo = vect[0].tempi[9], min_pos = 0;
	int i;
	for(i = 0; i < dim; i++) {
		if(vect[i].tempi[9] < min_tempo) {
			min_tempo = vect[i].tempi[9];
			min_pos = i;
		}
	}
	
	return min_pos;
}

int *tempi_to_intervalli(corridore c) {
	int base = 0, i;
	int *arr = malloc(sizeof(int) * 10);
	for(i = 0; i < 10; i++) {
		arr[i] = c.tempi[i] - base;
		base = c.tempi[i];
	}
	return arr;
}

int *trova_sprint(corridore c) {
	int *intervalli = tempi_to_intervalli(c);
	int *res = malloc(sizeof(int) * 10);
	int i, j;
	float media;
	
	for(i = 0; i < 10; i++) {
		media = 0;
		for(j = 0; j < 10; j++) {
			if(j != i) {
				media += intervalli[j];
			}
		}
		media = media / 9.0;
		
		if(intervalli[i] < (media / 2.0)) {
			res[i] = 1;
		} else {
			res[i] = 0;
		}
	}
	
	return res;
}

int main() {
	corridore *input;
	int dim, dim_sprint, vincitore, i ,j;
	int *intervalli, *sprint;
	
	/* Legge l'input */
	input = leggi_input(&dim);
	printf("Stampa dei valori in input: (%d atleti)\n", dim);
	for(i = 0; i < dim; i++) {
		printf("Tempi per l'atleta %s:", input[i].nome);
		for(j = 0; j < 10; j++) {
			printf(" %d", input[i].tempi[j]);
		}
		printf("\n");
	}
	
	/* Trova il vincitore */
	vincitore = trova_vincitore(input, dim);
	printf("Nome del vincitore: %s (miglior tempo: %d secondi)\n",
			input[vincitore].nome,
			input[vincitore].tempi[9]);
			
	
	/* Converti da tempi ad intervalli */
	for(i = 0; i < dim; i++) {
		intervalli = tempi_to_intervalli(input[i]);
		printf("Intervalli per l'atleta %s:", input[i].nome);
		for(j = 0; j < 10; j++) {
			printf(" %d", intervalli[j]);
		}
		printf("\n");
		free(intervalli);
	}
	
	/* Trova gli sprint */
	for(i = 0; i < dim; i++) {
		sprint = trova_sprint(input[i]);
		printf("Sprint per l'atleta %s:", input[i].nome);
		for(j = 0; j < 10; j++) {
			printf(" %d", sprint[j]);
		}
		printf("\n");
		free(sprint);
	}
	
	return 0;
}