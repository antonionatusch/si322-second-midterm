#include <iostream>
#include "../include/Agent.h"
#include "../include/SmokeSemaphore.h"

/**
 * Función que el Agente pone dos ingredientes para empezar
 * @acquire espera hasta que la accion este libre, en este caso el Fumador termine de fumar
 * Se genera un numero aleatorio para elegir que dos ingredientes colocar en la mesa
 * @release permite la siguiente accion, en este caso el Fumador podra actuar
 */

void Agent::PutTwoIngredients () {
    while (true) {
        agent_ready.acquire();  // Espera a que el fumador termine de fumar

        int choice = rand() % 3;

        if (choice == 0) {
            std::cout << "\nAgente coloca papel y fosforos en la mesa." << std::endl;
            smoker_with_tobacco.release();
        } else if (choice == 1) {
            std::cout << "\nAgente coloca tabaco y fosforos en la mesa." << std::endl;
            smoker_with_paper.release();
        } else {
            std::cout << "\nAgente coloca tabaco y papel en la mesa." << std::endl;
            smoker_with_matches.release();
        }
    }
}