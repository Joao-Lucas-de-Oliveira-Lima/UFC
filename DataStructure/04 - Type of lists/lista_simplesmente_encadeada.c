#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//Definindo tipo boolean
#define bool int
#define true 1
#define false 0;

//Uma lista simplesmente encadeada, nada mais é que um único nó, esse que por sua vez
// apontará para um outro nó ou para NULL, caso aponte para um nó, significa que a lista
// possui pelo menos um elemento

//Para colocar em um campo de um estrutura uma variável do tipo dela própria:
// precisamos colocar um apelido na mesma, e o nome struct no campo em questão, como exemplificado abaixo

typedef struct no{
	int valor;
	struct no* proximo_no;
} no;

typedef struct {
	no comeco_da_lista;
	int tamanho;
} lista_simplesmente_encadeada;

//Operações básicas de uma lista simplesmente encadeada

no* alocar_dinamicamente_um_no(int valor){
	no* novo_no = (no*)malloc(sizeof(no));
	novo_no->valor = valor;
	return novo_no;
}

lista_simplesmente_encadeada* alocar_dinamicamente_uma_lista_simplesmente_encadeada(){
	lista_simplesmente_encadeada* nova_lista = (lista_simplesmente_encadeada*)malloc(sizeof(lista_simplesmente_encadeada));
	nova_lista->comeco_da_lista.proximo_no = NULL;
	nova_lista->tamanho = 0;
	return nova_lista;
}

void adicionar_no_no_comeco_da_lista(lista_simplesmente_encadeada* lista, int valor){
	no* novo_no = alocar_dinamicamente_um_no(valor);
	novo_no->proximo_no = lista->comeco_da_lista.proximo_no;
	lista->comeco_da_lista.proximo_no = novo_no;
	lista->tamanho = lista->tamanho+1;
}	

bool buscar_primeira_ocorrencia_de_um_elemento_na_lista(lista_simplesmente_encadeada* lista, int valor){
	no* no_auxiliar = lista->comeco_da_lista.proximo_no;
	while(no_auxiliar != NULL){
		if(no_auxiliar->valor == valor) return true;
		no_auxiliar = no_auxiliar->proximo_no;
	}
	return false;
}

bool adicionar_no_no_indice_da_lista(lista_simplesmente_encadeada* lista, int indice, int valor){
	//Os valores que usarei para considerar se um índice é válido ou não, serão de 0 ao tamanho da lista-1, mas
	// poderia ser também de 1 ao tamanho da lista
	if(indice < 1 || indice > lista->tamanho){
		 return false;
	} else {
		no* novo_no = alocar_dinamicamente_um_no(valor);
		no* no_auxiliar = lista->comeco_da_lista.proximo_no;
		int k;
		//Descobrindo o índice no qual devo inserir o nó, mais precisamente o índice-1, pois caso eu insira um nó no indíce
		// exato, eu não teria como fazer o cara que vem antes dele apontar para o nó que eu acabei de inserir, já que eu 
		// guardo apenas a informação de que vem a seguir e não de que está antes, por essa razão o laço for a seguir se faz necessário
		for(k=0; k<indice-1; k++) no_auxiliar = no_auxiliar->proximo_no;
		if(k==0){
			novo_no->proximo_no = no_auxiliar;
			lista->comeco_da_lista.proximo_no = novo_no;
		}else{
			novo_no->proximo_no = no_auxiliar->proximo_no;
			no_auxiliar->proximo_no = novo_no;
		}
		lista->tamanho = lista->tamanho+1;
		return true;
	}
}

int retornar_valor_no_indice_da_lista(lista_simplesmente_encadeada* lista, int indice){
	if(indice < 1 || indice > lista->tamanho){
		//Não é um retorno eficaz, pois essa constante pode ser um valor válido da minha lista de inteiros
		return INT_MIN;
	} else {
		no* no_auxiliar = lista->comeco_da_lista.proximo_no;;
		int k=1;
		while(no_auxiliar != NULL && k != indice){
			no_auxiliar = no_auxiliar->proximo_no;
			k++;
		}
		return no_auxiliar->valor;
	}
}

void desalocar_no_no_comeco_da_lista(lista_simplesmente_encadeada* lista){
	no* no_auxiliar = lista->comeco_da_lista.proximo_no->proximo_no;
	free(lista->comeco_da_lista.proximo_no);
	lista->comeco_da_lista.proximo_no = no_auxiliar;
	lista->tamanho = lista->tamanho-1;
}

bool desalocar_no_pela_primeira_ocorrencia_de_um_valor(lista_simplesmente_encadeada* lista, int valor){
	no* no_auxiliar = lista->comeco_da_lista.proximo_no; 
	if(no_auxiliar->valor == valor){
		no* no_auxiliar_2 = no_auxiliar->proximo_no;
		free(no_auxiliar);
		lista->comeco_da_lista.proximo_no = no_auxiliar_2;
		lista->tamanho = lista->tamanho-1;
		return true;
	}else{
		while(no_auxiliar->proximo_no != NULL){
			if(no_auxiliar->proximo_no->valor == valor){
				no* no_auxiliar_2 = no_auxiliar->proximo_no;
				no_auxiliar->proximo_no = no_auxiliar->proximo_no->proximo_no;
				free(no_auxiliar_2);
				lista->tamanho = lista->tamanho-1;
				return true;
			}
			no_auxiliar = no_auxiliar->proximo_no;
		}
	}
	return false;
}

int desalocar_no_pelo_indice_da_lista(lista_simplesmente_encadeada* lista, int indice){
	if(indice < 1 || indice > lista->tamanho){
		return INT_MIN;
	}else{
		no* no_auxiliar = lista->comeco_da_lista.proximo_no;
		int valor, k=0;
		while(k < indice-1 && no_auxiliar != NULL){
			if(k==0) lista->comeco_da_lista.proximo_no;
			else no_auxiliar = no_auxiliar->proximo_no; 
			k++;
		}
		if(k==0){
			no* no_auxiliar_2 = no_auxiliar->proximo_no;
			valor = no_auxiliar->valor;
			free(no_auxiliar);
			lista->comeco_da_lista.proximo_no = no_auxiliar_2;
		}else{
			no* no_auxiliar_2 = no_auxiliar->proximo_no;
			no_auxiliar->proximo_no = no_auxiliar->proximo_no->proximo_no;
			valor = no_auxiliar_2->valor;
			free(no_auxiliar_2);
		}
		lista->tamanho = lista->tamanho-1;
		return valor;
	}
}

void desalocar_dinamicamente_lista_simplesmente_encadeada(lista_simplesmente_encadeada* lista){
	no* no_auxiliar = lista->comeco_da_lista.proximo_no;
	while(no_auxiliar != NULL){ 
		desalocar_no_no_comeco_da_lista(lista);
		no_auxiliar = lista->comeco_da_lista.proximo_no;
	}
	free(lista);
}

void imprimir_lista_simplesmente_encadeada(lista_simplesmente_encadeada* lista){
	no* no_auxiliar = lista->comeco_da_lista.proximo_no;
	int k = 0;
	while(no_auxiliar != NULL){
		printf("Valor conido no n%c de n%cvel %d: %d\n", 162, 161, k, no_auxiliar->valor);
		no_auxiliar = no_auxiliar->proximo_no;
		k++;
	}
}

//Questão 1: lista simplesmente encadeada
void remover_ocorrencias_de_um_elemento_menor_que_outro_na_lista_simplesmente_encadeada(lista_simplesmente_encadeada* lista, int valor){ 
	if(lista->tamanho != 0){
		no* no_auxiliar = lista->comeco_da_lista.proximo_no;
		while(no_auxiliar->proximo_no != NULL){
			if(no_auxiliar->proximo_no->valor < valor){
				no* no_auxiliar_2 = no_auxiliar->proximo_no;
				no_auxiliar->proximo_no = no_auxiliar_2->proximo_no;
				free(no_auxiliar_2);
				lista->tamanho = lista->tamanho-1;
			}else no_auxiliar = no_auxiliar->proximo_no;
		}
		if(lista->comeco_da_lista.proximo_no->valor < valor){
			desalocar_no_no_comeco_da_lista(lista);
		}
	}
}

//Questão 2: Para lista simplesmente encadeada
void remover_todas_as_acorrencias_de_um_elemento_na_lista_simplesmente_encadeada(lista_simplesmente_encadeada* lista, int valor){ 
	if(lista->tamanho != 0){
		no* no_auxiliar = lista->comeco_da_lista.proximo_no;
		while(no_auxiliar->proximo_no != NULL){
			if(no_auxiliar->proximo_no->valor == valor){
				no* no_auxiliar_2 = no_auxiliar->proximo_no;
				no_auxiliar->proximo_no = no_auxiliar_2->proximo_no;
				free(no_auxiliar_2);
				lista->tamanho = lista->tamanho-1;
			}else no_auxiliar = no_auxiliar->proximo_no;
		}
		if(lista->comeco_da_lista.proximo_no->valor == valor){
			desalocar_no_no_comeco_da_lista(lista);
		}
	}
}

//Questão 3
void concatenar_Listas_simplesmente_encadeadas(lista_simplesmente_encadeada *a, lista_simplesmente_encadeada* b){
	no* no_auxiliar = a->comeco_da_lista.proximo_no;
	while(no_auxiliar->proximo_no != NULL){
		no_auxiliar = no_auxiliar->proximo_no;
	}
	no_auxiliar->proximo_no = b->comeco_da_lista.proximo_no;
}

//Questão 4
bool verificar_se_dois_nos_pertecem_a_uma_mesma_lista(lista_simplesmente_encadeada* lista, no* a, no* b){
	int contador = 0;
	no* no_auxiliar = lista->comeco_da_lista.proximo_no;
	while(no_auxiliar != NULL){
		if(no_auxiliar == a || no_auxiliar == b) contador++;
		no_auxiliar = no_auxiliar->proximo_no;
	}
	if(contador >= 2) return true;
	else return false;
}

//Questão 5
/* Se o o campo L.primeiro não for um ponteiro, a variável nó, será uma cópia do campo L.primeiro, portanto alterá-la
não mudará o campo L.primeiro, que ainda apontará para o antigo começo da lista, logo qualquer valor inserido,
porém se o campo L.primeiro não passar a apontar para ele, caso a inserção for no começo da lista, ferá com que os novo nós
fiquem fora do encadeamento. */

//Questão 6
/* Por se tratar de uma lista encadeada, eu ainda precisaria percorrê-la, para encontrar a posição do lista que corresponde
a média aritimética dos indídes inicial e final, pois eu não tenho como fazer o "salto" de uma posição para a outro assim como em um vetor
já que no mesmo, minha memória está emfileirada lado a lado. Até chegar a metade da lista encadeada, no mínimo meu trabalho seria O(n)/2
, logo O(n). O mesmo acontece com uma lista duplamente encadeada, logo o algorítimo de busca binária não teria a mesma eficiência que
em um vetor. */

//Questão 7
/* Para que esse algorítimo funcione, devemos primeiro ancontrar qual nó da lista está no índice-1 passado como parâmetro para uma outra
função, e após, caso o índice seja válido, passar os parâmetros para essa função,
devomos enviar o índice-1, pois apenas assim colocaremos o índice na posição do índice passado como parâmetro,
pois, já que se trata de uma lista encadeada, passar o nó do índice exato, farai com que essa função o colocasse no índice+1,
tudo isso se deve ao fato de não sabermos qual nó está antes, mas apenas, qual nó vem depois. */
void auxiliador_de_insercao_em_uma_lista(no* no_no_indice_menos_um, no* novo_no){
	no* no_auxiliar = no_no_indice_menos_um->proximo_no;
	no_no_indice_menos_um->proximo_no = novo_no;
	novo_no->proximo_no = no_auxiliar;
}

//Questão 8
void auxiliador_de_remocao_de_um_no_em_uma_lista(no* no_anterior, no* no_a_ser_removido){
	no* no_auxiliar = no_a_ser_removido->proximo_no;
	free(no_a_ser_removido);
	no_anterior->proximo_no = no_auxiliar;
}

//Questão 9
no* retornar_no_no_indice(lista_simplesmente_encadeada* lista, int indice){
	if(indice < lista->tamanho && indice >= 0){
		no* no_auxiliar = lista->comeco_da_lista.proximo_no;
		int k;
		for(k=0; k<indice; k++) no_auxiliar = no_auxiliar->proximo_no;
		return no_auxiliar;
	}else return NULL;
}

//Questão 9: Inserção
void nova_insercao(lista_simplesmente_encadeada* lista, int indice, int valor){
	if(indice > 0){
		no* no_auxiliar = retornar_no_no_indice(lista, indice-1);
		if(no_auxiliar != NULL){
			no* novo_no = alocar_dinamicamente_um_no(valor);
			auxiliador_de_insercao_em_uma_lista(no_auxiliar, novo_no);
		}
	}else if(indice == 0){
		no* novo_no = alocar_dinamicamente_um_no(valor);
		auxiliador_de_insercao_em_uma_lista(&(lista->comeco_da_lista), novo_no);
	}
}

//Questão 9: Nova remocao
void nova_remocao(lista_simplesmente_encadeada* lista, int indice){
	if(indice > 0 && indice < lista->tamanho){
		no* no_auxiliar = retornar_no_no_indice(lista, indice-1);
		no* no_auxiliar_2 = retornar_no_no_indice(lista, indice);
		auxiliador_de_remocao_de_um_no_em_uma_lista(no_auxiliar, no_auxiliar_2);
	}else if(indice == 0){
		auxiliador_de_remocao_de_um_no_em_uma_lista(&(lista->comeco_da_lista), lista->comeco_da_lista.proximo_no);
	}
}

//Questão 10: Invertendo o incadeamento
void inverter_lista_simplesmente_encadeada(lista_simplesmente_encadeada* lista){
	int contador = 0;
	no* no_auxiliar = lista->comeco_da_lista.proximo_no;
	//Descobrindo o tamanho
	while(no_auxiliar != NULL){
		contador++;
		no_auxiliar = no_auxiliar->proximo_no;
	}
	no* vetor[contador];
	int k;
	no_auxiliar = lista->comeco_da_lista.proximo_no;
	//Salvando cada posição em um vetor de ponteiros
	for(k=0; k<contador; k++){
		 vetor[k] = no_auxiliar;
		 no_auxiliar = no_auxiliar->proximo_no;
	}
	//Invertendo os encadeamentos
	lista->comeco_da_lista.proximo_no = vetor[contador-1];
	no_auxiliar = lista->comeco_da_lista.proximo_no;
	for(k=contador-2; k>=0; k--){
		no_auxiliar->proximo_no = vetor[k];
		no_auxiliar = no_auxiliar->proximo_no;
	}
	no_auxiliar->proximo_no = NULL;
}

//Teste
int main(){

    return 0;
}