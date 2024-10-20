#include <iostream>

#include "../include/Menu.h"
int main() {
    std::string answer;

    while (tolower(answer[0]) != 'e') {
        std::cout << "===== Problemas con semáforos en C++ =====\n";
        std::cout << "Elija una opción:\n";
        std::cout << "1. Problema 10 inciso A\n";
        std::cout << "2. Problema 10 inciso B\n";
        std::cout << "3. Problema 11\n";
        std::cout << "e. Salir\n";

        std::getline(std::cin, answer);

        if (answer.empty() || answer == " ") {
            std::cerr << "Se introdujo un espacio en blanco o carácter vacío, introduzca una opción.\n";
            continue;
        }

        switch (tolower(answer[0])) {
            case '1':
                Menu::Problem10ExerciseA();
                break;
            case '2':
                Menu::Problem10ExerciseB();
                break;
            case '3':
                Menu::Problem11();
                break;
            case 'e':
                std::cout<<"Hasta luego.\n";
                break;
            default:
                std::cerr << "Introdujo una opción no válida, intente de nuevo.\n";
                break;
        }
    }
}