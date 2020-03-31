#ifndef Cheque_H
#define Cheque_H

#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;

class Cheque {
  protected: // permite que la clase heredada acceda a sus atributos
    int num_cheque;
    char nombre_banco[15];
    int cuenta_depositar;
    double monto;
  public:
    Cheque() {};
    Cheque(int num_cheque, string nombre_banco, int cuenta_depositar, double monto) {
      this->num_cheque = num_cheque;
      strcpy(this->nombre_banco, nombre_banco.c_str());
      this->cuenta_depositar = cuenta_depositar;
      this->monto = monto;
    }

    int obtenerNumCheque() {
      return num_cheque;
    }

    void establecerNumCheque(int num_cueque) {
      this->num_cheque = num_cheque;
    }

    string obtenerNombreBanco() {
      return string(nombre_banco);
    }

    void establecerNombreBanco(string nombre_banco) {
      strcpy(this->nombre_banco, nombre_banco.c_str());
    }

    int obtenerCuentaDepositar() {
      return cuenta_depositar;
    }

    void establecerCuentaDepositar(int cuenta_depositar) {
      this->cuenta_depositar = cuenta_depositar;
    }

    double obtenerMonto() {
      return monto;
    }

    void establecerMonto(double monto) {
      this->monto = monto;
    }

    // imprime un cheque
    void imprimir() {
      cout << left << "Número de cheque\t" 
      << setw(30) << "Nombre de banco\t" 
      << setw(30) << "Cuenta a depositar\t" 
      << setw(30) << "Monto\t" 
      << '\n';

      cout << left 
      << num_cheque << setw(17) << '\t'
      << nombre_banco << setw(15) << '\t'
      << cuenta_depositar << setw(28) << '\t'
      << monto << '\n';
    }
};
#endif