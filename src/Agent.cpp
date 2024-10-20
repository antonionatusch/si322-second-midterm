#include "../include/Agent.h"
#include "../include/SmokeSemaphore.h"
#include "../include/Smoker.h"
#include "../include/Global.h"

/**
 * Función que el Agente pone dos ingredientes para empezar
 * @acquire espera hasta que la accion este libre, en este caso el Fumador termine de fumar
 * Se genera un numero aleatorio para elegir que dos ingredientes colocar en la mesa
 * @release permite la siguiente accion, en este caso el Fumador podra actuar
 * @note Cada 5 iteraciones el programa se detendra para preguntar si se desea continuar
 * con las iteraciones para que no se quede en un bucle infinito. El Método a usar será 'AskToContinue'.
 */

void Agent::PutTwoIngredients () {

    const int MAX_ITERATIONS = 5;
    int iteration_count = 0;
    while (true) {
        continue_smoking= true;
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

        iteration_count++;

        if(iteration_count % MAX_ITERATIONS == 0 && !AskToContinue()) {
            std::cout << "\n saliendo del ciclo y volviendo al menú..." << std::endl;
            continue_smoking = false;
            break;
        }
    }
}

/**
 * @brief Solicita al usuario si desea continuar con la acción.
 *
 * Esta función presenta un mensaje al usuario preguntando si desea
 * continuar (opciones 'y' para sí y 'n' para no).
 * Se asegura de que la entrada del usuario sea válida y que no se
 * introduzcan caracteres en blanco o espacios. En caso de una
 * entrada no válida, se le solicita al usuario que intente de nuevo.
 *
 * @return true Si el usuario elige continuar ('y').
 * @return false Si el usuario elige no continuar ('n').
 *
 * @note La función espera hasta que se ingrese una respuesta válida
 * antes de devolver el resultado, y maneja la conversión de caracteres
 * a minúsculas para simplificar la comparación.
 */

bool Agent::AskToContinue() {
    std::string choice;

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\nDesea continuar? (y/n): ";
        std::getline(std::cin, choice);

        if (choice.empty() || choice == " ") {
            std::cerr << "Se introdujo un espacio en blanco o carácter vacío, introduzca una opción.\n";
            continue;
        }

        switch (tolower(choice[0])) {
            case 'y':
                return true;
            case 'n':
                return false;
            default:
                std::cerr << "Entrada no válida. Por favor, ingrese 'y' o 'n'." << std::endl;
        }
    }
}


