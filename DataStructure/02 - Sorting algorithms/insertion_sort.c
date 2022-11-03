#include <stdio.h>

void insertion_sort(int vetor[], int tamanho){
	int j = 0;
	while(j < tamanho-1){
		int k = j, copia = vetor[j+1]; 
		while(copia < vetor[k] && k >= 0){
			vetor[k+1] = vetor[k];
			k--;
		}
		vetor[k+1] = copia;
		j++;
	}
}

int main(){
	int  vetor[] = {0, -1, 5, 6, 8, 2, 0, -39};
	int k;
	for(k=0; k<8; k++) printf("%d ", vetor[k]);
	printf("\n");
	insertion_sort(vetor, 8);
	for(k=0; k<8; k++) printf("%d ", vetor[k]);
	return 0;
}