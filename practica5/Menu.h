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
    void darAltaContacto(fstream&);
    void consultaIndividual(fstream&);
    void consultaGeneral(fstream&);
};