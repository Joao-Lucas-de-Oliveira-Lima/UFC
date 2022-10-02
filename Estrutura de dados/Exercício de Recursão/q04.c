#include <stdio.h>

long soma_elementos_vetor(long vetor[], int tamanho){
	if(tamanho >= 1){
		return soma_elementos_vetor(vetor, tamanho-1)+vetor[tamanho-1];
	} else return 0;
}


int main(){
	long vetor[] ={1, 2, 9, 5, 6, 2};
	printf("%d", soma_elementos_vetor(vetor, 6));
	return 0;
}