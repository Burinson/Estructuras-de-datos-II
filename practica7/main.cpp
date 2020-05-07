// Práctica #7
// Equipo 2
//    Almazán de la Torre Rubén
//    Dueñas Becerra Mario Alejandro
//    Guzmán Mendoza Jesús Uriel
//    Martínez Yañez Astra Bernardino
//    Torres García Oscar
//    Vázquez Martínez Edgar Isaias
// Sección: D-05
// Calendario: 2020-A

#include "Menu.h"

int main() {
  Menu menu;
  string op;

  double total = 0.0;

  Cola<Producto> carrito;
  fstream archivo("productos.dat", ios::in | ios::out | ios::app); // archivo lógico
  fstream totalArchivo("total.dat", ios::in | ios::out | ios::app); // archivo lógico

  menu.cargar(carrito, archivo, totalArchivo, total); // cargar información a la cola y total de venta
  do {
    menu.mostrar(op);
    if (op == "1")
      menu.comprar(carrito, total); // insertar productos a la cola
    else if (op == "2") 
      menu.vender(carrito, total); // remover productos de la cola
    else if (op == "3")
      cout << "Total: $" << setprecision(2) << fixed << total << '\n'; // total de ventas
    else if (op == "4")
      menu.guardar(carrito, archivo, totalArchivo, total); // guardar información en archivo lógico
    else 
      cout << "(!) Opción no válida\n";
  } while(op != "4");
}