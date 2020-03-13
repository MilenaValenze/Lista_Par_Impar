#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

/*Relatório: O programa está dando erro quando recebe o primeiro número como par.*/

struct lista{
	int num, ParImpar; //Número inteiro qualquer e parâmetro para guardar se o número é par ou ímpar.
	struct lista *prox;
};

typedef struct lista Lista;

main(){

	setlocale(LC_ALL,"Portuguese");

	Lista *novo, *pri0, *pri1, *aux, *aux2; //pri0 indica o início dos números pares. pri1 para os ímpares. aux2 é para guardar o número anterior a aux

	pri0=NULL;
	pri1=NULL;

	novo=(Lista*)malloc(sizeof(Lista));
	printf("*O programa roda até recebe o valor '999'*\n");
	printf("Digite um número: ");
	scanf("%i", &novo->num);	
	
	if(novo->num==999){
		printf("\nLista:\t%i\tEspaço na memória: %i\nFim.\n", novo->num);
	//Se o primeiro número digitado for 999, o programa não executa mais nada (para evitar processamento desnecessário)
	}
	
	else if(novo->num!=999){ //se o primeiro número não for 999, o programa roda
	
		novo->ParImpar=(novo->num%2);
		novo->prox=NULL;  //O primeiro número receberá como prox, NULL. Não importa se for par ou ímpar
	
		if(novo->ParImpar!=0){ //Senão, se for ímpar...
			printf("Este número é ímpar.\n");
			pri1=novo;
		}
		else if(novo->ParImpar==0){ //Se for par...
			printf("Este número é par.\n");
			pri0=novo;
		}

		//DEPOIS DO PRIMEIRO NÚMERO

		while(novo->num!=999){
		
			novo=(Lista*)malloc(sizeof(Lista));
			printf("Digite um número: ");
			scanf("%i", &novo->num);
			novo->ParImpar=(novo->num%2);
			
			//INSERÇÃO DE PARES

			if (novo->ParImpar==0){ //Se for par a inserção será no fim dos pares
				printf("Este número é par.\n");
				if (pri0==NULL){
					pri0=novo;
				}
				else if(pri0!=NULL){
					if(pri0->prox==NULL){
						pri0->prox=pri1;
					}
					else if(pri0->prox!=NULL){
						aux=pri0;
						while((aux->prox!=NULL) && (aux->ParImpar==0)){ //enquanto o número for par e o próximo for diferente de NULL, aux recebe o próximo
							aux2=aux; //Guardará o anterior de aux2 para o caso de chegar em um número ímpar
							aux=aux->prox;
						}//quando encontrar o fim da lista (que será nulo OU um número ímpar)
						aux2->prox=novo; //o próximo do último par será o 'novo', que é ímpar
					}
				}
				if (pri1==NULL)
					novo->prox=NULL;
				else if (pri1!=NULL){
					novo->prox=pri1;
				}
			}

			//INSERÇÃO DE ÍMPARES

			else if (novo->ParImpar!=0){ //Se for ímpar, a inserção é no início
			
				printf("Este número é ímpar.\n"); // Será adicionado depois dos pares e antes dos ímpares que já estiverem na lista.
				novo->prox=pri1;
				pri1=novo;

				if (pri0!=NULL){
					if(pri0->prox==NULL){
						pri0->prox=pri1;
					}
					else if(pri0->prox!=NULL){
						aux=pri0;
						while((aux->prox!=NULL) && (aux->ParImpar==0)){ //enquanto o número for par e o próximo for diferente de NULL, aux recebe o próximo
							aux2=aux; //Guardará o anterior de aux2 para o caso de chegar em um número ímpar
							aux=aux->prox;
						}//quando encontrar o fim da lista (que será nulo OU um número ímpar)
						aux2->prox=novo; //o próximo do último par será o 'novo', que é ímpar
					}
				}
			}
		} //Finaliza o laço

		//SAÍDA DE DADOS
		printf("\nLista:\n");
		if(pri0!=NULL)
			aux=pri0;
		else if (pri0==NULL)
			aux=pri1;
		while(aux->prox!=NULL){
			printf("\t%i\t Espaço na memória: %i\n", aux->num, aux);
			aux=aux->prox;
		}
		printf("\t%i\t Espaço na memória: %i\n", aux->num, aux);
		printf("\nFim.\n");
	}
}
