#include "iostream"
#include "mutex"
#include "../include/Mounter.h"
#include "../include/BicycleSemaphore.h"

extern std::mutex print_mutex;
/**
 *
 * @descripción Función que recolecta las ruedas.
 * Libera los 2 hilos correspondientes a las ruedas y luego permite el flujo normal del programa.
 *
 */


void Mounter::CollectWheels() {
        wheel_semaphore.acquire();
        wheel_semaphore.acquire();
        {
            std::lock_guard<std::mutex> lock(print_mutex);
            std::cout << "Montador: Ambas ruedas recolectadas.\n";
        }
}

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

/**
 *
 * @descripción Función que ensambla la bicicleta. En este caso,
 * se espera a que las 2 ruedas estén listas (haciendo uso de la función CollectWheels) para recién
 * recogerlas y continuar con el flujo normal del armado de la bicicleta.
 */


void Mounter::MakeBicycleTwoWheels() {
    CollectWheels();

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
