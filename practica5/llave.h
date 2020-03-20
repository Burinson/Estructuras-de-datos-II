#include <iostream>
#include <string.h>
using namespace std;

class Llave {
  private:
    string primerNombre;
    string apellido;
  public:
    Llave(string primerNombre, string apellido) {
      this->primerNombre = primerNombre;
      this->apellido = apellido;
    }
};