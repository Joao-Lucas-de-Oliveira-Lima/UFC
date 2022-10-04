#include <stdio.h>

int numero_binomial(int n, int k){
	if(n == k || k == 0) return 1;
	return numero_binomial(n-1, k)+numero_binomial(n-1, k-1);
}

int main(){
	printf("%d\n", numero_binomial(6, 4));
	return 0;
}