#include <iostream>
#include <cstring>
#include <string>
#include "Cola.h"

class Producto {
  int clave;
  char nombre[20];
  double precio;
public:
  Producto(){}; // constructor por defecto
  
  Producto(string clave, string nombre, string precio) { // constructor
    establecerClave(clave);
    establecerNombre(nombre);
    establecerPrecio(precio);
  }


  int obtenerClave() {
    return clave;
  }


  void establecerClave(string clave) {
    this->clave = stoi(clave);
  }

  string obtenerNombre() {
    return string(nombre);
  }

  void establecerNombre(string nombre) {
    strcpy(this->nombre, nombre.c_str());
  }

  double obtenerPrecio() {
    return precio;
  }

  void establecerPrecio(string precio) {
    this->precio = stod(precio);
  }

  void leer() { // lectura de un producto estándar
    string clave, nombre, precio;

    cout << "Clave: ";
    getline(cin, clave);

    cout << "Nombre: ";    
    getline(cin, nombre);

    cout << "Precio: ";
    getline(cin, precio);

    establecerClave(clave);
    establecerNombre(nombre);
    establecerPrecio(precio);  // se usan los métodos que ya existen
  }
};
