#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

Tipo_Lista * crialistas()
{
	Tipo_Lista *elemento = (Tipo_Lista*)calloc(1,sizeof(Tipo_Lista));	//Aloca memoria para uma lista dinamicamente
	return elemento;
}

int somaentradas(int ent, Tipo_Lista *Elem, Tipo_Lista *Temp)
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

	for (j = 0; j < ent ; j++)
	{
		printf("Digite o tamanho da entrada %d\n",j);
		scanf("%d",&tam);
		
		fflush(stdin);
		for(i=1;i<tam;i++)
		{
			printf("Digite o valor do binario:\n");
			scanf("%c",&c);

			Elem->valor = atoi(&c);
			printf("%d\n", Elem->valor);

			Elem = Elem->next;
		}

		Elem = inicioE;
		
		Temp->valor = Temp->valor + Elem->valor;

	}
	return 0;
}