#include <stdio.h>

#define bool int
#define true 1
#define false 0

bool analise_balanceamento_string_recursivo(char string[], int tamanho, int vetor_auxiliar[]){
	if(tamanho > 1){
		if(string[tamanho-2] == '(' || string[tamanho-2] == ')') vetor_auxiliar[0] += 1;
		else if(string[tamanho-2] == '[' || string[tamanho-2] == ']') vetor_auxiliar[1] += 1;
		else if(string[tamanho-2] == '{' || string[tamanho-2] == '}') vetor_auxiliar[2] += 1;
		return analise_balanceamento_string_recursivo(string, tamanho-1, vetor_auxiliar);
	} else if(tamanho == 1){
		bool resultado;
		if(vetor_auxiliar[0] == vetor_auxiliar[1] && vetor_auxiliar[1] == vetor_auxiliar[2]) resultado =  true;
		else resultado = false;
		return resultado;
	} else return false;
}

bool analise_balanceamento_string(char string[], int tamanho){
	int vetor[3], k = 0;
	for(k=0; k<3; k++) vetor[k] = 0;
	return analise_balanceamento_string_recursivo(string, tamanho, vetor);
}

int main(){
	printf("%d\n", analise_balanceamento_string("()[]{}(", 8));
	return 0;
}