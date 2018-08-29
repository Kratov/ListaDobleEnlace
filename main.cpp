#include <iostream>

using namespace std;

struct Nodo
{
	int info;
	Nodo * ant;
	Nodo * sig;
};

void mostrarDesdeCabeza(Nodo *& cab) {
	Nodo * aux = cab;
	while(aux != NULL){
		cout << "\nDato: "<<aux->info;
		aux = aux->sig;
	}
}

void mostrarDesdeCola(Nodo * fin) {
	Nodo * aux = fin;
	while (aux != NULL) {
		cout << "\nDato: " << aux->info;
		aux = aux->ant;
	}
}

void insertarNodoCola(Nodo *& cab, Nodo *& fin, Nodo *& aux, int info) {
	Nodo * nuevo = new Nodo();
	nuevo->info = info;
	nuevo->sig = NULL;
	nuevo->ant = NULL;
	if (cab == NULL)
	{
		cab = nuevo;
		fin = nuevo;
		aux = nuevo;
	}
	else 
	{
		nuevo->ant = fin;
		fin->sig = nuevo;
		fin = nuevo;
	}
}

void insertarNodoInicio(Nodo *& cab, Nodo *& fin, Nodo *& aux, int info) {
	Nodo * nuevo = new Nodo();
	nuevo->info = info;
	nuevo->sig = NULL;
	nuevo->ant = NULL;
	if (cab == NULL)
	{
		cab = nuevo;
		fin = nuevo;
		aux = nuevo;
	}
	else
	{
		nuevo->sig = cab;
		cab->ant = nuevo;
		cab = nuevo;
	}
}


char menuPrincipal()
{
	char sel = 'S';
	printf("\nPILAS Y COLAS\n	1.Insertar\n	2.Eliminar\n	3.Recorrer\n	S.Salir\n	Seleccion: ");
	scanf(" %c", &sel);
	return sel;
}

int main() {
	Nodo * cab, *fin, *aux;
	cab = fin = aux = NULL;
	int dat;
	char opc = 'S';
	do {
		system("CLS");
		switch (opc = menuPrincipal())
		{
		case '1':
			
			break;
		case '2':
			
			break;
		case '3':
			
			break;
		}
		system("PAUSE");
	} while (opc != 'S');
}