#include "Menu.h"

int main() {
  Menu menu;
  string op;

  double total = 0.0;

  Cola<Producto> carrito;
  fstream archivo("productos.dat", ios::in | ios::out | ios::app);
  menu.cargar(carrito, archivo, total);
  do {
    menu.mostrar(op);
    if (op == "1")
      menu.comprar(carrito, total);
    else if (op == "2") 
      menu.vender(carrito, total);
    else if (op == "3")
      cout << "Total: $" << setprecision(2) << fixed << total << '\n';
    else if (op == "4")
      menu.guardar(carrito, archivo);
  } while(op != "4");
}