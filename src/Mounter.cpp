#include "iostream"
#include "mutex"
#include "../include/Mounter.h"
#include "../include/BicycleSemaphore.h"

extern std::mutex print_mutex;
/**
 * @descripción Función que ensambla toda la bicicleta.
 *
 * Lo que hace es adquirir el hilo principal de cada uno de los elementos
 * de la bicicleta, el cual por propósitos del ejercicio significa que
 * "recogió" ese componente de la bicicleta.
 *  Hará esto para cada hilo correspondiente a cada parte de la bicicleta.
 */
void Mounter::MakeBicycle() {
    wheel_semaphore.acquire();
    {
        std::lock_guard<std::mutex> lock(print_mutex);
        std::cout<<"Montador: Primera rueda recolectada.\n";
    }
    wheel_semaphore.acquire();
    {
        std::lock_guard<std::mutex> lock(print_mutex);
        std::cout<<"Montador: Segunda rueda recolectada.\n";
    }
    frame_semaphore.acquire();
    {
        std::lock_guard<std::mutex> lock(print_mutex);
        std::cout<<"Montador: Cuadro recolectado.\n";
    }
    handlebar_semaphore.acquire();
    {
        std::lock_guard<std::mutex> lock(print_mutex);
        std::cout<<"Montador: Manillar recolectado.\n";
    }

    {
        std::lock_guard<std::mutex> lock(print_mutex);
        std::cout<<"Montador: Todas las piezas listas, bicicleta ensamblada.\n";
    }
}