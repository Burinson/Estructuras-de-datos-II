#include <iostream>
#include <array>
using namespace std;

const int MAX = 5;
const int N = 1000;

template<class T>
class Cola {
  array<T, N> a;
  int izq, der;

  public:
      Cola<T>() {
        izq = der = 0; // inicialmente están en 0
      }

      bool vacio() {
        return izq == der; // existen 0 elementos
      }

      bool lleno() {
        return der - izq == MAX; // existen máximo número de elementos
      }

      void insertar(T v) {
        if (!lleno())
          a[++der] = v; // incrementa puntero de la derecha y se asigna elemento
      }

      void eliminar() {
        if (!vacio())
          ++izq; // incrementa el puntero de la izquierda
      }

      T frente() {
        if (!vacio())
          return a[izq + 1]; // el elemento próximo a procesar está en el puntero de la izquierda
      }
      

};

