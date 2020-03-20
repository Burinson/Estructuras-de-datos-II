#include "Cliente.h"
using namespace std;

// constructor por defecto
Cliente::Cliente(string valorPrimerNombre, string valorApellido, string valorDireccion, string valorCiudad, string valorEstado, string valorCodigoPostal, double valorSaldo) {
  establecerPrimerNombre(valorPrimerNombre);
  establecerApellido(valorApellido);
  establecerDireccion(valorDireccion);
  establecerCiudad(valorCiudad);
  establecerEstado(valorEstado);
  establecerCodigoPostal(valorCodigoPostal);
  establecerSaldo(valorSaldo);
}

// establecer apellido
void Cliente::establecerApellido(string valorApellido) {
  strcpy(apellido, valorApellido.c_str());
}

// obtener apellido
string Cliente::obtenerApellido() { 
  return string(apellido); 
}

// establecer primer nombre
void Cliente::establecerPrimerNombre(string valorPrimerNombre) {
  strcpy(primerNombre, valorPrimerNombre.c_str());
}

// obtener primer nombre
string Cliente::obtenerPrimerNombre() { 
  return string(primerNombre); 
}

// establecer dirección
void Cliente::establecerDireccion(string valorDireccion) {
  strcpy(direccion, valorDireccion.c_str());
}

// obtener direccion
string Cliente::obtenerDireccion() {
  return string(direccion);
}

// establecer ciudad
void Cliente::establecerCiudad(string valorCiudad) {
  strcpy(ciudad, valorCiudad.c_str());
}

// obtener ciudad 
string Cliente::obtenerCiudad() {
  return string(ciudad);
}

// establecer estado
void Cliente::establecerEstado(string valorEstado) {
  strcpy(estado, valorEstado.c_str());
}

// obtener estado
string Cliente::obtenerEstado() {
  return string(estado);
}

// estalcer código postal
void Cliente::establecerCodigoPostal(string valorCodigoPostal) {
  strcpy(codigoPostal, valorCodigoPostal.c_str());
}

// obtener código postal
string Cliente::obtenerCodigoPostal() {
  return string(codigoPostal);
}

// establecer saldo
void Cliente::establecerSaldo(double valorSaldo) { 
  saldo = valorSaldo; 
}

// obtener saldo
double Cliente::obtenerSaldo() { 
  return saldo; 
}

// imprimir cliente
void Cliente::imprimirCliente() {
  cout
  << setw(10) << obtenerPrimerNombre()
  << setw(10) << obtenerApellido()
  << setw(10) << obtenerDireccion()
  << setw(10) << obtenerDireccion()
  << setw(10) << obtenerCiudad()
  << setw(10) << obtenerCodigoPostal()
  << setw(10) << setprecision(2) << fixed << obtenerSaldo() 
  << endl;
}

// imprimir cabecera
void Cliente::imprimirCabecera() {
  cout
  << setw(10) << "NOMBRE" 
  << setw(10) << "APELLIDO" 
  << setw(10) << "DIRECCIÓN"
  << setw(10) << "CIUDAD"
  << setw(10) << "ESTADO"
  << setw(10) << "CÓDIGO POSTAL"
  << setw(10) << "SALDO" 
  << endl;
}
