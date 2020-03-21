#include "Menu.h"
using namespace std;


// mostrar menú
char Menu::mostrarMenu(fstream &archivoAgendaES) {
  archivoAgendaES.clear(); // Restaura el estado del flujo a “bueno”
  archivoAgendaES.seekg(0, ios::beg); // reposicionar puntero al principio del archivo

  int op;

  cout << "Menú - Agenda de Contactos\n"
    << "1. Alta de contacto\n"
    << "2. Consulta individual (utilizar llave canónica)\n"
    << "3. Consultas generales\n"
    << "4. Salir\n"
    << "Elige tu opción: ";
  cin >> op;
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

// dar de alta contacto
void Menu::darAltaContacto(fstream &archivoAgendaES) {
  string valorPrimerNombre, valorApellido, valorDireccion, valorCiudad, valorEstado, valorCodigoPostal;
  double valorSaldo;
  Contacto c;

  cout << "Primer nombre: ";
  cin >> valorPrimerNombre;

  cout << "Apellido: ";
  cin >> valorApellido;

  if (existeLlave(fstream("contactos.txt", ios::in), valorPrimerNombre, valorApellido)) {
    cout << "Esta llave ya existe\n";
    return;
  }

  cout << "Dirección: ";
  cin >> valorDireccion;

  cout << "Ciudad: ";
  cin >> valorCiudad;

  cout << "Estado: ";
  cin >> valorEstado;

  cout << "Código postal: ";
  cin >> valorCodigoPostal;

  cout << "Saldo: ";
  cin >> valorSaldo;

  c = Contacto(valorPrimerNombre, valorApellido, valorDireccion, valorCiudad, valorEstado, valorCodigoPostal, valorSaldo);

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

  string valorPrimerNombre, valorApellido, valorDireccion, valorCiudad, valorEstado, valorCodigoPostal;
  double valorSaldo;
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
  getline(ss, temp, '|'); 
  valorSaldo = stod(temp);

  // asignar atributos a contacto
  c = Contacto(valorPrimerNombre, valorApellido, valorDireccion, valorCiudad, valorEstado, valorCodigoPostal, valorSaldo);

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
  cin >> valorPrimerNombre;

  cout << "Apellido: ";
  cin >> valorApellido;

  while (!archivoAgendaES.eof()) {
    leerContacto(archivoAgendaES, c);

    if (archivoAgendaES.eof())
      break;

    if (llaveCorresponde(valorPrimerNombre, valorApellido, c)) {
      cout << '\n';
      c.imprimirCabecera();
      c.imprimirContacto();
      cout << '\n';
      encontrado = true;
    }  
  }  
  if (!encontrado) 
    cout << "No existe este contacto\n";
}

// consulta general
void Menu::consultaGeneral(fstream &archivoAgendaES) {
  Contacto c;

  c.imprimirCabecera();

  while (leerContacto(archivoAgendaES, c)) 
    c.imprimirContacto();

  cout << '\n';
}