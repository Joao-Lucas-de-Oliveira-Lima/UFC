#include <stdio.h>

void entrelacamento(int vetor[], int inicio, int media, int fim){
	int ta = media-inicio+1, tb = fim-media;
	int vetor_a[ta], vetor_b[tb];
	int k;
	for(k=0; k<ta; k++) vetor_a[k] = vetor[inicio+k];
	for(k=0; k<tb; k++) vetor_b[k] = vetor[media+k+1];
	int j = 0;
	k = 0;
	while(k < ta && j < tb){
		if(vetor_a[k] <= vetor_b[j]){
			vetor[inicio] = vetor_a[k];
			k++;
		} else {
			vetor[inicio] = vetor_b[j];
			j++;
		}
		inicio++;
	}
	while(k < ta){
		vetor[inicio] =  vetor_a[k];
		k++;
		inicio++;
	}
	while(j < tb){
		vetor[inicio] = vetor_b[j];
		j++;
		inicio++;
	}
}


void merge_sortJ(int vetor[], int inicio, int fim){
	int media = (inicio+fim)/2;
	if(inicio < fim){
		merge_sortJ(vetor, inicio, media);
		merge_sortJ(vetor, media+1, fim);
		entrelacamento(vetor, inicio, media, fim);
	}
}

int main(){
	int k;
	int t = 10;
	int vetor[] = {0, 3, -6, 7, 9, 1, 6, 8, 2, 0};
	for(k=0; k<t; k++) printf("%d ", vetor[k]);
	printf("\n");
	merge_sortJ(vetor, 0, t-1);
	for(k=0; k<t; k++) printf("%d ", vetor[k]);
	return 0;
}