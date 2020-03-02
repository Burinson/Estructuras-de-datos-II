#include "Menu.h"
using namespace std;

// menú
Menu::Menu() {
  archivoCreditoEntradaSalida = fstream("credito.dat", ios::in | ios::out);
}


// mostrar menú
char Menu::mostrarMenu() {
  archivoCreditoEntradaSalida.clear();
  archivoCreditoEntradaSalida.seekg(0, ios::beg);

  int op;

  cout << "Menú - Sistema de Cuentas\n"
    << "1. Altas\n"
    << "2. Bajas (eliminar un registro)\n"
    << "3. Cambios (actualizar el saldo de la cuenta)\n"
    << "4. Consultas individuales (número de cuenta)\n"
    << "5. Consultas generales\n"
    << "6. Salir\n"
    << "Elige tu opción: ";
  cin >> op;
  cout << '\n';
  return op;
}

// dar de alta cliente
void Menu::darAltaCliente() {

  int valorNumeroCuenta;
  string valorApellido, valorPrimerNombre;
  double valorSaldo;

  cout << "Escriba el numero de cuenta (De 1 a 100, 0 para terminar la entrada)\n?";
  cin >> valorNumeroCuenta;

  if (valorNumeroCuenta < 0 || valorNumeroCuenta > 100) {
    cout << "Opción no existe\n";
    return;
  }

  if (valorNumeroCuenta == 0) return;

  cout << "Teclea apellido, primer nombre, saldo\n?";
  cin >> valorApellido >> valorPrimerNombre >> valorSaldo;

  Cliente c;
  c.establecerNumeroCuenta(valorNumeroCuenta);

  c.establecerApellido(valorApellido);
  c.establecerPrimerNombre(valorPrimerNombre);
  c.establecerSaldo(valorSaldo);

  archivoCreditoEntradaSalida.seekp((c.obtenerNumeroCuenta() - 1) * sizeof(Cliente));  
  archivoCreditoEntradaSalida.write(reinterpret_cast<const char *>(&c), sizeof(Cliente));

  cout << "La dirección es: " << int(archivoCreditoEntradaSalida.tellp()) - int(sizeof(Cliente)) << '\n';
  cout << "Tamaño del objeto es: " << sizeof(c) << '\n';
}

// dar de baja cliente
void Menu::darBajaCliente() {

  int valorNumeroCuenta;
  Cliente c;

  cout << "Escriba el numero de cuenta (De 1 a 100, 0 para terminar la entrada)\n?";
  cin >> valorNumeroCuenta;

  if (valorNumeroCuenta < 0 || valorNumeroCuenta > 100) {
    cout << "Opción no existe\n";
    return;
  }

  archivoCreditoEntradaSalida.seekp((valorNumeroCuenta - 1) * sizeof(Cliente));  
  archivoCreditoEntradaSalida.write(reinterpret_cast<const char *>(&c), sizeof(Cliente));

  if (c.obtenerNumeroCuenta() != 0) {
    c = Cliente();
    archivoCreditoEntradaSalida.seekp((valorNumeroCuenta - 1) * sizeof(Cliente));  
    archivoCreditoEntradaSalida.write(reinterpret_cast<const char *>(&c), sizeof(Cliente)); 
  }

}

// cambiar saldo de cliente
void Menu::cambiarSaldoCliente() {

  int valorNumeroCuenta;
  Cliente c;
  int transaccion;

  cout << "Escriba el numero de cuenta (De 1 a 100, 0 para terminar la entrada)\n?";
  cin >> valorNumeroCuenta;

  if (valorNumeroCuenta < 0 || valorNumeroCuenta > 100) {
    cout << "Opción no existe\n";
    return;
  }

  archivoCreditoEntradaSalida.seekp((valorNumeroCuenta - 1) * sizeof(Cliente));  
  archivoCreditoEntradaSalida.read(reinterpret_cast<char *>(&c), sizeof(Cliente));

  if (c.obtenerNumeroCuenta() != 0) {
    c.imprimirCliente();

    cout << "Escriba cargo (+) o abono (-): ";
    cin >> transaccion;

    c.establecerSaldo(c.obtenerSaldo() + transaccion);

    c.imprimirCliente();

    archivoCreditoEntradaSalida.seekp((valorNumeroCuenta - 1) * sizeof(Cliente));  
    archivoCreditoEntradaSalida.write(reinterpret_cast<const char *>(&c), sizeof(Cliente)); 
  } 
}

// consulta individual
void Menu::consultaIndividual() {
  int valorNumeroCuenta;
  Cliente c;

  cout << "Escriba el numero de cuenta (De 1 a 100, 0 para terminar la entrada)\n?";
  cin >> valorNumeroCuenta;

  if (valorNumeroCuenta < 0 || valorNumeroCuenta > 100) {
    cout << "Opción no existe\n";
    return;
  } 

  archivoCreditoEntradaSalida.seekg((valorNumeroCuenta - 1) * sizeof(Cliente));  
  archivoCreditoEntradaSalida.read(reinterpret_cast<char *>(&c), sizeof(Cliente));

  if (c.obtenerNumeroCuenta() != 0) 
    c.imprimirCliente();  
}

// consulta general
void Menu::consultaGeneral() {
  Cliente c;

  while(!archivoCreditoEntradaSalida.eof()) {

    archivoCreditoEntradaSalida.read(reinterpret_cast<char *>(&c), sizeof(Cliente));

    if (archivoCreditoEntradaSalida.eof()) 
      break;

    if (c.obtenerNumeroCuenta() != 0) 
      c.imprimirCliente();
  }
}