typedef struct Lista
{
	struct Lista * next;
	char valor;

}Tipo_Lista;

Tipo_Lista * crialistas();

int somaentradas(int, Tipo_Lista *, Tipo_Lista *);