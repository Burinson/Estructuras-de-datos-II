// Práctica #1
// Equipo 2
//  Almazán de la Torre Rubén
//  Dueñas Becerra Mario Alejandro
//  Guzmán Mendoza Jesús Uriel
//  Martínez Yañez Astra Bernardino
//  Torres García Oscar
//  Vázquez Martínez Edgar Isaias
// Sección: D-05
// Calendario: 2020-A

#include <bits/stdc++.h>

using namespace std;

void mostrarLinea(int, const char* const, double);

int main() {

  int cuenta;
  char nombre[30];
  double saldo;
  char op;

  ifstream archivoClientesEntrada;
  archivoClientesEntrada.open("clientes.txt", ios::in);

  if (!archivoClientesEntrada) {
    cerr << "No se pudo arbrir el archivo" << endl;
    exit(1);
  }  // fin de if

  do {
    cout << "MENU - Investigación de créditos" << endl;
    cout << "1. Mostrar cuentas con todos los saldos en 0" << endl;
    cout << "2. Mostrar cuentas con saldo acreedor(-)" << endl;
    cout << "3. Mostrar cuentas con sald deudor(+)" << endl;
    cout << "4. Salir" << endl;
    cout << endl;
    cout << "Ingrese una opción: ";
    cin >> op;
    cout << endl;  // fin de menú

    archivoClientesEntrada.clear();  // cambia el estado de un booleano que
                                     // indica que se encuentra en el eof()
    archivoClientesEntrada.seekg(
        0,
        ios::beg);  // posiciona el puntero de lectura al principio del archivo

    if (op == '1') {
      cout << "CUENTAS CON SALDO EN CEROS" << endl;
      cout << left << setw(10) << "CUENTA" << setw(13) << "NOMBRE"
           << "SALDO" << endl
           << fixed << showpoint;

      while (archivoClientesEntrada >> cuenta >> nombre >> saldo)
        if (!saldo) mostrarLinea(cuenta, nombre, saldo);

      cout << endl;

    } else if (op == '2') {
      cout << "CUENTAS CON SALDO ACREEDOR" << endl;
      cout << left << setw(10) << "CUENTA" << setw(13) << "NOMBRE"
           << "SALDO" << endl
           << fixed << showpoint;

      while (archivoClientesEntrada >> cuenta >> nombre >> saldo)
        if (saldo < 0) mostrarLinea(cuenta, nombre, saldo);

      cout << endl;

    } else if (op == '3') {
      cout << "CUENTAS CON SALDO DEUDOR" << endl;
      cout << left << setw(10) << "CUENTA" << setw(13) << "NOMBRE"
           << "SALDO" << endl
           << fixed << showpoint;

      while (archivoClientesEntrada >> cuenta >> nombre >> saldo)
        if (saldo > 0) mostrarLinea(cuenta, nombre, saldo);

      cout << endl;

    } else if (!(op >= '1' && op <= '4')) {
      cout << "Opción no existe" << endl << endl;
    }  // fin de if/else if

  } while (op != '4');  // fin de do while

  archivoClientesEntrada.close();

  return 0;
}  // fin de main

void mostrarLinea(int cuenta, const char* const nombre, double saldo) {

  cout << left << setw(10) << cuenta << setw(13) << nombre << setw(7)
       << setprecision(2) << right << saldo << endl;
}  // fin de mostrarLinea