typedef struct Lista
{
	struct Lista * next;		//Estrutura principal do programa
	int valor;

}Tipo_Lista;

//Declaração das Funções abaixo

Tipo_Lista * crialistas();

int somaentradas(int, Tipo_Lista *, Tipo_Lista *);

Tipo_Lista * verificafinal(int, Tipo_Lista *, Tipo_Lista *);
