#include <stdio.h>

void bubble_sort(double vetor[], int tamanho){
	int a;
	while(tamanho-1 > 0){
		for(a=0; a<tamanho-1; a++){
			if(vetor[a] > vetor[a+1]){
				double auxiliar = vetor[a];
				vetor[a] = vetor[a+1];
				vetor[a+1] = auxiliar;
			}
		}
		tamanho--;
	}
}

int main(){
	double vetor[] = {2.4, -2.21, 2.345, 8.1, 4.67, 9.34, -10, 0};
	int k;
	for(k=0; k<8; k++) printf("%.2lf ", vetor[k]);
	printf("\n");
	bubble_sort(vetor, 8);
	for(k=0; k<8; k++) printf("%.2lf ", vetor[k]);
	return 0;
}