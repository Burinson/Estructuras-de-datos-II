// Práctica #2
// Equipo 2
//  Almazán de la Torre Rubén
//  Dueñas Becerra Mario Alejandro
//  Guzmán Mendoza Jesús Uriel
//  Martínez Yañez Astra Bernardino
//  Torres García Oscar
//  Vázquez Martínez Edgar Isaias
// Sección: D-05
// Calendario: 2020-A


#include "Cliente.cpp"

int main() {
  ofstream archivoCreditoSalida;  // el contructor abre el archivo

  archivoCreditoSalida.open("credito.dat", ios::binary); // abrir el archivo

  // cerrar el archivo si no existe
  if (!archivoCreditoSalida) {
    cerr << "No se pudo abrir el archivo " << endl;
    exit(1);
  }  // fin de if

  Cliente clienteEnBlanco;

  string valorApellido, valorPrimerNombre;
  int valorNumeroCuenta;
  bool romper = false;
  double valorSaldo;

  while (!romper) {
    cout << "Escriba el numero de cuenta (De 1 a 100, 0 para terminar la "
            "entrada)\n?";
    cin >> valorNumeroCuenta;

    if (valorNumeroCuenta < 0 || valorNumeroCuenta > 100) {
      cout << "Opción no existe\n";
      continue;
    }  // revisar valores no válidos

    if (valorNumeroCuenta == 0) romper = true;  // terminar registros si se ingresa 0

    if (!romper) {
      clienteEnBlanco.establecerNumeroCuenta(valorNumeroCuenta);

      cout << "Teclea apellido, primer nombre, saldo\n?";
      cin >> valorApellido >> valorPrimerNombre >> valorSaldo;

      clienteEnBlanco.establecerApellido(valorApellido);
      clienteEnBlanco.establecerPrimerNombre(valorPrimerNombre);
      clienteEnBlanco.establecerSaldo(valorSaldo);

      // buscar la posicion en el archivo del registro especificado por el usuario
      archivoCreditoSalida.seekp((clienteEnBlanco.obtenerNumeroCuenta() - 1) *
                                sizeof(Cliente));  // seekp(n,ios::beg);

      // escribir la informacion especificada por el usuario en el archivo
      archivoCreditoSalida.write(reinterpret_cast<const char *>(&clienteEnBlanco),
                                sizeof(Cliente));

      cout << "La dirección es: "
          << int(archivoCreditoSalida.tellp()) - int(sizeof(Cliente)) << '\n';
      cout << "Tamaño del objeto es: " << sizeof(clienteEnBlanco) << '\n';
    }

  }  // fin de while

  archivoCreditoSalida.close(); // cerrar el archivo

  return 0; 
}// fin del main