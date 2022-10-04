#include <stdio.h>

double media_aritimetica(double a, double b){
	return (a+b)/2;
}

int fusc (int n, int profund) {
for (int i = 0; i < profund; ++i)
printf ("|_|_|");
printf ("fusc(%d,%d)\n", n, profund);
if (n == 1) return 1;
if (n % 2 == 0) return fusc (n/2, profund+1);
return fusc ((n-1)/2, profund+1) +
fusc ((n+1)/2, profund+1);
}

int main(){
	//printf("%lf\n", media_aritimetica(-5, 10));
	fusc(7, 0);
	return 0;
}