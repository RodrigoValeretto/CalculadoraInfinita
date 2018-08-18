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
	int ent;

	Elem = crialistas();									//Recebendo as listas criadas pela função
	Temp = crialistas();									//nos ponteiros elem e temp


	printf("Digite o numero de entradas que serao feitas:\n");
	scanf("%d",&ent);										//Recebe o numero de entradas

	somaentradas(ent, Elem, Temp);							//Função que recebe e soma as entradas



	return 0;												//Final do programa
}