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

#include <iostream>
using namespace std;

#include "Menu.cpp"

int main() {
  Menu menu;
  bool leer = true;  

  while(leer) {
    int op = menu.mostrarMenu();

    if (op == 1)  
      menu.darAltaCliente();
     
    if (op == 2)  
      menu.darBajaCliente();
     
    if (op == 3)  
      menu.cambiarSaldoCliente();
     
    if (op == 4) 
      menu.consultaIndividual();
    
    if (op == 5) 
      menu.consultaGeneral();
    if (op == 6)
      leer = false;
    if (op < 0 || op > 6)  
      cout << "Opción no válida\n";
  } 
  return 0; 
} 