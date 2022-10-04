#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//Definindo tipo boolean
#define bool int
#define true 1
#define false 0;

//Criando um ArrayList ou uma lista sequencial

typedef struct{
	int* array;
	int tamanho;
	int capacidade;
} arraylist;

//Operações básicas com um ArrayList

arraylist* alocar_dinamicamente_um_array_list(int capacidade_do_vetor){
	if(capacidade_do_vetor <= 0) capacidade_do_vetor = 1;
	arraylist* lista_sequencial = (arraylist*)malloc(sizeof(arraylist));
	lista_sequencial->array = (int*)malloc(sizeof(int)*capacidade_do_vetor);
	lista_sequencial->capacidade = capacidade_do_vetor;
	lista_sequencial->tamanho = 0;
	return lista_sequencial;
}

void gerir_falta_de_memoria_do_arraylist(arraylist* lista_sequencial){
	//Quando o vetor estiver com nenhum espaço sobrando
	if(lista_sequencial->tamanho == lista_sequencial->capacidade){
		//Não coloque o realloc, pois ainda não sei se realmente a função ao alocar um novo pedaço da memória, vai desconsiderar
		// os dados já salvos no vetor anterior
		int nova_capacidade = lista_sequencial->capacidade+(lista_sequencial->capacidade/2);
		int* array_auxiliar = malloc(sizeof(int)*nova_capacidade);
		int k;
		for(k=0; k<lista_sequencial->tamanho; k++){
			array_auxiliar[k] = lista_sequencial->array[k];
		}
		int* ponteiro_para_o_array_da_lista = lista_sequencial->array;
		lista_sequencial->array = array_auxiliar;
		free(ponteiro_para_o_array_da_lista);
		lista_sequencial->capacidade = nova_capacidade;
	}
}

void gerir_excesso_de_memoria_do_arraylist(arraylist* lista_sequencial){
	if(lista_sequencial->capacidade == lista_sequencial->tamanho*3){
		int nova_capacidade = lista_sequencial->capacidade/2;
		lista_sequencial->array = (int*)realloc(lista_sequencial->array, sizeof(int)*nova_capacidade);
		lista_sequencial->capacidade = nova_capacidade;
		printf("Aqui2: %d\n", nova_capacidade);
	}
}

void adicionar_elemento_no_fim_do_array_list(arraylist* lista_sequencial, int valor){
	gerir_falta_de_memoria_do_arraylist(lista_sequencial);
	lista_sequencial->array[lista_sequencial->tamanho] = valor;
	lista_sequencial->tamanho = lista_sequencial->tamanho+1;
}

bool adicionar_elemento_no_indice_do_array(arraylist* lista_sequencial, int indice, int valor){
	if(indice < 0 || indice >= lista_sequencial->tamanho){
		return false;
	}else{
		lista_sequencial->array[indice] = valor;
		return true;
	}
}

int buscar_primeira_ocorrencia_de_um_elemento_no_array_list(arraylist* lista_sequencial, int valor){
	int k;
	for(k=0; k<lista_sequencial->tamanho; k++) if(lista_sequencial->array[k] == valor) return k;
	return INT_MIN;
}

int retornar_elemento_no_indice_do_array_list(arraylist* lista_sequencial, int indice){
	if(indice < 0 || indice >= lista_sequencial->tamanho){
		return INT_MIN;
	}else{
		return lista_sequencial->array[indice];
	}
}

void remover_elemento_do_array_list(arraylist* lista_sequencial, int valor){
	gerir_excesso_de_memoria_do_arraylist(lista_sequencial);
	int k;
	for(k=0; k<lista_sequencial->tamanho; k++){
		if(lista_sequencial->array[k] == valor){
			lista_sequencial->array[k] = lista_sequencial->array[lista_sequencial->tamanho-1];
			lista_sequencial->tamanho = lista_sequencial->tamanho-1;
			break;
		}
	}
}

bool remover_elemento_no_indice_do_array_list(arraylist* lista_sequencial, int indice){
	gerir_excesso_de_memoria_do_arraylist(lista_sequencial);
	if(indice < 0 || indice >= lista_sequencial->tamanho-1){
		return false;
	}else{
		lista_sequencial->array[indice] = lista_sequencial->array[lista_sequencial->tamanho-1];
		lista_sequencial->tamanho = lista_sequencial->tamanho-1;
		return true;
	}
}

void desalocar_dinamicamente_array_list(arraylist* lista_sequencial){
	free(lista_sequencial->array);
	free(lista_sequencial);
}

void imprimir_array_list(arraylist* lista_sequencial){
	int k;
	for(k=0; k<lista_sequencial->tamanho; k++){
		printf("Elemento na posi%c%co %d do vetor: %d\n", 135, 198, k, lista_sequencial->array[k]);
	}
}

//Questão 1: Para um arraylist
void remover_ocorrencias_de_um_elemento_menor_que_outro_em_um_array_list(arraylist* lista_sequencial, int valor){
	gerir_excesso_de_memoria_do_arraylist(lista_sequencial);
	int k;
	for(k=0; k<lista_sequencial->tamanho; k++){
		if(lista_sequencial->array[k] < valor){
			int j;
			for(j=k; j<lista_sequencial->tamanho; j++){
				lista_sequencial->array[j] = lista_sequencial->array[j+1];
			}
			k--;
			lista_sequencial->tamanho = lista_sequencial->tamanho-1;
		}
	}
}

//Questão 2: Para um arraylist
void remover_todas_as_ocorrencias_de_um_elemento_em_um_array_list(arraylist* lista_sequencial, int valor){
	gerir_excesso_de_memoria_do_arraylist(lista_sequencial);
	int k;
	for(k=0; k<lista_sequencial->tamanho; k++){
		if(lista_sequencial->array[k] == valor){
			int j;
			for(j=k; j<lista_sequencial->tamanho; j++){
				lista_sequencial->array[j] = lista_sequencial->array[j+1];
			}
			k--;
			lista_sequencial->tamanho = lista_sequencial->tamanho-1;
		}
	}
}

//teste
int main(){

    return 0;
}