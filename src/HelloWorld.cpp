#include "../include/HelloWorld.h"
HelloWorld::HelloWorld() {
   std::cout<<"Hello World!\n";
}

/**
 * Función que suma
 * @param a, primer entero a sumar
 * @param b, segundo entero a sumar
 * @return la suma de los dos números enteros a + b
 */
int HelloWorld::Sum(int a, int b) {
    return a + b;
}
