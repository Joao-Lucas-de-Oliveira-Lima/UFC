#include <stdio.h>

int quantidade_algarismo(int numero){
	if(numero == 0) return 1;
	else{
		int a = quantidade_algarismo(numero/10);
		if(a == 1 && numero <= 9) a = 0;
		return a+=1;
	}
}

int main(){
	printf("%d\n", quantidade_algarismo(11));
	return 0;
}