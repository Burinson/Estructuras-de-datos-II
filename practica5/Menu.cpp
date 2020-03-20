#include "Menu.h"
using namespace std;


// mostrar menú
char Menu::mostrarMenu(fstream &archivoCreditoEntradaSalida) {
  archivoCreditoEntradaSalida.clear(); // Restaura el estado del flujo a “bueno”
  archivoCreditoEntradaSalida.seekg(0, ios::beg); // reposicionar puntero al principio del archivo

  int op;

  cout << "Menú - Agenda de Contactos\n"
    << "1. Alta de contacto\n"
    << "2. Consulta individual (utilizar llave canónica)\n"
    << "3. Consultas generales\n"
    << "4. Salir\n"
    << "Elige tu opción: ";
  cin >> op;
  cout << '\n';
  return op;
}

// dar de alta cliente
void Menu::darAltaContacto(fstream &archivoCreditoEntradaSalida) {
  string valorPrimerNombre, valorApellido, valorDireccion, valorCiudad, valorEstado, valorCodigoPostal;
  double valorSaldo;
  Cliente c;

  cout << "Primer nombre: ";
  cin >> valorPrimerNombre;

  cout << "Apellido: ";
  cin >> valorApellido;

  cout << "Dirección: ";
  cin >> valorDireccion;

  cout << "Ciudad: ";
  cin >> valorCiudad;

  cout << "Estado: ";
  cin >> valorEstado;

  cout << "Código postal: ";
  cin >> valorCodigoPostal;

  cout << "Saldo: ";
  cin >> valorSaldo;

  c = Cliente(valorPrimerNombre, valorApellido, valorDireccion, valorCiudad, valorEstado, valorCodigoPostal, valorSaldo);

  archivoCreditoEntradaSalida.write(reinterpret_cast<const char *>(&c), sizeof(Cliente)); // escribir cuenta
}

// consulta individual
void Menu::consultaIndividual(fstream &archivoCreditoEntradaSalida) {

}

// consulta general
void Menu::consultaGeneral(fstream &archivoCreditoEntradaSalida) {

}