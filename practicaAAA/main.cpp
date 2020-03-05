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
  ofstream archivoCreditoSalida("credito.txt",
                                ios::binary);  // el contructor abre el archivo

  // cerrar el archivo si no existe
  if (!archivoCreditoSalida) {
    cerr << "No se pudo abrir el archivo " << endl;
    exit(1);
  } // fin de if

  Cliente clienteEnBlanco;

  for (int i = 0; i < 100; ++i)
    archivoCreditoSalida.write(reinterpret_cast<const char *>(&clienteEnBlanco),
                               sizeof(Cliente));

  return 0;  // el destructor cierra el archivo
}