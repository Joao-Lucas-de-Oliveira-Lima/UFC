#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//Definindo tipo boolean
#define bool int
#define true 1
#define false 0;

//Criando uma lista duplamente encadeada
typedef struct no_d{
	int valor;
	struct no_d* proximo_no;
	struct no_d* no_anterior;
} no_d;

typedef struct{
	no_d comeco_da_lista;
	no_d fim_da_lista;
	int tamanho;
} lista_duplamente_encadeada;

	//Operações básicas de uma lista duplamente encadeada
no_d* alocar_dinamicamente_um_no_d(int valor){
	no_d* novo_no_d = (no_d*)malloc(sizeof(no_d));
	novo_no_d->valor = valor;
	return novo_no_d; 
}

lista_duplamente_encadeada* alocar_dinamicamente_um_lista_duplamente_encadeada(){
	lista_duplamente_encadeada* lista_d = (lista_duplamente_encadeada*)malloc(sizeof(lista_duplamente_encadeada));
	lista_d->comeco_da_lista.proximo_no = &(lista_d->fim_da_lista);
	lista_d->comeco_da_lista.no_anterior = NULL;
	lista_d->fim_da_lista.proximo_no = NULL;
	lista_d->fim_da_lista.no_anterior = &(lista_d->comeco_da_lista);
	lista_d->tamanho = 0;
	return lista_d;
}

void adicionar_elemento_no_comeco_da_lista_duplamente_encadeada(lista_duplamente_encadeada* lista_d, int valor){
	no_d* novo_no_d = alocar_dinamicamente_um_no_d(valor);
	lista_d->comeco_da_lista.proximo_no->no_anterior = novo_no_d;
	novo_no_d->proximo_no = lista_d->comeco_da_lista.proximo_no;
	novo_no_d->no_anterior = &(lista_d->comeco_da_lista);
	lista_d->comeco_da_lista.proximo_no = novo_no_d;
	lista_d->tamanho = lista_d->tamanho+1;
}

void adicionar_elemento_no_fim_da_lista_duplamente_encadeada(lista_duplamente_encadeada* lista_d, int valor){
	no_d* novo_no_d = alocar_dinamicamente_um_no_d(valor);
	lista_d->fim_da_lista.no_anterior->proximo_no = novo_no_d;
	novo_no_d->no_anterior = lista_d->fim_da_lista.no_anterior;
	novo_no_d->proximo_no = &(lista_d->fim_da_lista);
	lista_d->fim_da_lista.no_anterior = novo_no_d;
	lista_d->tamanho = lista_d->tamanho+1;
}

void remover_no_comeco_da_lista_duplamente_encadeada(lista_duplamente_encadeada* lista_d){
	if(lista_d->tamanho != 0){
		no_d* no_auxiliar = lista_d->comeco_da_lista.proximo_no->proximo_no;
		free(lista_d->comeco_da_lista.proximo_no);
		lista_d->comeco_da_lista.proximo_no = no_auxiliar;
		lista_d->comeco_da_lista.proximo_no->no_anterior = &(lista_d->comeco_da_lista);
		lista_d->tamanho = lista_d->tamanho-1;
	}
}

void remover_no_fim_da_lista_duplamente_encadeada(lista_duplamente_encadeada* lista_d){
	if(lista_d->tamanho != 0){
		no_d* no_auxiliar = lista_d->fim_da_lista.no_anterior->no_anterior;
		free(lista_d->fim_da_lista.no_anterior);
		lista_d->fim_da_lista.no_anterior = no_auxiliar;
		lista_d->fim_da_lista.no_anterior->proximo_no = &(lista_d->fim_da_lista);
		lista_d->tamanho = lista_d->tamanho-1;
	}
}

void imprimir_lista_duplamente_encadeada_a_partir_do_comeco(lista_duplamente_encadeada* lista_d){
	int k;
	no_d* no_auxiliar = lista_d->comeco_da_lista.proximo_no;
	while(no_auxiliar->proximo_no != NULL){
		printf("%d. Valor: %d\n", k, no_auxiliar->valor);
		no_auxiliar = no_auxiliar->proximo_no;
	}
}

//Questão 12: ORDENAÇÂO
//Em fase de testes
void ordenar_lista_duplamente_encadeada_para_uma_lista_nao_decresente(lista_duplamente_encadeada* lista){
	no_d* no_auxiliar = lista->comeco_da_lista.proximo_no;
	if(no_auxiliar->proximo_no != NULL){
		no_auxiliar = no_auxiliar->proximo_no;
		int indice_atual = 1;
		while(no_auxiliar->proximo_no != NULL){
			no_d* copia_do_no_auxiliar = no_auxiliar;
			no_d* copia_do_no_auxiliar_proximo = no_auxiliar->proximo_no;
			int k;
			for(k=indice_atual; k>0; k--){
				if(no_auxiliar->valor < copia_do_no_auxiliar->no_anterior->valor) break;
				copia_do_no_auxiliar = copia_do_no_auxiliar->no_anterior;
			}
			no_auxiliar->proximo_no->no_anterior = no_auxiliar->no_anterior;
			no_auxiliar->no_anterior = no_auxiliar->proximo_no;
			//
			no_auxiliar->proximo_no = copia_do_no_auxiliar;
			no_auxiliar->no_anterior = copia_do_no_auxiliar->no_anterior;
			no_auxiliar->no_anterior->proximo_no = no_auxiliar;
			copia_do_no_auxiliar->no_anterior = no_auxiliar;
			indice_atual++;
			no_auxiliar = no_auxiliar->proximo_no;
		}
	}
}

//teste
int main(){

    return 0;
}