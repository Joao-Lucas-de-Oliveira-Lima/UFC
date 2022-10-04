#include <stdio.h>

long produto_elementos_vetor(long vetor[], int tamanho){
	if(tamanho > 0){
		int a = produto_elementos_vetor(vetor, tamanho-1);
		if(a != 0) if(vetor[tamanho-1] > 0) return a*=vetor[tamanho-1];
		if(a == 0 && vetor[tamanho-1] > 0) return vetor[tamanho-1];
		return a;
	} else return 0;
}

int main(){
	long vetor[] = {2, 4};
	printf("%d\n", produto_elementos_vetor(vetor, 2));
	return 0;
}

