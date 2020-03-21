#include "Contacto.h"
using namespace std;

// constructor por defecto
Contacto::Contacto(string valorPrimerNombre, string valorApellido, string valorDireccion, string valorCiudad, string valorEstado, string valorCodigoPostal, double valorSaldo) {
  establecerPrimerNombre(valorPrimerNombre);
  establecerApellido(valorApellido);
  establecerDireccion(valorDireccion);
  establecerCiudad(valorCiudad);
  establecerEstado(valorEstado);
  establecerCodigoPostal(valorCodigoPostal);
  establecerSaldo(valorSaldo);
}

// establecer apellido
void Contacto::establecerApellido(string valorApellido) {
  strcpy(apellido, valorApellido.c_str());
}

// obtener apellido
string Contacto::obtenerApellido() { 
  return string(apellido); 
}

// establecer primer nombre
void Contacto::establecerPrimerNombre(string valorPrimerNombre) {
  strcpy(primerNombre, valorPrimerNombre.c_str());
}

// obtener primer nombre
string Contacto::obtenerPrimerNombre() { 
  return string(primerNombre); 
}

// establecer dirección
void Contacto::establecerDireccion(string valorDireccion) {
  strcpy(direccion, valorDireccion.c_str());
}

// obtener direccion
string Contacto::obtenerDireccion() {
  return string(direccion);
}

// establecer ciudad
void Contacto::establecerCiudad(string valorCiudad) {
  strcpy(ciudad, valorCiudad.c_str());
}

// obtener ciudad 
string Contacto::obtenerCiudad() {
  return string(ciudad);
}

// establecer estado
void Contacto::establecerEstado(string valorEstado) {
  strcpy(estado, valorEstado.c_str());
}

// obtener estado
string Contacto::obtenerEstado() {
  return string(estado);
}

// estalcer código postal
void Contacto::establecerCodigoPostal(string valorCodigoPostal) {
  strcpy(codigoPostal, valorCodigoPostal.c_str());
}

// obtener código postal
string Contacto::obtenerCodigoPostal() {
  return string(codigoPostal);
}

// establecer saldo
void Contacto::establecerSaldo(double valorSaldo) { 
  saldo = valorSaldo; 
}

// obtener saldo
double Contacto::obtenerSaldo() { 
  return saldo; 
}

// imprimir contacto
void Contacto::imprimirContacto() {
  cout << left
  << setw(30) << obtenerPrimerNombre() << '\t'
  << setw(30) << obtenerApellido() << '\t'
  << setw(30) << obtenerDireccion() << '\t'
  << setw(30) << obtenerCiudad() << '\t'
  << setw(30) << obtenerEstado() << '\t'
  << setw(30) << obtenerCodigoPostal() << '\t'
  << setw(30) << setprecision(2) << fixed << obtenerSaldo() 
  << endl;
}

// imprimir cabecera
void Contacto::imprimirCabecera() {
  cout << left
  << setw(31) << "NOMBRE\t" 
  << setw(25) << "APELLIDO\t" 
  << setw(27) << "DIRECCIÓN\t"
  << setw(31) << "CIUDAD\t"
  << setw(31) << "ESTADO\t"
  << setw(31) << "CÓDIGO POSTAL\t"
  << setw(30) << "SALDO\t" 
  << endl;
}
