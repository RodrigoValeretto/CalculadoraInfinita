#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

/*
#########################################
#  Calculadora Infinita em C 		 	#
#  										#
#  Aluno: Rodrigo Augusto Valeretto 	#
#  NUSP: 10684792						#
#  Engenharia de Computação 018			#
#										#
#########################################
*/

int main()
{
//	printf("Calculadora de Binarios Infinita\n");
	Tipo_Lista *Elem;										//Declaração de variáveis
	Tipo_Lista *Temp;
	Tipo_Lista *inicioT;
	Tipo_Lista *inicioE;
	int ent;
	int tam;
	int cont=0;

	Elem = crialistas();									//Recebendo as listas criadas pela função
	Temp = crialistas();									//nos ponteiros elem e temp

	inicioT = Temp;											//Salvando o inicio das listas em outros ponteiros
	inicioE = Elem;

//	printf("Digite o numero de entradas que serao feitas:\n");
	scanf(" %d",&ent);										//Recebe o numero de entradas

	tam = somaentradas(ent, Elem, Temp);							//Função que recebe e soma as entradas

	while(Temp != NULL)
	{
		cont++;												//While responsável por contar o número de digitos da saída
		Temp = Temp->next;
	}
	printf("%d ", cont);									//Print da saída

	Temp = inicioT;											//Reposiciona o ponteiro no inicio do mesmo
	while(Temp != NULL)
	{
		printf("%d", Temp->valor);							//While responsável por printar a resposta na tela
		Temp = Temp->next;
	}

	liberamemoria(Temp, inicioT);							//Funções para liberar memoria alocada para os elementos das listas

    if(tam == 1 && Elem->valor == 0)
    {
        liberamemoria(Elem, inicioE);
    }

	return 0;												//Final do programa
}
