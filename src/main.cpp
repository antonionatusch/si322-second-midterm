#include <iostream>
#include <thread>
#include <semaphore>
#include "../include/HelloWorld.h"

std::binary_semaphore smoker_with_tobacco(0);  // Fumador con tabaco espera papel y fósforos
std::binary_semaphore smoker_with_paper(0);    // Fumador con papel espera tabaco y fósforos
std::binary_semaphore smoker_with_matches(0);  // Fumador con fósforos espera tabaco y papel

// Semáforo para el agente (inicializado en 1 para que el agente comience primero)
std::binary_semaphore agent_ready(1);

// Función del agente que coloca los ingredientes en la mesa
void agent() {
    while (true) {
        agent_ready.acquire();  // Espera a que el fumador termine de fumar

        // Elegir aleatoriamente qué dos ingredientes colocar en la mesa
        int choice = rand() % 3;

        if (choice == 0) {
            std::cout << "\nAgente coloca papel y fosforos en la mesa." << std::endl;
            smoker_with_tobacco.release();  // Fumador con tabaco puede actuar
        } else if (choice == 1) {
            std::cout << "\nAgente coloca tabaco y fosforos en la mesa." << std::endl;
            smoker_with_paper.release();  // Fumador con papel puede actuar
        } else {
            std::cout << "\nAgente coloca tabaco y papel en la mesa." << std::endl;
            smoker_with_matches.release();  // Fumador con fósforos puede actuar
        }
    }
}

// Función para el fumador con tabaco
void smoker_tobacco() {
    while (true) {
        smoker_with_tobacco.acquire();  // Espera papel y fósforos
        std::cout << "Fumador con tabaco arma y fuma el cigarrillo." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));  // Simula el tiempo para fumar
        agent_ready.release();  // Notifica al agente que ha terminado
    }
}

// Función para el fumador con papel
void smoker_paper() {
    while (true) {
        smoker_with_paper.acquire();  // Espera tabaco y fósforos
        std::cout << "Fumador con papel arma y fuma el cigarrillo." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));  // Simula el tiempo para fumar
        agent_ready.release();  // Notifica al agente que ha terminado
    }
}

// Función para el fumador con fósforos
void smoker_matches() {
    while (true) {
        smoker_with_matches.acquire();  // Espera tabaco y papel
        std::cout << "Fumador con fosforos arma y fuma el cigarrillo." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));  // Simula el tiempo para fumar
        agent_ready.release();  // Notifica al agente que ha terminado
    }
}

int main() {
    auto hw = new HelloWorld();
    std::cout<<"The sum of 2 and 3 is: "<<hw->Sum(2,3)<<"\n";

    std::thread agent_thread(agent);
    std::thread tobacco_thread(smoker_tobacco);
    std::thread paper_thread(smoker_paper);
    std::thread matches_thread(smoker_matches);

    // Esperar a que los hilos terminen (en este caso no lo harán porque el ciclo es infinito)
    agent_thread.join();
    tobacco_thread.join();
    paper_thread.join();
    matches_thread.join();

    return 0;
}
