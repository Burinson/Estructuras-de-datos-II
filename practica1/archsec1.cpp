#include <bits/stdc++.h>
using namespace std;
int main() {
  cerr << "kwejfw" << endl;
  int cuenta;
  char nombre[30];
  double saldo;
  ofstream archivoClientesSalida;
  archivoClientesSalida.open("clientes.txt", ios::out);
  if (!archivoClientesSalida) {
    cerr << "No se pudo abrir el arhivo" << endl;
    exit(1);
  }
  cout << "Escriba el número de cuenta, nombre y saldo." << endl
       << "Escriba fin de archivo para terminar la entrada. \n ?";
  while (cin >> cuenta >> nombre >> saldo) {
    archivoClientesSalida << cuenta << " " << nombre << " " << saldo << endl;
    cout << "?";
  }
  archivoClientesSalida.close();
  return 0;
}