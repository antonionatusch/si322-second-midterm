#include <atomic>

#ifndef GLOBAL_H
#define GLOBAL_H

/**
 * Variable atómica 'continue_smoking' que controla el flujo
 * del proceso de fumar, asegurando acceso seguro en entornos
 * multihilo mediante la biblioteca <atomic>.
 */

extern std::atomic<bool> continue_smoking;

#endif //GLOBAL_H
