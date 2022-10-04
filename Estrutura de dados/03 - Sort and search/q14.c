#include <stdio.h>

int ordenar_impar_par(int vetor[], int tamanho){
	int j=0, copia;
	for(int k=0; k<tamanho; k++){
		if(vetor[k]%2 != 0){
			copia = vetor[j];
			vetor[j] = vetor[k];
			vetor[k] = copia;
			j++;
		}
	}
	return j--;
}

int main(){
	int tamanho = 12;
	int vetor[] = {4, 9, 0, 2, -4, 2, 6, 19, 123, 0, 5, -67};
	for(int k=0; k<tamanho; k++) printf("%d ", vetor[k]);
	printf("\n");
	printf("Primeira posicao par: %d\n", ordenar_impar_par(vetor, tamanho));
	for(int k=0; k<tamanho; k++) printf("%d ", vetor[k]);
	return 0;
}