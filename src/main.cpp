#include <iostream>
#include <thread>
#include <semaphore>
#include "../include/Agent.h"
#include "../include/Smoker.h"
#include "../include/SmokeSemaphore.h"

int main() {
    Agent ag;
    Smoker smk1, smk2, smk3;

    std::thread agent_thread(&Agent::PutTwoIngredients, &ag);
    std::thread tobacco_thread(&Smoker::PutTobacco, &smk1);
    std::thread paper_thread(&Smoker::PutPaper, &smk2);
    std::thread matches_thread(&Smoker::PutMatches, &smk3);

    agent_thread.join();
    tobacco_thread.join();
    paper_thread.join();
    matches_thread.join();

    return 0;
}
