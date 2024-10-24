#include "../include/Menu.h"
#include "../include/Worker.h"
#include "../include/Mounter.h"
#include "../include/BicycleSemaphore.h"
#include "../include/Agent.h"
#include "../include/Smoker.h"
#include "../include/SmokeSemaphore.h"
#include <thread>

#include "../include/Global.h"
// Inicialización de los semáforos globales

std::mutex print_mutex;
/**
 * Funcion del Menú correspondiente al inciso A del problema 10.
 * En este caso, el operario 1 solo puede fabricar y guardar una rueda a la vez , entonces
 * se utiliza el método MakeBicycle el cual se encarga de "recoger la rueda" una vez se termine de fabricar.
 */
void Menu::Problem10ExerciseA() {

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
/**
 * Funcion del Menú correspondiente al inciso B del problema 10.
 * En este caso, el operario 1 puede fabricar y guardar las 2 ruedas, entonces
 * se utiliza el método MakeBicycleTwoWheels el cual se encarga de recoger ambas una vez se termine de fabricar.
 */
void Menu::Problem10ExerciseB() {

    Worker wk1, wk2, wk3;
    Mounter mounter;

    // Crear hilos para cada operario y el mounter
    std::thread t1(&Worker::MakeWheel, &wk1);
    std::thread t2(&Worker::MakeWheel, &wk1);  // Segunda rueda
    std::thread t3(&Worker::MakeFrame, &wk2);
    std::thread t4(&Worker::MakeHandlebar, &wk3);
    std::thread t5(&Mounter::MakeBicycleTwoWheels, &mounter);

    // Esperar a que todos los hilos terminen
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
}

/**
 * Función del Menú correspondiente al problema 11.
 * El agente coloca dos ingredientes sobre la mesa, permitiendo que el
 * fumador con el ingrediente restante arme y fume un cigarrillo.
 * Se utiliza el método PutTwoIngredients como método de entrada en el cual el 'Agente' coloca los primeros 2 ingredientes del cigarro.
 * Al finalizar el proceso, es necesario desvincular (detach) los hilos de los 3 diferentes procesos de los fumadores
 * si no se desea continuar, para evitar que sigan ejecutándose innecesariamente.
 * Si se desea continuar, se espera (join) a que cada hilo de fumador termine su ejecución.
 */


void Menu::Problem11() {
    Agent ag;
    Smoker smk1, smk2, smk3;

    std::thread agent_thread(&Agent::PutTwoIngredients, &ag);
    std::thread tobacco_thread(&Smoker::PutTobacco, &smk1);
    std::thread paper_thread(&Smoker::PutPaper, &smk2);
    std::thread matches_thread(&Smoker::PutMatches, &smk3);

    agent_thread.join();
    if(!continue_smoking) {
        tobacco_thread.detach();
        paper_thread.detach();
        matches_thread.detach();
    }
    else {
        tobacco_thread.join();
        paper_thread.join();
        matches_thread.join();
    }
}