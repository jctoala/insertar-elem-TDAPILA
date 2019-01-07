//TDA PILA
//declaración de librerías
#include <iostream>
#include <stdlib.h>
//estructura 
struct Nodo {
	int elemento;
	Nodo *sig;
};
//prototipo de funciones
int vacia(Nodo **);
void insertar(Nodo **, int &);
void mostrar(Nodo **);
void quitar(Nodo **);
//funcion main
using namespace std;
int main(){
	Nodo *cab = NULL;
	int opc, valor;
	do{
		system("cls");
		cout << "1.-INGRESAR ELEMENTO" << endl;
		cout << "2.-MOSTRAR ELEMENTO" << endl;
		cout << "3.-VACIAR PILA" << endl;
		cout << "9.-SALIR" << endl;
		cout << "Digite opcion: ";
		cin >> opc;
		switch(opc){
			case 1:
				system("cls");
				cout << "Ingrese valor: ";
				cin >> valor;
				insertar(&cab, valor);
				
				system("pause");
				break;
			case 2:
				system("cls");
				cout << "LOS ELEMENTOS DE LA PILA SON" << endl;
				mostrar(&cab);
				
				system("pause");
				break;
			case 3: 
				system("cls");
				quitar (&cab);
				
				system("pause");
				break;
		}
	}while(opc!=9);
	
	return 0;
}
//cuerpo de las funciones prototipo
int vacia(Nodo **cab){
	if(*cab == NULL)
		return 1;
	else
		return 0;
}
void insertar(Nodo **cab, int &valor){
	Nodo *p;
	p = new Nodo ();
	p -> elemento = valor;
	if(vacia(cab))
		p -> sig = NULL;
	else 
		p -> sig = *cab;
	*cab = p;
	
	cout << "Elemento insertado correctamente a la pila" << endl;
}
void mostrar(Nodo **cab){
	Nodo *aux;
	if (vacia(cab))
		cout << "La pila esta vacia";
	else {
		aux = *cab;
		while (aux != NULL){
			cout << aux->elemento << endl;
			aux = aux -> sig;
		}
		cout << "TODOS LOS ELEMENTOS MOSTRADOS" << endl;
	}
} 
void quitar(Nodo **cab){
	Nodo *aux;
	if (vacia(cab))
		cout << "La pila esta vacia";
	else{
		aux = *cab;
		cout << "Elemento " << aux -> elemento << ", quitado de la pila" << endl;
		*cab = aux -> sig; 
		delete aux;
	}
}
