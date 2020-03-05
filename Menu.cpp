#include "Menu.h"
using namespace std;


// mostrar menú
char Menu::mostrarMenu(fstream &archivoCreditoEntradaSalida) {
  archivoCreditoEntradaSalida.clear(); // Restaura el estado del flujo a “bueno”
  archivoCreditoEntradaSalida.seekg(0, ios::beg); // reposicionar puntero al principio del archivo

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
void Menu::darAltaCliente(fstream &archivoCreditoEntradaSalida) {
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

  Cliente clienteAnterior;

  archivoCreditoEntradaSalida.seekg((valorNumeroCuenta - 1) * sizeof(Cliente));   // reposicionar puntero a número de cuenta
  archivoCreditoEntradaSalida.read(reinterpret_cast<char *>(&clienteAnterior), sizeof(Cliente));

  if (clienteAnterior.obtenerNumeroCuenta() != 0) {
    cout << "Esta cuenta ya existe\n";
    return;
  }
  
  cout << "Teclea apellido, primer nombre, saldo\n?";
  cin >> valorApellido >> valorPrimerNombre >> valorSaldo;

  Cliente c;
  c.establecerNumeroCuenta(valorNumeroCuenta);
  c.establecerApellido(valorApellido);
  c.establecerPrimerNombre(valorPrimerNombre);
  c.establecerSaldo(valorSaldo);

  archivoCreditoEntradaSalida.seekp((valorNumeroCuenta - 1) * sizeof(Cliente));   // reposicionar puntero a número de cuenta
  archivoCreditoEntradaSalida.write(reinterpret_cast<const char *>(&c), sizeof(Cliente)); // leer cuenta

  cout << "La dirección es: " << int(archivoCreditoEntradaSalida.tellp()) - int(sizeof(Cliente)) << '\n'; // posición en la que se guardó
  cout << "Tamaño del objeto es: " << sizeof(c) << '\n';  // tamaño del objeto
}

// dar de baja cliente
void Menu::darBajaCliente(fstream &archivoCreditoEntradaSalida) {
  int valorNumeroCuenta;
  Cliente c;

  cout << "Escriba el numero de cuenta (De 1 a 100, 0 para terminar la entrada)\n?";
  cin >> valorNumeroCuenta;

  if (valorNumeroCuenta < 0 || valorNumeroCuenta > 100) {
    cout << "Opción no existe\n";
    return;
  }

  archivoCreditoEntradaSalida.seekg((valorNumeroCuenta - 1) * sizeof(Cliente)); // reposicionar puntero
  archivoCreditoEntradaSalida.read(reinterpret_cast<char *>(&c), sizeof(Cliente)); // leer cuenta

  if (c.obtenerNumeroCuenta() != 0) {
    cout << "Registro eliminado exitosamente\n";
    c = Cliente();
    archivoCreditoEntradaSalida.seekp((valorNumeroCuenta - 1) * sizeof(Cliente));   // reposicionar puntero
    archivoCreditoEntradaSalida.write(reinterpret_cast<const char *>(&c), sizeof(Cliente)); // eliminar cuenta
  } else {
    cout << "Esta cuenta no existe\n";
  }

}

// cambiar saldo de cliente
void Menu::cambiarSaldoCliente(fstream &archivoCreditoEntradaSalida) {
  int valorNumeroCuenta;
  Cliente c;
  double transaccion;

  cout << "Escriba el numero de cuenta (De 1 a 100, 0 para terminar la entrada)\n?";
  cin >> valorNumeroCuenta;

  if (valorNumeroCuenta < 0 || valorNumeroCuenta > 100) {
    cout << "Opción no existe\n";
    return;
  }

  archivoCreditoEntradaSalida.seekp((valorNumeroCuenta - 1) * sizeof(Cliente));   // reposicionar puntero
  archivoCreditoEntradaSalida.read(reinterpret_cast<char *>(&c), sizeof(Cliente)); // leer cuenta

  if (c.obtenerNumeroCuenta() != 0) {
    c.imprimirCabecera();
    c.imprimirCliente();

    cout << "Escriba cargo (+) o abono (-): ";
    cin >> transaccion;

    c.establecerSaldo(c.obtenerSaldo() + transaccion);

    c.imprimirCabecera();
    c.imprimirCliente();

    archivoCreditoEntradaSalida.seekp((valorNumeroCuenta - 1) * sizeof(Cliente));  // reposicionar puntero
    archivoCreditoEntradaSalida.write(reinterpret_cast<const char *>(&c), sizeof(Cliente));  // actualizar cuenta
  } else {
    cout << "Esta cuenta no existe\n";
  }
}

// consulta individual
void Menu::consultaIndividual(fstream &archivoCreditoEntradaSalida) {
  int valorNumeroCuenta;
  Cliente c;

  cout << "Escriba el numero de cuenta (De 1 a 100, 0 para terminar la entrada)\n?";
  cin >> valorNumeroCuenta;

  if (valorNumeroCuenta < 0 || valorNumeroCuenta > 100) {
    cout << "Opción no existe\n";
    return;
  } 

  archivoCreditoEntradaSalida.seekg((valorNumeroCuenta - 1) * sizeof(Cliente));  // reposicionar puntero
  archivoCreditoEntradaSalida.read(reinterpret_cast<char *>(&c), sizeof(Cliente)); // leer cuenta

  if (c.obtenerNumeroCuenta() != 0) {
    c.imprimirCabecera();
    c.imprimirCliente();
  } else {
    cout << "Esta cuenta no existe\n";
  }
}

// consulta general
void Menu::consultaGeneral(fstream &archivoCreditoEntradaSalida) {
  Cliente c;

  c.imprimirCabecera();
  while(!archivoCreditoEntradaSalida.eof()) { // leer hasta fin del archivo

    archivoCreditoEntradaSalida.read(reinterpret_cast<char *>(&c), sizeof(Cliente)); // leer cuenta

    if (archivoCreditoEntradaSalida.eof()) // no imprimir si es el último
      break;

    if (c.obtenerNumeroCuenta() != 0) {
      c.imprimirCliente();
    }
  }
}