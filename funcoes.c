#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

Tipo_Lista * crialistas()
{
	Tipo_Lista *elemento = (Tipo_Lista*)calloc(1,sizeof(Tipo_Lista));	//Aloca memoria para uma lista dinamicamente
	return elemento;
}

Tipo_Lista * verificafinal(int tam, Tipo_Lista * Elem, Tipo_Lista * inicioE)	//Função que verifica o numero mais significativo da entrada
{
    Tipo_Lista *Aux;						//Criação de função auxiliar para apontar para NULL
	for (int i = 0; i < tam; i++)			//Laço responsável por remover vários zeros no fim da entrada
	{
		Elem = inicioE;						//Ponteros sendo apontados para o lugar correto
		Aux = inicioE;
		while(Elem->next!=NULL)				//While que busca o ultimo elemento da lista
        {
            Elem = Elem->next;
        }

        while(Aux->next != Elem)			//While que posiciona o auxiliar um elemento antes do ultimo da lista
        {

            if(tam == 1 || Aux == NULL)		//If responsável por quebrar o laço caso o tamanho da entrada seja 1 ou Aux aponte para NULL
            {
                break;
            }else{
                if(i != (tam-1))
                {
                    Aux = Aux->next;
                }else{break;}
            }
        }

        if(Elem->valor == 0)			    //Condicional para remover elemento caso ele for 0
        {
            free(Elem);                     //Liberação de memória
            Aux->next = NULL;               //e ponteiro next sendo apontado para NULL
            if(tam == 1)
            {inicioE = NULL;}               //Caso especial para o zero
        }

	}
	return inicioE;							//Retorno da função
}


void somaentradas(int ent, Tipo_Lista *Elem, Tipo_Lista *Temp)	//Função para receber e somar as entradas
{
	int i=0;						//Declaração de Variáveis
	int j=0;
	int tam;
	int vaium=0;
	char c;
	Tipo_Lista *inicioE;
	Tipo_Lista *inicioT;
    inicioT = Temp;					//Guardando o local para onde os
    inicioE = Elem;					//ponteiros apontam inicialmente

	for (j = 0; j < ent ; j++)		//For utilizado para realizar a soma
	{
        Temp = inicioT;					//Guardando o local para onde os
        Elem = inicioE;					//ponteiros apontam inicialmente

		printf("Digite o tamanho da entrada %d\n",j);
		fflush(stdin);
		scanf("%d",&tam);			//Recebe o tamanho da entrada

		fflush(stdin);				//Limpa o buffer do teclado
		printf("Digite o valor do binario:\n");
		for(i = 0;i < tam; i++)		//For utilizado para colocar todos os elementos em uma lista encadeada
		{
			scanf("%c",&c);			//Variavel de suporte criada para receber a string da entrada

			Elem->valor = c - '0';	//Função que transforma a entrada em int e atribui ao valor do elemento da lista

			if(i!=(tam-1))			//Aloca memoria para o proximo elemento caso ele exista
			{
				Elem->next = (Tipo_Lista*)calloc(1,sizeof(Tipo_Lista));
				Elem = Elem->next;
			}else{
                Elem->next = NULL;	//Caso o prox elemento não seja necessario, o ponteiro é direcionado a NULL
			}

		}

		inicioE = verificafinal(tam, Elem, inicioE);	//Verifica o número mais significativo da entrada

		i=0;
        Elem = inicioE;									//Reposiciona o ponteiro em seu inicio
		while(Elem != NULL || Temp != NULL)				//While responsável por realizar a soma dos binários
		{
			if(Elem == NULL)							//Caso o elemento a ser somado seja NULL
			{
				vaium = (Temp->valor + vaium);			
				Temp->valor = (vaium % 2);
				vaium = (vaium / 2);
			}else{										//Caso o elem esteja preenchido
				vaium = (Temp->valor + Elem->valor + vaium);	
				Temp->valor = (vaium % 2);
				vaium = (vaium / 2);
				Elem = Elem->next;
			}

			if((Elem != NULL || vaium != 0) && Temp->next == NULL)	//If responsável por alocar memória para o buffer temp que soma o resultado
			{
				Temp->next = (Tipo_Lista*)calloc(1,sizeof(Tipo_Lista));
			}
			Temp = Temp->next;							//Avança o ponteiro Temp para o próximo
		}

	}
	return;
}

void liberamemoria(Tipo_Lista *Elem, Tipo_Lista *inicioE)	//Função responsável por liberar a memoria dos elementos da lista encadeada
{
	Elem = inicioE;							//Atribui ao ponteiro Elem sua posição inicial

	while(Elem != NULL)						//While que roda até que Elem aponte para NULL
	{
		free(Elem);							//Libera Elem
		Elem = Elem->next;					//Avança para o próximo da lista
	}

	return;
}
