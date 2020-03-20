#include <fstream>
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

class Cliente {
 private:
  char apellido[15];
  char primerNombre[15];
  char direccion[15];
  char ciudad[15];
  char estado[15];
  char codigoPostal[15];
  double saldo;

 public:
  Cliente(string = "", string = "", string = "", string = "", string = "", string = "", double = 0.0);

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
  void imprimirCliente();
};  
