#ifndef LISTA_H
#define LISTA_H
#include "TipoElemento.h"
#include <iostream>
using namespace std;
template<class T>

class Lista{
	private:
		int longitud;
		TipoElemento<T>* inicio;
	public:
		Lista();
		~Lista();
		int getLongitud();
		void setLongitud(int);
		TipoElemento<T>* getInicio();
		void setInicio(TipoElemento<T>*);
		int fin(Lista<T>*);
		void inserta(TipoElemento<T>*, int, Lista<T>*);
		int localiza(TipoElemento<T>*, Lista<T>*);
		TipoElemento<T>* recupera(int, Lista<T>*);
		void suprime(int, Lista<T>*);
		int siguiente(int, Lista<T>*);
		int anterior(int, Lista<T>*);
		int anula(Lista<T>*);
		int primero(Lista<T>*);
		void imprimir(Lista<T>*);			
};

#endif