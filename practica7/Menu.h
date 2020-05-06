#include "Producto.h"
#include <iomanip>
#include <fstream>

class Menu {
  public:
    void mostrar(string &op) {
      cout << '\n';
      cout << "Menú - Gestión de productos\n";
      cout << "1. Compra de un producto - (insertar)\n";
      cout << "2. Venta de un producto - (eliminar)\n";
      cout << "3. Total de lo vendido\n";
      cout << "4. Salir\n";
      cout << "Elige tu opción: ";
      cin >> op;
      cout << '\n';
      cin.ignore();
    }

    void comprar(Cola<Producto> &carrito, double &total) {
      if (carrito.lleno()) {
        cout << "(!) El carrito está lleno\n";
        return;
      }

      Producto p;
      p.leer();
      carrito.insertar(p);

      cout << "\nEl producto fue comprado exitosamente\n";

      total += p.obtenerPrecio();
    }

    void vender(Cola<Producto> &carrito, double &total) {
      if (carrito.vacio()) {
        cout << "(!) El carrito está vacío\n";
        return;
      }

      cout << "\nEl producto fue vendido exitosamente\n";

      total -= carrito.frente().obtenerPrecio();
      carrito.eliminar();
    }

    void leer(fstream &archivo, string &attr) {
      int len;
      archivo.read(reinterpret_cast<char *>(&len), sizeof(int));
      char *buffer = new char[len];
      archivo.read(buffer, len);
      attr = buffer;
      delete [] buffer;
    }

    void escribir(fstream &archivo, string attr) {
      int len = attr.size();
      archivo.write(reinterpret_cast<char *>(&len), sizeof(int));
      archivo.write(attr.c_str(), len);
    }

    void cargar(Cola<Producto> &carrito, fstream &archivo, double &total) {
      string clave, nombre, precio;

      while (!archivo.eof()) {
        if (archivo.peek() == -1)
          break;
        
        leer(archivo, clave);
        leer(archivo, nombre);
        leer(archivo, precio);

        total += stod(precio);

        what(precio);

        carrito.insertar(Producto(clave, nombre, precio));
      }

      archivo.close();
    }

    void guardar(Cola<Producto> &carrito, fstream &archivo) {
      archivo.open("productos.dat", ios::out | ios::trunc);
      archivo.clear();
      archivo.seekg(0, ios::beg);

      while (!carrito.vacio()) {
        Producto p = carrito.frente();
        carrito.eliminar();

        escribir(archivo, to_string(p.obtenerClave()));
        escribir(archivo, p.obtenerNombre());
        escribir(archivo, to_string(p.obtenerPrecio()));
      }
      archivo.close();
    }
};