#include "Pila.cpp"
#include "Cheque.h"
#include "ChequeRechazado.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
class Menu {
  private:
  public:
    void mostrar(string &op) {
      cout << '\n';
      cout << "Menú - Administración de cheques\n";
      cout << "1. Registrar Cheque - (insertar)\n";
      cout << "2. Procesar Cheque - (eliminar)\n";
      cout << "3. Registrar Cheque Rechazado - (insertar)\n";
      cout << "4. Procesar Cheque Rechazado - (eliminar)\n";
      cout << "5. Salir\n";
      cout << "Elige tu opción: ";
      cin >> op;
      cout << "\n";
    }
    void registrarCheque(Pila<Cheque> &cheques) {
      if (cheques.lleno()) {
        cout << "(!) Pila de cheques llena\n";
        return;
      }
      int num_cheque;
      string nombre_banco;
      int cuenta_depositar;
      double monto;

      // leer atributos
      cout << "Número de cheque: ";
      cin >> num_cheque;

      cout << "Nombre de banco: ";
      cin >> nombre_banco;

      cout << "Cuenta a depositar: ";
      cin >> cuenta_depositar;

      cout << "Monto: ";
      cin >> monto;

      // insertar objeto cheque a la pila de cheques
      Cheque c(num_cheque, nombre_banco, cuenta_depositar, monto);
      cheques.insertar(c);
    }

    void procesarCheque(Pila<Cheque> &cheques) {
      // si está vacío, imprimir, si no, mandar mensaje
      if (!cheques.vacio()) {
        cheques.arriba().imprimir();
        cheques.eliminar();
      } else 
        cout << "(!) Pila vacía, no hay cheques\n";
    }

    void registrarChequeRechazado(Pila<ChequeRechazado> &cheques_rechazados) {
      if (cheques_rechazados.lleno()) {
        cout << "(!) Pila de cheques rechazados llena\n";
        return;
      }
      int num_cheque;
      string nombre_banco;
      int cuenta_depositar;
      double monto;
      double cargo;

      // leer atributos
      cout << "Número de cheque: ";
      cin >> num_cheque;

      cout << "Nombre de banco: ";
      cin >> nombre_banco;

      cout << "Cuenta a depositar: ";
      cin >> cuenta_depositar;

      cout << "Monto: ";
      cin >> monto;    

      cout << "Cargo: ";
      cin >> cargo;

      // agregar clase cheque rechazado a la pila de cheques rechazados
      ChequeRechazado c(num_cheque, nombre_banco, cuenta_depositar, monto, cargo);  
      cheques_rechazados.insertar(c);
    }

    void procesarChequeRechazado(Pila<ChequeRechazado> &cheques_rechazados) {
      // si está vacía, imprimir mensaje, si no, imprimir cheque rechazado y eliminarlo
      if (!cheques_rechazados.vacio()) {
        cheques_rechazados.arriba().imprimir();
        cheques_rechazados.eliminar();
      } else 
        cout << "(!) Pila vacía, no hay cheques rechazados\n";   
    }

    // leer información sobre cheques del archivo físico
    void leer(fstream &archivo, Pila<Cheque> &cheques) {
      int len;
      string campo, num_cheque, nombre_banco, cuenta_depositar, monto;
      while (!archivo.eof()) {
        if (archivo.peek() == -1)
          break;

        // leer registro
        archivo.read(reinterpret_cast<char *>(&len), sizeof(int));
        char *buffer = new char[len];
        archivo.read(buffer, len);
        campo = buffer;
        delete [] buffer;

        // crear un registro vacío
        stringstream ss(campo);

        // leer atributos
        getline(ss, num_cheque, '|');
        getline(ss, nombre_banco, '|');
        getline(ss, cuenta_depositar, '|');
        getline(ss, monto, '|');

        // crear un objeto cheque e insertarlo a la pila de cheques
        Cheque c(stoi(num_cheque), nombre_banco, stoi(cuenta_depositar), stod(monto));
        cheques.insertar(c);
      }
      archivo.close();
    }

    // leer información sobre cheques rechazados del archivo físico
    void leer(fstream &archivo, Pila<ChequeRechazado> &chequesRechazados) {
      int len;
      string campo, num_cheque, nombre_banco, cuenta_depositar, monto, cargo;

      // leer mientras no esté vacío el archivo
      while (!archivo.eof()) {
        if (archivo.peek() == -1)
          break;
        // leer registro
        archivo.read(reinterpret_cast<char *>(&len), sizeof(int));
        char *buffer = new char[len];
        archivo.read(buffer, len);
        campo = buffer;
        delete [] buffer;

        // crear registro vacío
        stringstream ss(campo);

        // leer atributos
        getline(ss, num_cheque, '|');
        getline(ss, nombre_banco, '|');
        getline(ss, cuenta_depositar, '|');
        getline(ss, monto, '|');
        getline(ss, cargo, '|');

        // crear objeto de cheque rechazado y agregarlo a la pila de cheques rechazados vacíos
        ChequeRechazado c(stoi(num_cheque), nombre_banco, stoi(cuenta_depositar), stod(monto), stod(cargo));
        chequesRechazados.insertar(c);
      }
      archivo.close();
    }

    // guardar información sobre cheques en el archivo físico
    void guardar(fstream &archivo, Pila<Cheque> &cheques) {
      archivo.open("cheques.dat", ios::out | ios::trunc);
      archivo.clear(); // Restaura el estado del flujo a “bueno”
      archivo.seekg(0, ios::beg); // reposicionar puntero al principio del archivo

      // Pila auxiliar para insertar el el orden correcto a la hora de leer
      Pila<Cheque> aux;
      while (!cheques.vacio()) {
        aux.insertar(cheques.arriba());
        cheques.eliminar();
      }

      int len;

      while (!aux.vacio()) {
        Cheque c = aux.arriba();
        aux.eliminar();

        string campo;

        campo += to_string(c.obtenerNumCheque()) + '|' +
        c.obtenerNombreBanco() + '|' +
        to_string(c.obtenerCuentaDepositar()) + '|' +
        to_string(c.obtenerMonto()) + '|';

        len = campo.size();
        archivo.write(reinterpret_cast<char *>(&len), sizeof(int));
        archivo.write(campo.c_str(), len);
      }
      archivo.close();
    }

      // guardar información sobre cheques rechazados en el archivo físico
      void guardar(fstream &archivo, Pila<ChequeRechazado> &cheques_rechazados) {
      archivo.open("cheques_rech.dat", ios::out | ios::trunc);
      archivo.clear(); // Restaura el estado del flujo a “bueno”
      archivo.seekg(0, ios::beg); // reposicionar puntero al principio del archivo

      int len;

      // Pila auxiliar para insertar el el orden correcto a la hora de leer
      Pila<ChequeRechazado> aux;
      while (!cheques_rechazados.vacio()) {
        aux.insertar(cheques_rechazados.arriba());
        cheques_rechazados.eliminar();
      }

      while (!aux.vacio()) {
        ChequeRechazado c = aux.arriba();
        aux.eliminar();

        string campo;

        campo += to_string(c.obtenerNumCheque()) + '|' +
        c.obtenerNombreBanco() + '|' +
        to_string(c.obtenerCuentaDepositar()) + '|' +
        to_string(c.obtenerMonto()) + '|' +
        to_string(c.obtenerCargo()) + '|';
        
        int len = campo.size();
        archivo.write(reinterpret_cast<char *>(&len), sizeof(int));
        archivo.write(campo.c_str(), len);
      }
      archivo.close();
    }
};