// Práctica #5
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
  fstream archivoCreditoEntradaSalida; // creación de flujo
  archivoCreditoEntradaSalida.open("contactos.txt", ios::in | ios::out | ios::app);

  while(leer) {
    // leer opción
    int op = menu.mostrarMenu(archivoCreditoEntradaSalida); 

    // dar de alta contacto
    if (op == 1)  
      menu.darAltaContacto(archivoCreditoEntradaSalida); 

    // consulta individual 
    if (op == 2)  
      menu.consultaIndividual(archivoCreditoEntradaSalida); 
     
    // consulta general 
    if (op == 3)  
      menu.consultaGeneral(archivoCreditoEntradaSalida); 

    //salir 
    if (op == 4) 
      leer = false; 
      
    if (op < 1 || op > 4)  
      cout << "Opción no válida\n"; // validar opción
  } 

  archivoCreditoEntradaSalida.close();
  return 0; 
} // fin de main