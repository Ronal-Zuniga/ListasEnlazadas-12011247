#include "Lista.h"

template<typename T>
Lista<T>::Lista() {
	this->longitud = 0;
	this->inicio = NULL;
}

template<typename T>
Lista<T>::~Lista() {
}

template<typename T>
int Lista<T>::getLongitud() {
	return this->longitud;
}

template<typename T>
void Lista<T>::setLongitud(int _longitud) {
	this->longitud = _longitud;
}

template<typename T>
TipoElemento<T>* Lista<T>::getInicio() {
	return this->inicio;
}

template<typename T>
void Lista<T>::setInicio(TipoElemento<T>* _inicio) {
	this->inicio = _inicio;
}

template<typename T>
int Lista<T>::fin(Lista<T>* l) {
	return this->longitud + 1;
}

template<typename T>
void Lista<T>::inserta(TipoElemento<T>* x, int p, Lista<T>* l) {
	if(p < 1 || p >= fin(l)) {
		cout << "Posicion invalida" << endl;
	} else {
		Lista<T>* list = l;
		TipoElemento<T>* temp = l->inicio;
		for (int i = 1; i < p - 1; i++) {
			temp = temp->getSiguiente();
		}
		TipoElemento<T>* aux = temp->getSiguiente();
		temp->setSiguiente(x);
		x->setSiguiente(aux);
		l[p] = x;
		l[p+1] = aux;
		l->setLongitud(l->getLongitud() + 1);
		int pos = p+2;
		for(int i = p + 1; i < list->getLongitud() + 1; i++) {
			l[pos] = list[i];
			pos++;
		}
	}
}

template <typename T>
int Lista<T>::localiza(TipoElemento<T>* x, Lista<T>* l) {
	for(int i = 1; i < l->getLongitud() + 1; i++) {
		if(l[i] == x) {
			return i;
		}
	}
	return fin(l);
}

template <typename T>
TipoElemento<T>* Lista<T>::recupera(int p, Lista<T>* l) {
	if(p < 1 || p >= fin(l)) {
		cout << "Posicion invalida" << endl;
		return NULL;
	} else {
		return l[p];
	}
}

template <typename T>
void Lista<T>::suprime(int p, Lista<T>* l) {
	if(p < 1 || p >= fin(l)) {
		cout << "Posicion invalida" << endl;
	} else {
		if(p == 1) {
			TipoElemento<T>* temp = l->inicio->getSiguiente();
			TipoElemento<T>* aux = l->inicio;
			l->inicio = temp;
			Lista<T>* list = l;
			int pos = 1;
			delete aux;
			l->setLongitud(l->getLongitud() - 1);
			for(int i = 2; i < list->getLongitud() + 1; i++) {
				if(pos <= l->getLongitud()) {
					l[pos] = list[i];
				}
			}
		} else {
			Lista<T>* list = l;
			int pos = p;
			TipoElemento<T>* aux = l[p];
			TipoElemento<T>* temp = aux->getSiguiente();
			delete aux;
			l[p-1] ->setSiguiente(temp);
			l->setLongitud(l->getLongitud() - 1);
			for(int i = p+1; i < list->getLongitud() + 1; i++) {
				if(pos <= l->getLongitud()) {
					l[pos] = list[i];
				}
			}
		}
	}
}

template <typename T>
int Lista<T>::siguiente(int p, Lista<T>* l) {
	if(p < 1 || p >= fin(l)) {
		cout << "Posicion invalida" << endl;
		return 0;
	} else {
		if(p == l->getLongitud()) {
			return fin(l);
		} else {
			return p+1;
		}
	}
}

template <typename T>
int Lista<T>::anterior(int p, Lista<T>* l) {
	if(p < 1 || p >= fin(l)) {
		cout << "Posicion invalida" << endl;
		return 0;
	} else {
		if(p == 1) {
			return 0;
		} else {
			return p-1;
		}
	}
}

template <typename T>
int Lista<T>::anula(Lista<T>* l) {
	for(int i = 1; i < l->getLongitud() + 1; i++) {
		TipoElemento<T>* temp = l[i];
		delete temp->getDato();
		temp->setDato(NULL);
		temp->setSiguiente(NULL);
		delete temp;
	}
	l->setLongitud(0); 
	return fin(l);
}

template <typename T>
int Lista<T>::primero(Lista<T>* l){
	if(l->getLongitud() != 0){
		return 1;
	} else{
		return fin(l);
	}
}

template <typename T>
void Lista<T>::imprimir(Lista<T>* l){
	for(int i = 1; i < l->getLongitud() + 1; i++) {
		TipoElemento<T>* temp = l[i];
		cout << temp->getDato() << endl;
	}
}