#include <stdio.h>

int maior_indice_elemento_vetor(long vetor[], int tamanho){
	if(tamanho > 0){
		int a = maior_indice_elemento_vetor(vetor, tamanho-1);
		if(vetor[a] > vetor[tamanho-1]) return a;
		else return tamanho-1;
	} else return tamanho;
}

int main(){
	long vetor[] = {0, 2, 4, 20, -30, 9};
	printf("%d\n", maior_indice_elemento_vetor(vetor, 6));
	return 0;
}