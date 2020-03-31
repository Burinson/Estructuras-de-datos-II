// Práctica #6
// Equipo 2
//  Almazán de la Torre Rubén
//  Dueñas Becerra Mario Alejandro
//  Guzmán Mendoza Jesús Uriel
//  Martínez Yañez Astra Bernardino
//  Torres García Oscar
//  Vázquez Martínez Edgar Isaias
// Sección: D-05
// Calendario: 2020-A

#include "Menu.h"
#include <fstream>

int main() {
  Menu menu;
  Pila<Cheque> cheques; // pila de cheques
  Pila<ChequeRechazado> chequesRechazados; // pila de cheques rechazados

  fstream archivoCheques("cheques.dat", ios::in | ios::out | ios::app); // archivo de cheques
  fstream archivoChequesRechazados("cheques_rech.dat", ios::in | ios::out | ios::app); // archivo de
  // cheques rechazados

  menu.leer(archivoCheques, cheques); // leer datos de cheques
  menu.leer(archivoChequesRechazados, chequesRechazados); // leer datos de cheques rechazados
  
  string op;
  do {
    menu.mostrar(op);
    if (op == "1") 
      menu.registrarCheque(cheques);
    else if (op == "2")
      menu.procesarCheque(cheques);
    else if (op == "3")
      menu.registrarChequeRechazado(chequesRechazados);
    else if (op == "4")
      menu.procesarChequeRechazado(chequesRechazados);
    else if (op == "5") {
      menu.guardar(archivoCheques, cheques); // guardar información sobre cheques
      menu.guardar(archivoChequesRechazados, chequesRechazados); // guardar información sobre cheques
      // rechazados
    } else
      cout << "\n(!) No existe esta opción\n";
  } while (op != "5");
}