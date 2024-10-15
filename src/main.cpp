#include <iostream>
#include "../include/HelloWorld.h"

int main() {
    auto hw = new HelloWorld();
    std::cout<<"The sum of 2 and 3 is: "<<hw->Sum(2,3)<<"\n";
    return 0;
}
