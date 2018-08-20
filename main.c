#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
/*
#########################################
#  Calculadora Infinita em C 		 	#
#  										#
#  Aluno: Rodrigo Valeretto 			#
#  NUSP: 10684792						#
#  Engenharia de Computação 018			#
#										#
#########################################
*/

int main()
{
	printf("Calculadora de Binarios Infinita\n");
	Tipo_Lista *Elem;										//Declaração de variáveis
	Tipo_Lista *Temp;
	Tipo_Lista *inicioT;
	int ent;
	int cont=0;

	Elem = crialistas();									//Recebendo as listas criadas pela função
	Temp = crialistas();									//nos ponteiros elem e temp
	inicioT = Temp;

	printf("Digite o numero de entradas que serao feitas:\n");
	scanf("%d",&ent);										//Recebe o numero de entradas

	somaentradas(ent, Elem, Temp);							//Função que recebe e soma as entradas

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


	return 0;												//Final do programa
}