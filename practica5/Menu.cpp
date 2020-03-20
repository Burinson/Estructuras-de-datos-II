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
  
  while(!archivoAgenaES.eof()) {
    if (archivoAgenaES.eof())
      break;
    
    archivoAgenaES.read(reinterpret_cast<char *>(&c), sizeof(Contacto));
    if (llaveCorresponde(valorPrimerNombre, valorPrimerApellido, c))
      return true;
  }

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


  archivoAgendaES.write(reinterpret_cast<const char *>(&c), sizeof(Contacto)); // escribir cuenta
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
    archivoAgendaES.read(reinterpret_cast<char *>(&c), sizeof(Contacto));

    if (archivoAgendaES.eof())
      break;

    if (llaveCorresponde(valorPrimerNombre, valorApellido, c)) {
      c.imprimirCabecera();
      c.imprimirContacto();
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

  while (!archivoAgendaES.eof()) {
    archivoAgendaES.read(reinterpret_cast<char *>(&c), sizeof(Contacto));

    if (archivoAgendaES.eof())
      break;

    c.imprimirContacto();
  }
}