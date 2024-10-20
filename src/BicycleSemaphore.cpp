#include "../include/BicycleSemaphore.h"

std::binary_semaphore wheel_semaphore(0);
std::binary_semaphore frame_semaphore(0);
std::binary_semaphore handlebar_semaphore(0);
