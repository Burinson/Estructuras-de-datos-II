#ifndef Pila_H
#define Pila_H

#include <array>
#include <iostream>
using namespace std;

#define MAX 3 // máximo número de elementos que puede contener la pila

template<typename T> 
class Pila {
	public:
		typedef typename array<T, MAX>::size_type size_type;
		
		Pila<T>(); // Constructor por defecto
		~Pila<T>() = default; // Destructor

		void insertar(T x); // insertar en la pila
		void eliminar(); // eliminar de la pila
		bool vacio(); // revisar si la pila está vacía
		bool lleno(); // revisar si la pila está llena
		T arriba(); // obtener el elemento al tope de la pila
	private:
		array<T, MAX> a; // arreglo que contiene los elementos de la pila
		int tope; // apuntador de elementos de la pila
};

#endif
