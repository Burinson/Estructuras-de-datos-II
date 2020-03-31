#include "Cheque.h"
class ChequeRechazado : public Cheque { // hereda atributos de la superclase cheque
  private:
    double cargo; // único atributo que difiere de la superclase
  public:
    double obtenerCargo() {
      return this->cargo;
    }
    ChequeRechazado() {};
    ChequeRechazado(int num_cheque, string nombre_banco, int cuenta_depositar, double monto, double cargo) {
      this->num_cheque = num_cheque;
      strcpy(this->nombre_banco, nombre_banco.c_str());
      this->cuenta_depositar = cuenta_depositar;
      this->monto = monto;
      this->cargo = cargo;
    }
    void establecerCargo(double cargo) {
      this->cargo = cargo;
    }

    // clase virtual para sobreescribir la función del mismo nombre de la superclase
    virtual void imprimir() {
      cout << left 
      << "Número de cheque\t" 
      << setw(30) << "Nombre de banco\t" 
      << setw(30) << "Cuenta a depositar\t" 
      << setw(30) << "Monto\t" 
      << setw(30) << "cargo" 
      << '\n';

      cout << left << num_cheque << setw(17) << '\t'
      << nombre_banco << setw(23) << '\t'
      << cuenta_depositar << setw(28) << '\t'
      << monto << setw(25) << '\t'
      << cargo << '\n';
    }
};
