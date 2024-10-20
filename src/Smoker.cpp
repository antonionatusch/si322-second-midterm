#include "../include/Smoker.h"
#include "../include/SmokeSemaphore.h"

/**
 * Función que el Fumador pone tabaco para completar al Agente
 * @acquire espera hasta que la accion este libre, en este caso el Fumador espera que el Agente coloque papel y fosforo
 * @sleep_for simula el tiempo para fumar
 * @release permite la siguiente accion, en este caso el Agente termino de preparar el cigarrillo
 */

void Smoker::PutTobacco() {
    while (true) {
        smoker_with_tobacco.acquire();
        std::cout << "Fumador con tabaco arma y fuma el cigarrillo." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        agent_ready.release();
    }
}

/**
 * Función que el Fumador pone papel para completar al Agente
 * @acquire espera hasta que la accion este libre, en este caso el Fumador espera que el Agente coloque tabaco y fosforo
 * @sleep_for simula el tiempo para fumar
 * @release permite la siguiente accion, en este caso el Agente termino de preparar el cigarrillo
 */

void Smoker::PutPaper() {
    while (true) {
        smoker_with_paper.acquire();
        std::cout << "Fumador con papel arma y fuma el cigarrillo." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        agent_ready.release();
    }
}

/**
 * Función que el Fumador pone fosforo para completar al Agente
 * @acquire espera hasta que la accion este libre, en este caso el Fumador espera que el Agente coloque tabaco y papel
 * @sleep_for simula el tiempo para fumar
 * @release permite la siguiente accion, en este caso el Agente termino de preparar el cigarrillo
 */

void Smoker::PutMatches() {
    while (true) {
        smoker_with_matches.acquire();
        std::cout << "Fumador con fosforos arma y fuma el cigarrillo." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        agent_ready.release();
    }
}