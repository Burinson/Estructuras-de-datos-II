#include "Cliente.h"
using namespace std;

Cliente::Cliente(int valorNumeroCuenta, string valorApellido, string valorPrimerNombre, double valorSaldo) {
  establecerNumeroCuenta(valorNumeroCuenta);
  establecerApellido(valorApellido);
  establecerPrimerNombre(valorPrimerNombre);
  establecerSaldo(valorSaldo);
}

int Cliente::obtenerNumeroCuenta() { 
  return numeroCuenta; 
}

void Cliente::establecerNumeroCuenta(int valorNumeroCuenta) {
  numeroCuenta = valorNumeroCuenta;
}

string Cliente::obtenerApellido() { 
  return string(apellido); 
}

void Cliente::establecerApellido(string valorApellido) {
  strcpy(apellido, valorApellido.c_str());
}

string Cliente::obtenerPrimerNombre() { 
  return string(primerNombre); 
}

void Cliente::establecerPrimerNombre(string valorPrimerNombre) {
  strcpy(primerNombre, valorPrimerNombre.c_str());
}

double Cliente::obtenerSaldo() { 
  return saldo; 
}

void Cliente::establecerSaldo(double valorSaldo) { 
  saldo = valorSaldo; 
}

void Cliente::imprimirCliente() { // imprimir un cliente
  cout << left << setw(10) << obtenerNumeroCuenta() << setw(13) << obtenerPrimerNombre() << setw(10) << obtenerApellido() << setw(5) << setprecision(2) << right << obtenerSaldo() << endl;
}

void Cliente::imprimirCabecera() {
  cout << left << setw(10) << "CUENTA" << setw(13) << "NOMBRE" << setw(10) << "APELLIDO" << setw(25) << setprecision(2) << "SALDO" << endl << fixed << showpoint;
}
