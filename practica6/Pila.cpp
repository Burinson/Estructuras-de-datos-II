#include <iostream>
#include <stdio.h>
#include "Pila.h"
#define what(x) cerr << #x << ": " << x << '\n'
using namespace std;

// Constructor por defecto
template<typename T>
Pila<T>::Pila() {
	tope = -1;
}

// Revisar si está vacía la pila
template<typename T>
bool Pila<T>::vacio() {
	if (tope == -1)
		return true;
	return false;
}

// Revisar si está llena la pila
template<typename T>
bool Pila<T>::lleno() {
	if (tope == MAX-1)
		return true;
	return false;
}

// Insertar en la pila
template<typename T>
void Pila<T>::insertar(T x){
	if (tope < MAX-1)
		a[++tope] = x;
}

// Eliminar un objeto de la pila
template<typename T>
void Pila<T>::eliminar(){
	if (!vacio())
		tope--;
}

// Obtener el elemento al tope de la pila
template<typename T>
T Pila<T>::arriba(){
	if (!vacio())
		return a[tope];
}


