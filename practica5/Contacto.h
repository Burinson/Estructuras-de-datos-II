#include <fstream>
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
#define what(x) cout << #x << ": " << x << '\n'

class Contacto {
 private:
  char primerNombre[50];
  char apellido[50];
  char direccion[50];
  char ciudad[50];
  char estado[50];
  char codigoPostal[50];
  double saldo;

 public:
  Contacto(string = "", string = "", string = "", string = "", string = "", string = "", double = 0.0);

  void establecerPrimerNombre(string);
  string obtenerPrimerNombre();

  void establecerApellido(string);
  string obtenerApellido();

  void establecerDireccion(string);
  string obtenerDireccion();

  void establecerCiudad(string);
  string obtenerCiudad();

  void establecerEstado(string);
  string obtenerEstado();

  void establecerCodigoPostal(string);
  string obtenerCodigoPostal();

  void establecerSaldo(double);
  double obtenerSaldo();
  void imprimirCabecera();
  void imprimirContacto();
};  
