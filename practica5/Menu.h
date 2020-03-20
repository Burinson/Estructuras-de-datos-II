#include <fstream>
#include <iostream>
#include <string>
#include "Contacto.cpp"
using namespace std;

class Menu {
  private:
    int op;
    struct llaveCanonina {
      string primerNombre;
      string valorApellido;
    } llave;
  public:
    Menu() {};
    char mostrarMenu(fstream&);
    void darAltaContacto(fstream&);
    void consultaIndividual(fstream&);
    void consultaGeneral(fstream&);
    bool existeLlave(fstream, string, string);
    void estandarizar(string&);
    bool llaveCorresponde(string, string, Contacto);
};