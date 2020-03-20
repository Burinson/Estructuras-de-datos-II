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
  fstream archivoAgendaES; // creación de flujo
  archivoAgendaES.open("contactos.txt", ios::in | ios::out | ios::app);

  while(leer) {
    // leer opción
    int op = menu.mostrarMenu(archivoAgendaES); 

    // dar de alta contacto
    if (op == 1)  
      menu.darAltaContacto(archivoAgendaES); 

    // consulta individual 
    if (op == 2)  
      menu.consultaIndividual(archivoAgendaES); 
     
    // consulta general 
    if (op == 3)  
      menu.consultaGeneral(archivoAgendaES); 

    //salir 
    if (op == 4) 
      leer = false; 
      
    if (op < 1 || op > 4)  
      cout << "Opción no válida\n"; // validar opción
  } 

  archivoAgendaES.close();
  return 0; 
} // fin de main