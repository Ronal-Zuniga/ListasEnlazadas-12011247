#ifndef TIPOELEMENTO_H
#define TIPOELEMENTO_H
#include <iostream>
using namespace std;
template<class T>

class TipoElemento{
	private:
		TipoElemento* siguiente;
		T dato;
	public:
		TipoElemento();
		TipoElemento(T);
		~TipoElemento();
		TipoElemento* getSiguiente();
		void setSiguiente(TipoElemento*);
		T getDato();
		void setDato(T);	
};

#endif