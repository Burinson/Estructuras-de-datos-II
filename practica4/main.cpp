// Práctica #4
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
  archivoCreditoEntradaSalida.open("credito.dat", ios::in | ios::out);

  while(leer) {
    int op = menu.mostrarMenu(archivoCreditoEntradaSalida); // recuperar opción

    if (op == 1)  
      menu.darAltaCliente(archivoCreditoEntradaSalida); // dar de alta a a cliente
     
    if (op == 2)  
      menu.darBajaCliente(archivoCreditoEntradaSalida); // dar de baja a cliente
     
    if (op == 3)  
      menu.cambiarSaldoCliente(archivoCreditoEntradaSalida); // cambiar saldo a cliente
     
    if (op == 4) 
      menu.consultaIndividual(archivoCreditoEntradaSalida); // consulta individual
    
    if (op == 5) 
      menu.consultaGeneral(archivoCreditoEntradaSalida); // consultas generales

    if (op == 6)
      leer = false;
      
    if (op < 0 || op > 6)  
      cout << "Opción no válida\n"; // validar opción
  } 

  archivoCreditoEntradaSalida.close();
  return 0; 
} // fin de main