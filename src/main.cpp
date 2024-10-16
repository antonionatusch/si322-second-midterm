#include <iostream>
#include <thread>
#include <mutex>
#include "../include/Worker.h"
#include "../include/Mounter.h"
#include "../include/BicycleSemaphore.h"

// Inicialización de los semáforos globales

std::mutex print_mutex;

int main() {
    Worker op1, op2, op3;
    Mounter montador;

    // Crear hilos para cada operario y el montador
    std::thread t1(&Worker::MakeWheel, &op1);
    std::thread t2(&Worker::MakeWheel, &op1);  // Segunda rueda
    std::thread t3(&Worker::MakeFrame, &op2);
    std::thread t4(&Worker::MakeHandlebar, &op3);
    std::thread t5(&Mounter::MakeBicycle, &montador);

    // Esperar a que todos los hilos terminen
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
}