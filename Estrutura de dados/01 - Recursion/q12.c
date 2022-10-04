#include <stdio.h>

int soma_algarismos(int numero){
	if(numero > 0){
		int a = numero%10;
		return soma_algarismos(numero/10)+a;
	} else return 0; 
}

int main(){
	printf("%d\n", soma_algarismos(120964));
	return 0;
}