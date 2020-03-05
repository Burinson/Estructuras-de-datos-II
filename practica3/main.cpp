// Práctica #3
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
#define what(a) cout << #a << ": " << a << '\n'

void menu(char &op) {
  cout << "MENÚ - INVESTIGACIÓN DE CRÉDITOS\n"
       << "1. Consulta individual (número de cuenta)\n"
       << "2. Consultas generales\n"
       << "3. Salir\n"
       << "Elige tu opción: ";
  cin >> op;
} 


#include "Cliente.cpp"

int main() {
  char op;
  bool leer = true;

  ifstream archivoClientesEntrada;
  
  archivoClientesEntrada.open("credito.dat", ios::in | ios::binary); // abre el archivo

  while(leer) {
    menu(op); // mostrar menú

    // consulta individual 
    if (op == '1') { 
      // cliente en blanco     
      Cliente c;

      int valorNumeroCuenta;

      // leer número de cuenta
      cout << "Número de cuenta: ";
      cin >> valorNumeroCuenta;

      // poisicionar puntero en el número de cuenta del cliente
      archivoClientesEntrada.seekg((valorNumeroCuenta - 1) * sizeof(Cliente)); 

      // leer un registro
      archivoClientesEntrada.read((char *)&c, sizeof(Cliente)); 

      if (c.obtenerNumeroCuenta() != 0) {
        // imprimir el cliente
        c.imprimirCabecera();
        c.imprimirCliente();
      } else {
        cout << "Esta cuenta no existe\n";
      }

      // consultas generales
      } else if (op == '2') { 
        // cliente en blanco
        Cliente c; 

        c.imprimirCabecera();
        // leer mientras no sea fin de archivo
        while(!archivoClientesEntrada.eof()) { 

          // leer registro
          archivoClientesEntrada.read((char *)&c, sizeof(Cliente)); 

          // no imprimir si se ha llegado al final del archivo
          if (archivoClientesEntrada.eof())
            break;

          // solo imprimir cuentas válidas
          if (c.obtenerNumeroCuenta()) 
            c.imprimirCliente(); 
        }

      // salir
      } else if (op == '3') { 
        // deshabilita opción de seguir leyendo
        leer = false;

        // cierra el archivo
        archivoClientesEntrada.close();
        
      // opción no válida
      } else if (op < '0' || op > 3) { 
        cout << "Opción no válida\n";
      } 

    // Reestablece el estado del flujo a "bueno"
    archivoClientesEntrada.clear();

    // posicionar el puntero en 0 para leer otra vez
    archivoClientesEntrada.seekg(0, ios::beg);

  } // fin del while
  return 0; 
} // fin del main