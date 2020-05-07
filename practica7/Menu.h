#include "Producto.h"
#include <iomanip>
#include <fstream>

class Menu {
  public:
    void mostrar(string &op) { // menú principal
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

    void comprar(Cola<Producto> &carrito, double &total) { // insertar objetos a la cola
      if (carrito.lleno()) { // si está lleno, no se pueden insertar más objetos
        cout << "(!) El carrito está lleno\n";
        return;
      }

      Producto p;
      p.leer(); // leer información sobre producto
      carrito.insertar(p);

      cout << "\nEl producto fue comprado exitosamente\n";
    }

    void vender(Cola<Producto> &carrito, double &total) {
      if (carrito.vacio()) { // si está vacío, no se pueden eliminar productos
        cout << "(!) El carrito está vacío\n";
        return;
      }

      cout << "\nEl producto fue vendido exitosamente\n";

      total += carrito.frente().obtenerPrecio(); // acumular ventas
      carrito.eliminar(); // eliminar el producto más proóximo en la cola
    }

    void leer(fstream &archivo, string &attr) { // leer un atributo del archivo físico
      int len;
      archivo.read(reinterpret_cast<char *>(&len), sizeof(int));
      char *buffer = new char[len];
      archivo.read(buffer, len);
      attr = buffer;
      delete [] buffer;
    }

    void escribir(fstream &archivo, string attr) { // escribir un atributo al archivo físico
      int len = attr.size();
      
      archivo.write(reinterpret_cast<char *>(&len), sizeof(int));
      archivo.write(attr.c_str(), len);
    }

    void cargar(Cola<Producto> &carrito, fstream &archivo, fstream &totalArchivo, double &total) { // cargar información a la cola y total de ventas
      string clave, nombre, precio, valorTotal;

      while (!archivo.eof()) { // mientras el archivo no haya finalizado 
        if (archivo.peek() == -1)
          break;
        
        leer(archivo, clave);
        leer(archivo, nombre);
        leer(archivo, precio); // leer atributos

        carrito.insertar(Producto(clave, nombre, precio)); // llenar la cola con la información
      }
      archivo.close(); // cerrar el archivo

      cout << totalArchivo.peek() << '\n';
      if (totalArchivo.peek() != -1) {
        leer(totalArchivo, valorTotal);
        total = stod(valorTotal); // recuperar total
      }

      totalArchivo.close(); // cerrrar el archivo
    }

    void guardar(Cola<Producto> &carrito, fstream &archivo, fstream &totalArchivo, double total) { // guardar la información de la cola al archivo físico
      archivo.open("productos.dat", ios::out | ios::trunc); // para no tener que vaciar el archivo manualmente
      archivo.clear(); // restablecer flujo a "bueno"
      archivo.seekg(0, ios::beg); // reposiciona el puntero al principio del archivo

      totalArchivo.open("total.dat", ios::out | ios::trunc);
      totalArchivo.clear();
      totalArchivo.seekg(0, ios::beg);

      while (!carrito.vacio()) { // mientras no esté vacío el carrito
        Producto p = carrito.frente(); // el producto más próximo es el que sigue en la cola
        carrito.eliminar(); // se elimina el producto más próximo

        escribir(archivo, to_string(p.obtenerClave()));
        escribir(archivo, p.obtenerNombre());
        escribir(archivo, to_string(p.obtenerPrecio())); // se escriben todos los atributos al archivo físico
      }
      archivo.close(); // cerrar el archivo

      escribir(totalArchivo, to_string(total));
      totalArchivo.close(); // cerrar el archivo
    }
};