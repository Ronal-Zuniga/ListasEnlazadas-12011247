#include "TipoElemento.h"

template<typename T> 
TipoElemento<T>::TipoElemento(){
	this->dato = NULL;
	this->siguiente = NULL;
}

template<typename T>
TipoElemento<T>::TipoElemento(T _dato){
	this->dato = _dato;
	this->siguiente = NULL;
}

template<typename T>
TipoElemento<T>::~TipoElemento(){
}

template<typename T>
TipoElemento<T>* TipoElemento<T>::getSiguiente(){
	return this->siguiente;
}

template<typename T>
void TipoElemento<T>::setSiguiente(TipoElemento*_siguiente){
	this->siguiente = _siguiente;
}

template<typename T>
T TipoElemento<T>::getDato(){
	return this->dato;
}

template<typename T>
void TipoElemento<T>::setDato(T _dato){
	this->dato = _dato;
}
