#include <exception>
#include <iostream>
#include <sstream>
#include <vector>

#include "readDescription.hpp"
#include "types.hpp"

int main() {
    try {
        TuringMachine tm;

        readTuringMachineDescription(tm);

        std::cout << "\nit works!\n";
    } catch (std::exception &e) {
        std::cout << std::endl
                  << e.what() << std::endl;
    }
    return 0;
}
