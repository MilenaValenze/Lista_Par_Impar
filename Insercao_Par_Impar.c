#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

/*Relat�rio: O programa est� dando erro quando recebe o primeiro n�mero como par.*/

struct lista{
	int num, ParImpar; //N�mero inteiro qualquer e par�metro para guardar se o n�mero � par ou �mpar.
	struct lista *prox;
};

typedef struct lista Lista;

main(){

	setlocale(LC_ALL,"Portuguese");

	Lista *novo, *pri0, *pri1, *aux, *aux2; //pri0 indica o in�cio dos n�meros pares. pri1 para os �mpares. aux2 � para guardar o n�mero anterior a aux

	pri0=NULL;
	pri1=NULL;

	novo=(Lista*)malloc(sizeof(Lista));
	printf("*O programa roda at� recebe o valor '999'*\n");
	printf("Digite um n�mero: ");
	scanf("%i", &novo->num);	
	
	if(novo->num==999){
		printf("\nLista:\t%i\tEspa�o na mem�ria: %i\nFim.\n", novo->num);
	//Se o primeiro n�mero digitado for 999, o programa n�o executa mais nada (para evitar processamento desnecess�rio)
	}
	
	else if(novo->num!=999){ //se o primeiro n�mero n�o for 999, o programa roda
	
		novo->ParImpar=(novo->num%2);
		novo->prox=NULL;  //O primeiro n�mero receber� como prox, NULL. N�o importa se for par ou �mpar
	
		if(novo->ParImpar!=0){ //Sen�o, se for �mpar...
			printf("Este n�mero � �mpar.\n");
			pri1=novo;
		}
		else if(novo->ParImpar==0){ //Se for par...
			printf("Este n�mero � par.\n");
			pri0=novo;
		}

		//DEPOIS DO PRIMEIRO N�MERO

		while(novo->num!=999){
		
			novo=(Lista*)malloc(sizeof(Lista));
			printf("Digite um n�mero: ");
			scanf("%i", &novo->num);
			novo->ParImpar=(novo->num%2);
			
			//INSER��O DE PARES

			if (novo->ParImpar==0){ //Se for par a inser��o ser� no fim dos pares
				printf("Este n�mero � par.\n");
				if (pri0==NULL){
					pri0=novo;
				}
				else if(pri0!=NULL){
					if(pri0->prox==NULL){
						pri0->prox=pri1;
					}
					else if(pri0->prox!=NULL){
						aux=pri0;
						while((aux->prox!=NULL) && (aux->ParImpar==0)){ //enquanto o n�mero for par e o pr�ximo for diferente de NULL, aux recebe o pr�ximo
							aux2=aux; //Guardar� o anterior de aux2 para o caso de chegar em um n�mero �mpar
							aux=aux->prox;
						}//quando encontrar o fim da lista (que ser� nulo OU um n�mero �mpar)
						aux2->prox=novo; //o pr�ximo do �ltimo par ser� o 'novo', que � �mpar
					}
				}
				if (pri1==NULL)
					novo->prox=NULL;
				else if (pri1!=NULL){
					novo->prox=pri1;
				}
			}

			//INSER��O DE �MPARES

			else if (novo->ParImpar!=0){ //Se for �mpar, a inser��o � no in�cio
			
				printf("Este n�mero � �mpar.\n"); // Ser� adicionado depois dos pares e antes dos �mpares que j� estiverem na lista.
				novo->prox=pri1;
				pri1=novo;

				if (pri0!=NULL){
					if(pri0->prox==NULL){
						pri0->prox=pri1;
					}
					else if(pri0->prox!=NULL){
						aux=pri0;
						while((aux->prox!=NULL) && (aux->ParImpar==0)){ //enquanto o n�mero for par e o pr�ximo for diferente de NULL, aux recebe o pr�ximo
							aux2=aux; //Guardar� o anterior de aux2 para o caso de chegar em um n�mero �mpar
							aux=aux->prox;
						}//quando encontrar o fim da lista (que ser� nulo OU um n�mero �mpar)
						aux2->prox=novo; //o pr�ximo do �ltimo par ser� o 'novo', que � �mpar
					}
				}
			}
		} //Finaliza o la�o

		//SA�DA DE DADOS
		printf("\nLista:\n");
		if(pri0!=NULL)
			aux=pri0;
		else if (pri0==NULL)
			aux=pri1;
		while(aux->prox!=NULL){
			printf("\t%i\t Espa�o na mem�ria: %i\n", aux->num, aux);
			aux=aux->prox;
		}
		printf("\t%i\t Espa�o na mem�ria: %i\n", aux->num, aux);
		printf("\nFim.\n");
	}
}
