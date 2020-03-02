#include <fstream>
#include <iostream>
#include <string>
#include "Cliente.cpp"
using namespace std;

class Menu {
  private:
    int op;
    fstream archivoCreditoEntradaSalida;
  public:
    Menu();
    char mostrarMenu();
    void darAltaCliente();
    void darBajaCliente();
    void cambiarSaldoCliente();
    void consultaIndividual();
    void consultaGeneral();
    void mostrarDirectorio();
};