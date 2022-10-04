#include <stdio.h>

int compara_string_recursivo(char string_1[], int tamanho_1, int copia_1, char string_2[], int tamanho_2, int copia_2){
	if(tamanho_1 > 1){
		int a = 0, b;
		if(tamanho_2-1 == 0) tamanho_2 = copia_2;
		if(string_1[tamanho_1-2] == string_2[tamanho_2-2]){
			int b = compara_string_recursivo(string_1, tamanho_1-1, copia_1, string_2, tamanho_2-1, copia_2);
			if(string_2[tamanho_2-2] == string_2[0]) a = 1;
			return b+a;
		} else {
			tamanho_2 = copia_2;
			int b = compara_string_recursivo(string_1, tamanho_1-1, copia_1, string_2, tamanho_2, copia_2);
			return b+a;
		}
	} else return 0;
}

int compara_string(char string_1[], int tamanho_1, char string_2[], int tamanho_2){
	int copia_1 = tamanho_1, copia_2 = tamanho_2;
	return compara_string_recursivo(string_1, tamanho_1, copia_1, string_2, tamanho_2, copia_2);
}


int main(){
	printf("%d", compara_string("abcdabceac", 11, "abc", 5));
	return 0;
}