#include <stdio.h>

void imprimir_ordem_decresente(int a, int b){
	if(a >= b){
		printf("%d ", a);
		imprimir_ordem_decresente(a-1, b);
	}
}

int main(){
	imprimir_ordem_decresente(20, 0);
	return 0;
}