#include "iostream"
#include "mutex"
#include "../include/Mounter.h"
#include "../include/BicycleSemaphore.h"

extern std::mutex print_mutex;

void Mounter::MakeBicycle() {
    wheel_semaphore.acquire();
    wheel_semaphore.acquire();
    frame_semaphore.acquire();
    handlebar_semaphore.acquire();

    {
        std::lock_guard<std::mutex> lock(print_mutex);
        std::cout<<"Montador: Todas las piezas listas, bicicleta ensamblada.\n";
    }
}