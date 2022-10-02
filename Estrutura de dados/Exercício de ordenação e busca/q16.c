#include <stdio.h>

int preprocessamento(int v[], int n, int a, int b){
	int aux_1 = -1, aux_2 = -1;
	for(int k=0; k<n; k++){
		if(k == a) aux_1 = k;
		if(k == b) aux_2 = k;
	}
	int menor, maior, soma = 0;
	//if(aux_1 == -1 && aux_2 == -1) return NULL;
	if(aux_1 <= aux_2){
		menor = aux_1;
		maior = aux_2;
	} else {
		menor = aux_2;
		maior = aux_1;
	}
	for(int k=menor; k<=maior; k++) soma+=v[k];
	return soma;
}

int soma_elementos_entre_intervalo(int v[], int n, int a, int b){
	return preprocessamento(v, n, a, b);
}

int main(){
	int tamanho = 10;
	int vetor[] = {1, 7, 8, 2, 109, 3, 5, 9, 0, 30};
	printf("%d\n", soma_elementos_entre_intervalo(vetor, tamanho, 3, 8));
	return 0;
}