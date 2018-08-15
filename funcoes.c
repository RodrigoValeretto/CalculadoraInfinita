#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

Tipo_Lista * crialistas()
{
	Tipo_Lista *elemento = (Tipo_Lista*)calloc(1,sizeof(Tipo_Lista));	//Aloca memoria para uma lista dinamicamente
	return elemento;
}

void verificafinal(int tam, Tipo_Lista * Elem, Tipo_Lista * inicioE)	//Função que verifica o numero mais significativo da entrada
{
	for (int i = 0; i < tam; i++)
	{
		Elem = inicioE;
		while(1)
		{

			if (Elem->valor == 0 && Elem->next == NULL)
			{
				free(Elem);
				break;
			}else{
				Elem = Elem->next;
				if(Elem->next == NULL)
					{break;}
			}
		}

	}
	return;
}


int somaentradas(int ent, Tipo_Lista *Elem, Tipo_Lista *Temp)	//Função para receber e somar as entradas
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
		printf("Digite o tamanho da entrada %d\n",j);
		scanf("%d",&tam);			//Recebe o tamanho da entrada
		
		fflush(stdin);				//Limpa o buffer do teclado
		printf("Digite o valor do binario:\n");
		for(i = 0;i < tam; i++)		//For utilizado para colocar todos os elementos em uma lista encadeada	
		{
			scanf("%c",&c);			//Variavel de suporte criada para receber a string da entrada

			Elem->valor = atoi(&c);	//Função que transforma a entrada em int e atribui ao valor do elemento da lista
			
			if(i!=(tam-1))
			{
				Elem->next = (Tipo_Lista*)calloc(1,sizeof(Tipo_Lista));
				Elem = Elem->next;
			}

		}

		verificafinal(tam, Elem, inicioE);

		Elem = inicioE;
		while(Elem != NULL)
		{
			printf("*%d", Elem->valor);
			Elem = Elem->next;
		}
		
		Temp->valor = Temp->valor + Elem->valor;

	}
	return 0;
}