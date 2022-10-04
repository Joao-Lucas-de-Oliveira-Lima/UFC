#include <stdio.h>

int busca_binaria(int vetor[], int elemento_para_inserir, int inicio, int fim){
	int media = (inicio+fim)/2;
	if(inicio < fim){
		if(elemento_para_inserir >= vetor[media] && elemento_para_inserir < vetor[media+1]) return media+1;
		if(elemento_para_inserir > vetor[media]) inicio = media+1;
		else fim = media-1;
		busca_binaria(vetor, elemento_para_inserir, inicio, fim);
	} else {
		if(elemento_para_inserir >= vetor[media]) return media+1;
		else return media;
	}
}


void binary_insertion_sort(int vetor[], int tamanho){
	int tamanho_auxiliar = 1, posicao_para_inserir, copia;
	while(tamanho_auxiliar <= tamanho){
		posicao_para_inserir = busca_binaria(vetor, vetor[tamanho_auxiliar], 0, tamanho_auxiliar-1);
		copia = vetor[tamanho_auxiliar];
		for(int k=tamanho_auxiliar; k>posicao_para_inserir; k--) vetor[k] = vetor[k-1];
		vetor[posicao_para_inserir] = copia;
		tamanho_auxiliar++;
	}
}

int main(){
	int tamanho = 10;
	int vetor[] = {9, 0, 4, 10, 3, -3, 0, 30, -3, 90};
	for(int k=0; k<tamanho; k++) printf("%d ", vetor[k]);
	printf("\n");
	binary_insertion_sort(vetor, tamanho-1);
	for(int k=0; k<tamanho; k++) printf("%d ", vetor[k]);
	return 0;
}