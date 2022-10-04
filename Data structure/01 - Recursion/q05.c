#include <stdio.h>

long maior_elemento_vetor(long vetor[], int tamanho){
	if(tamanho >= 1){
		int maior = maior_elemento_vetor(vetor, tamanho-1);
		if(maior >= vetor[tamanho-1]) return maior;
		else return vetor[tamanho-1];
	} return vetor[0];
}

int main(){
	long vetor[] = {1, 9, -4, -9, 20, 94};
	printf("%d\n", maior_elemento_vetor(vetor, 6));
	return 0;
}