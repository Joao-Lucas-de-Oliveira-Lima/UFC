#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int particionamento(int vetor[], int inicio, int fim){
	srand(time(NULL));
	int pivo = rand()%fim+1;
	while(1){
		if(pivo >= inicio && pivo <= fim) break;
		else pivo = rand()%fim+1;
	}
	int copia = vetor[fim];
	vetor[fim] = vetor[pivo];
	vetor[pivo] = copia;
	int esquerda = inicio, direita = fim-1;
	while(esquerda < direita){
		while(vetor[esquerda] <= vetor[fim] && esquerda < direita) esquerda++;
		while(vetor[direita] > vetor[fim] && direita > esquerda) direita--;
		copia = vetor[esquerda];
		vetor[esquerda] = vetor[direita];
		vetor[direita] = copia;
	}
	if(vetor[esquerda] > vetor[fim]){
		copia = vetor[esquerda];
		vetor[esquerda] = vetor[fim];
		vetor[fim] = copia;
		return esquerda;
	}
	return fim;
}

void quick_sort(int vetor[], int inicio, int fim){
	if(inicio < fim){
		int pivo = particionamento(vetor, inicio, fim);
		quick_sort(vetor, inicio, pivo-1);
		quick_sort(vetor, pivo+1, fim);
	}
}

int main(){
	int tamanho = 10;
	int vetor[] = {5, -3, 2, 9, 10, 0, 39, 0, -5, 109};
	for(int k=0; k<tamanho; k++) printf("%d ", vetor[k]);
	printf("\n");
	quick_sort(vetor, 0, tamanho-1);
	for(int k=0; k<tamanho; k++) printf("%d ", vetor[k]);
	return 0;
}