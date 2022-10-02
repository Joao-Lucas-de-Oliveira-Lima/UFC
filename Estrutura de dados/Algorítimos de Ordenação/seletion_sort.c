#include <stdio.h>

void seletion_sort(long vetor[], int tamanho){
	int menor, a;
	while(tamanho-1 > 0){
		menor = 0;
		for(a=1; a<tamanho; a++) if(vetor[menor] >= vetor[a]) menor=a;
		int auxiliar = vetor[menor];
		vetor[menor] = vetor[tamanho-1];
		vetor[tamanho-1] = auxiliar;
		tamanho--;
	}
}

int main(){
	int k;
	long vetor[] = {-1, -2, 0, 0, 9, 3, 1, 5, 8, 0, 39};
	for(k=0; k<11; k++) printf("%d ", vetor[k]);
	printf("\n");
	seletion_sort(vetor, 11);
	for(k=0; k<11; k++) printf("%d ", vetor[k]);
	return 0;
}