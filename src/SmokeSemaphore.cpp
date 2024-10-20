#include "../include/SmokeSemaphore.h"

std::binary_semaphore smoker_with_tobacco(0);
std::binary_semaphore smoker_with_paper(0);
std::binary_semaphore smoker_with_matches(0);

std::binary_semaphore agent_ready(1);