#include <stdio.h>
#include <stdlib.h>

typedef struct ponto{
	int x, y;
	struct ponto *prox_elemento;
}t_ponto;

// Função para armazenar o conteúdo dentro da lista encadeada.
void criar_lista(){
	// Marca o inicio da lista.
	t_ponto *inicio;
	t_ponto *proximo;
	
	int resp;	
	
	// Aloca um espaço na memória.
	inicio = (t_ponto *)malloc(sizeof(t_ponto));
	
	// Caso o espaço alocado dê erro.
	if(inicio == NULL){
		printf("ERRO!\n Erro ao alocar o espaço.");
		exit(1);
	}
	
	proximo = inicio;
	
	while(true){
		printf("Digite x: ");
		scanf("%d", &proximo->x);
		
		printf("Digite y: ");
		scanf("%d", &proximo->y);
		
		printf("Deseja continuar? <1> SIM <outro valor> NAO:");
		scanf("%d", &resp);
		
		if(resp == 1){
			proximo->prox_elemento = (t_ponto *)malloc(sizeof(t_ponto));
			proximo = proximo->prox_elemento;
		}else{
			break;
		}
	}	
	
	// O fim da lista tem que ser vazio.
	proximo->prox_elemento = NULL;
	
	// Percorre a lista do inicio.
	proximo = inicio;
}

// Função para mostrar os valores armazenados na lista encadeada.
void mostrar_lista(){
	t_ponto *inicio;
	t_ponto *proximo;
	
	printf("Lista encadeada: \n");
	
	// Laço para ler todos os valores armazenados.
	// Se reprete enquanto o próximo ponto for diferente de vazio.
	while(proximo != NULL){
		printf("x: %d, y: %d\n", proximo->x, proximo->y);
		proximo = proximo->prox_elemento;
	}		
	
	// Libera a memória que estava alocada no sistema.
	free(inicio);
	free(proximo);
}

// Função principal.
int main() {
	
	criar_lista();
	
	mostrar_lista();
	
	return 0;
}
