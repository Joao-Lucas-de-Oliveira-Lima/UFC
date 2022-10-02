#include <stdio.h>
#include <stdlib.h>

void conting_sort(int vetor[], int tamanho){
	int maior = vetor[0], menor = vetor[0];
	for(int k=1; k<tamanho; k++){
		if(maior < vetor[k]) maior = vetor[k];
		if(menor > vetor[k]) menor = vetor[k];
	}
	int* vetor_auxiliar = calloc(sizeof(int), maior-menor+1);
	for(int k=0; k<tamanho; k++) vetor_auxiliar[vetor[k]-menor]++;
	int j=0;
	for(int k=0; k<=maior-menor+1; k++){
		while(vetor_auxiliar[k] != 0){
			vetor[j] = k+menor;
			vetor_auxiliar[k]--;
			j++;
		}
	}
}

int main(){
	int tamanho = 10;
	int vetor[] = {2, 10, 4, 0, 9, 3,  6, 87, 1123, 23};
	for(int k=0; k<tamanho; k++) printf("%d ", vetor[k]);
	printf("\n");
	conting_sort(vetor, tamanho);
	for(int k=0; k<tamanho; k++) printf("%d ", vetor[k]);
	return 0;
}