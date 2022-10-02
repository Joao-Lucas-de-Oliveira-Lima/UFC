#include <stdio.h>

void imprimir_ordem_crescente(int a, int b){
	if(a <= b){
		printf("%d ", a);
		imprimir_ordem_crescente(a+1, b);
	}
}

int main(){
	imprimir_ordem_crescente(10, 15);
	return 0;
}