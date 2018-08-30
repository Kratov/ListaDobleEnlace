#include <iostream>

using namespace std;

enum Insercion
{
	InsercionInicio,
	InsercionFin,
	InsercionAdelanteDe
};

struct Nodo
{
	int dato;
	Nodo * ant;
	Nodo * Siguiente;
};

int menuPrincipal() {
	int op = 0;
	cout << "\n	1.Insetar Nodo\n	2.Mostrar(Inicio)\n	3.Mostrar(Fin)\n	0.Salir\n	Seleccion: ";
	cin >> op;
	return op;
}

int menuTipoInsercion() {
	int op = 0;
	cout << "\n	1.Inicio\n	2.Fin\n	3.Despues de aux\n Seleccion: ";
	cin >> op;
	return op;
}

void mostrarDesdeCabeza(Nodo *& cab) {
	Nodo * aux = cab;
	while(aux != NULL){
		cout << "\nDato: "<<aux->dato;
		aux = aux->Siguiente;
	}
}

void mostrarDesdeCola(Nodo * fin) {
	Nodo * aux = fin;
	while (aux != NULL) {
		cout << "\nDato: " << aux->dato;
		aux = aux->ant;
	}
}

void insertarNodo(Nodo *& cab, Nodo *& fin, Nodo *& aux, Insercion tipoInsercion, int dato) {
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = dato;
	nuevo_nodo->ant = NULL;
	nuevo_nodo->Siguiente = NULL;

	if (cab == NULL) {
		cab = nuevo_nodo;
		fin = nuevo_nodo;
		aux = nuevo_nodo;
	}
	else {

		switch (tipoInsercion)
		{
		case InsercionInicio:
			nuevo_nodo->Siguiente = cab;
			cab->ant = nuevo_nodo;
			cab = nuevo_nodo;
			break;
		case InsercionFin:
			fin->Siguiente = nuevo_nodo;
			nuevo_nodo->ant = fin;
			fin = nuevo_nodo;
			break;
		case InsercionAdelanteDe:
			nuevo_nodo->Siguiente = aux->Siguiente;
			nuevo_nodo->ant = aux;
			if (aux->Siguiente != NULL)
				aux->Siguiente->ant = nuevo_nodo;
			aux->Siguiente = nuevo_nodo;
			break;
		}
		aux = cab;
	}
}

int main() {
	int dato, op = 0;
	Nodo *cab, *fin, *aux;
	cab = fin = aux = NULL;
	do {
		system("CLS");
		if (aux != NULL)
			cout << "\nEl auxiliar es: " << aux->dato;
		switch (op = menuPrincipal())
		{
		case 1:
			cout << "	\nIngrese el dato a insertar: ";
			cin >> dato;
			switch (menuTipoInsercion())
			{
			case 1:
				insertarNodo(cab, fin, aux, InsercionInicio, dato);
				break;
			case 2:
				insertarNodo(cab, fin, aux, InsercionFin, dato);
				break;
			case 3:
				insertarNodo(cab, fin, aux, InsercionAdelanteDe, dato);
				break;
			}
			break;
		case 2:
			mostrarDesdeCabeza(cab);
			break;
		case 3:
			mostrarDesdeCola(fin);
			break;
		}
		system("PAUSE");
	} while (op != 0);
}