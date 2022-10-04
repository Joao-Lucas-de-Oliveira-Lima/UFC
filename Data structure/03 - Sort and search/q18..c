#include <stdio.h>

void busca_intervalo(int vetor[], int inicio, int fim, int* a, int* b){
	int media_central = (inicio+fim)/2;
	int media_esquerda = (inicio+media_central)/2;
	int media_direita = (media_central+fim)/2;
	if(vetor[inicio] >= *a && vetor[fim] <= *b){
		if(*a >= vetor[media_esquerda]) inicio = media_esquerda;
		else inicio = media_esquerda-1;
		if(*b <= vetor[media_direita]) fim = media_esquerda;
		else fim = media_direita+1;

	}
}

int main(){

	return 0;
}