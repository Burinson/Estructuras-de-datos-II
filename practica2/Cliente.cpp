#include "Cliente.h"

Cliente::Cliente(int valorNumeroCuenta, string valorApellido,
                 string valorPrimerNombre, double valorSaldo) {
  establecerNumeroCuenta(valorNumeroCuenta);
  establecerApellido(valorApellido);
  establecerPrimerNombre(valorPrimerNombre);
  establecerSaldo(valorSaldo);
}

int Cliente::obtenerNumeroCuenta() { return numeroCuenta; }

void Cliente::establecerNumeroCuenta(int valorNumeroCuenta) {
  numeroCuenta = valorNumeroCuenta;
}

string Cliente::obtenerApellido() { return string(apellido); }

void Cliente::establecerApellido(string valorApellido) {
  strcpy(apellido, valorApellido.c_str());
}

string Cliente::obtenerPrimerNombre() { return string(primerNombre); }

void Cliente::establecerPrimerNombre(string valorPrimerNombre) {
  strcpy(primerNombre, valorPrimerNombre.c_str());
}

double Cliente::obtenerSaldo() { return saldo; }

void Cliente::establecerSaldo(double valorSaldo) { saldo = valorSaldo; }
