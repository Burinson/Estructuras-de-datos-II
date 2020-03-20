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
  << setw(16) << obtenerPrimerNombre()
  << setw(16) << obtenerApellido()
  << setw(16) << obtenerDireccion()
  << setw(16) << obtenerDireccion()
  << setw(16) << obtenerCiudad()
  << setw(16) << obtenerCodigoPostal()
  << setw(16) << setprecision(2) << fixed << obtenerSaldo() 
  << endl;
}

// imprimir cabecera
void Contacto::imprimirCabecera() {
  cout << left
  << setw(16) << "NOMBRE" 
  << setw(16) << "APELLIDO" 
  << setw(16) << "DIRECCIÓN"
  << setw(16) << "CIUDAD"
  << setw(17) << "ESTADO"
  << setw(17) << "CÓDIGO POSTAL"
  << setw(16) << "SALDO" 
  << endl;
}
