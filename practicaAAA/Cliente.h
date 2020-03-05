#include <bits/stdc++.h>
using namespace std;

class Cliente {
 private:
  int numeroCuenta;
  char apellido[15];
  char primerNombre[10];
  double saldo;

 public:
  Cliente(int = 0, string = "", string = "", double = 0.0);
  void establecerNumeroCuenta(int);
  int obtenerNumeroCuenta();
  void establecerApellido(string);
  string obtenerApellido();
  void establecerPrimerNombre(string);
  string obtenerPrimerNombre();
  void establecerSaldo(double);
  double obtenerSaldo();
};  // fin de clase Cliente
