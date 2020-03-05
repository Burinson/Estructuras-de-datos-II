#include <fstream>
#include <iostream>
#include <string>
#include "Cliente.cpp"
using namespace std;

class Menu {
  private:
    int op;
  public:
    Menu() {};
    char mostrarMenu(fstream&);
    void darAltaCliente(fstream&);
    void darBajaCliente(fstream&);
    void cambiarSaldoCliente(fstream&);
    void consultaIndividual(fstream&);
    void consultaGeneral(fstream&);
};