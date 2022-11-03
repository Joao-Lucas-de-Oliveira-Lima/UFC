#include <stdio.h>

int Euclides(int m, int n){
	int r = m%n;
	if(r != 0){
		m = n;
		n = r;
		return Euclides(m, n);
	} else return n;
}

int main(){
	printf ("%d", Euclides(27, 9));
	return 0;
}