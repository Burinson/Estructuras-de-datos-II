#include <bits/stdc++.h>
using namespace std;
void mostrarLinea(int, const char* const, double);
int main() {
  int cuenta;
  char nombre[30];
  double saldo;
  ifstream archivoClientesEntrada;
  archivoClientesEntrada.open("clientes.txt", ios::in);
  if (!archivoClientesEntrada) {
    cerr << "No se pudo arbrir el archivo" << endl;
    exit(1);
  }
  cout << left << setw(10) << "cuenta" << setw(13) << "nombre"
       << "saldo" << endl
       << fixed << showpoint;
  while (archivoClientesEntrada >> cuenta >> nombre >> saldo)
    mostrarLinea(cuenta, nombre, saldo);
  archivoClientesEntrada.close();
  return 0;
}
void mostrarLinea(int cuenta, const char* const nombre, double saldo) {
  cout << left << setw(10) << cuenta << setw(13) << nombre << setw(7)
       << setprecision(2) << right << saldo << endl;
}