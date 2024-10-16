#include "../include/Worker.h"
#include "../include/BicycleSemaphore.h"
#include "iostream"
#include "thread"
#include "chrono"
#include "mutex"

extern std::mutex print_mutex; // Bloqueo de exclusión mutua para proteger los prints

Worker::Worker() {

}
Worker::~Worker() {

}

/**
 * Función encargada de elaborar una rueda.
 * @lock_guard El lock guard se encarga de permitir la ejecución del print sin que intervengan otros hilos.
 * Una vez hecho esto, el semáforo correspondiente al hilo de la creación de ruedas se libera.
 *
 */


void Worker::MakeWheel() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lock(print_mutex);
        std::cout<<"OP 1: Rueda montada.\n";
    }
    wheel_semaphore.release();
}
/**
 * Función encargada de elaborar una rueda.
 * @lock_guard El lock guard se encarga de permitir la ejecución del print sin que intervengan otros hilos.
 * Una vez hecho esto, el semáforo correspondiente al hilo de la creación de cuadro se libera.
 *
 */
void Worker::MakeFrame() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lock(print_mutex);
        std::cout<<"OP 2: Cuadro montado.\n";
    }
    frame_semaphore.release();
}
/**
 * Función encargada de elaborar una rueda.
 * @lock_guard El lock guard se encarga de permitir la ejecución del print sin que intervengan otros hilos.
 * Una vez hecho esto, el semáforo correspondiente al hilo de la creación de manillar se libera.
 *
 */
void Worker::MakeHandlebar() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lock(print_mutex);
        std::cout<<"OP 3: Manillar montado.\n";
    }
    handlebar_semaphore.release();
}
