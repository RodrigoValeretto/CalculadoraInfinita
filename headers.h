typedef struct Lista
{
	struct Lista * next;
	int valor;

}Tipo_Lista;

Tipo_Lista * crialistas();

int somaentradas(int, Tipo_Lista *, Tipo_Lista *);

void verificafinal(int, Tipo_Lista *, Tipo_Lista *);