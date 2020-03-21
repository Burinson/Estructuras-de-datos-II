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
    void guardarContacto(fstream&, Contacto);
    bool leerContacto(fstream&, Contacto&);
    bool existeLlave(fstream, string, string);
    void estandarizar(string&);
    void mensaje(string);
    bool llaveCorresponde(string, string, Contacto);
};