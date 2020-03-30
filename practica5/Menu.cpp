#include "Menu.h"
#include <sstream>
using namespace std;


// mostrar menú
string Menu::mostrarMenu(fstream &archivoAgendaES) {
  archivoAgendaES.clear(); // Restaura el estado del flujo a “bueno”
  archivoAgendaES.seekg(0, ios::beg); // reposicionar puntero al principio del archivo

  string op;

  cout << "Menú - Agenda de Contactos\n"
    << "1. Alta de contacto\n"
    << "2. Consulta individual (utilizar llave canónica)\n"
    << "3. Consultas generales\n"
    << "4. Salir\n"
    << "Elige tu opción: ";
  getline(cin, op);
  cout << '\n';
  return op;
}

// revisar si ya existe el usuario
bool Menu::existeLlave(fstream archivoAgenaES, string valorPrimerNombre, string valorPrimerApellido) {
  Contacto c;
  archivoAgenaES.seekg(0);
  
  while(leerContacto(archivoAgenaES, c))
    if (llaveCorresponde(valorPrimerNombre, valorPrimerApellido, c))
      return true;

  return false;
}

// mensajes de información
void Menu::mensaje(string texto) {
  cout << "\n(!) " << texto << "\n\n";
}

// dar de alta contacto
void Menu::darAltaContacto(fstream &archivoAgendaES) {
  string valorSaldo, valorPrimerNombre, valorApellido, valorDireccion, valorCiudad, valorEstado, valorCodigoPostal;
  Contacto c;

  cout << "Primer nombre: ";
  getline(cin, valorPrimerNombre);

  cout << "Apellido: ";
  getline(cin, valorApellido);

  if (existeLlave(fstream("contactos.txt", ios::in), valorPrimerNombre, valorApellido)) {
    mensaje("Esta llave ya existe");
    return;
  }

  cout << "Dirección: ";
  getline(cin, valorDireccion);

  cout << "Ciudad: ";
  getline(cin, valorCiudad);

  cout << "Estado: ";
  getline(cin, valorEstado);

  cout << "Código postal: ";
  getline(cin, valorCodigoPostal);

  cout << "Saldo: ";
  getline(cin, valorSaldo);

  c = Contacto(valorPrimerNombre, valorApellido, valorDireccion, valorCiudad, valorEstado, valorCodigoPostal, stod(valorSaldo));

  guardarContacto(archivoAgendaES, c);
}

// guardar contacto
void Menu::guardarContacto(fstream &archivoAgendaES, Contacto c) {
  int len;
  string campo;

  // escribir cada atributo separado por un delimitador
  campo += 
  c.obtenerPrimerNombre() + '|' +
  c.obtenerApellido() + '|' +
  c.obtenerDireccion() + '|' +
  c.obtenerCiudad() + '|' +
  c.obtenerEstado() + '|' +
  c.obtenerCodigoPostal() + '|' +
  to_string(c.obtenerSaldo()) + '|';

  len = campo.size();

  archivoAgendaES.write(reinterpret_cast<char *>(&len), sizeof(int));
  archivoAgendaES.write(campo.c_str(), len);
}

bool Menu::leerContacto(fstream &archivoAgendaES, Contacto &c) {
  // revisa si se puede seguir leyendo
  if (archivoAgendaES.peek() == -1) 
    return false;

  string valorSaldo, valorPrimerNombre, valorApellido, valorDireccion, valorCiudad, valorEstado, valorCodigoPostal;
  int len;
  string campo, temp;
  
  // leer registro
  archivoAgendaES.read(reinterpret_cast<char *>(&len), sizeof(int));
  char *buffer = new char[len];
  archivoAgendaES.read(buffer, len);
  campo = buffer;
  delete [] buffer;

  stringstream ss(campo);

  // leer atributos
  getline(ss, valorPrimerNombre, '|'); 
  getline(ss, valorApellido, '|'); 
  getline(ss, valorDireccion, '|'); 
  getline(ss, valorCiudad, '|'); 
  getline(ss, valorEstado, '|'); 
  getline(ss, valorCodigoPostal, '|'); 
  getline(ss, valorSaldo, '|'); 

  // asignar atributos a contacto
  c = Contacto(valorPrimerNombre, valorApellido, valorDireccion, valorCiudad, valorEstado, valorCodigoPostal, stod(valorSaldo));

  return !archivoAgendaES.eof();
}

// transformar todas las letras a minúscula
void Menu::estandarizar(string &llave) {
  for (auto &letra : llave)
    letra = tolower(letra);
}


// verificar que la llave corresponda al contacto
bool Menu::llaveCorresponde(string valorPrimerNombre, string valorApellido, Contacto c) {
  string primerNombre = c.obtenerPrimerNombre();
  string apellido = c.obtenerApellido();

  estandarizar(valorPrimerNombre);
  estandarizar(valorApellido);
  estandarizar(primerNombre);
  estandarizar(apellido);
  return valorPrimerNombre == primerNombre and valorApellido == apellido;
}

// consulta individual
void Menu::consultaIndividual(fstream &archivoAgendaES) {
  string valorPrimerNombre, valorApellido;
  Contacto c;
  bool encontrado = false;

  cout << "Primer nombre: ";
  getline(cin, valorPrimerNombre);

  cout << "Apellido: ";
  getline(cin, valorApellido);

  while (leerContacto(archivoAgendaES, c)) {
    if (llaveCorresponde(valorPrimerNombre, valorApellido, c)) {
      cout << '\n';
      c.imprimirCabecera();
      c.imprimirContacto();
      cout << '\n';
      encontrado = true;
    }  
  }  
  if (!encontrado) 
    mensaje("No existe este contacto");
}

// consulta general
void Menu::consultaGeneral(fstream &archivoAgendaES) {
  Contacto c;

  c.imprimirCabecera();

  while (leerContacto(archivoAgendaES, c)) 
    c.imprimirContacto();

  cout << '\n';
}