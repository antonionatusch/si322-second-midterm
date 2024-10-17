#include "../include/Menu.h"
#include "../include/Worker.h"
#include "../include/Mounter.h"
#include "../include/BicycleSemaphore.h"
#include <thread>
// Inicialización de los semáforos globales

std::mutex print_mutex;
void Menu::Problema10IncisoA() {

    Worker wk1, wk2, wk3;
    Mounter mounter;

    // Crear hilos para cada operario y el mounter
    std::thread t1(&Worker::MakeWheel, &wk1);
    std::thread t2(&Worker::MakeWheel, &wk1);  // Segunda rueda
    std::thread t3(&Worker::MakeFrame, &wk2);
    std::thread t4(&Worker::MakeHandlebar, &wk3);
    std::thread t5(&Mounter::MakeBicycle, &mounter);

    // Esperar a que todos los hilos terminen
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
}
