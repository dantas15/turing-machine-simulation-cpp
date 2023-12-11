#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "readDescription.hpp"
#include "types.hpp"

const char RIGHT_DIRECTION = 'D';
const char LEFT_DIRECTION = 'E';
const char STAYS_DIRECTION = 'S';

int main() {
    try {
        TuringMachine tm;
        std::string word;
        std::string outputFileName;

        readTuringMachineDescription(tm);

        // ignore space between fileName and word
        std::cin.ignore();

        std::getline(std::cin, word);

        size_t lastSpaceIndex = word.rfind(' ');

        // Check if a space was found
        if (lastSpaceIndex == std::string::npos) {
            throw std::runtime_error("Word cannot be empty (use spaces for λ).");
        }

        // Split the string into two parts
        outputFileName = word.substr(lastSpaceIndex + 1);
        word = word.substr(0, word.rfind(' '));

        // allow word to be λ
        if (word.empty()) {
            word = " ";
        }

        std::ofstream outputFile(outputFileName);

        outputFile << word;

        // std::cout << "\n\"" << word << "\"\n";
        // std::cout << "\n\"" << outputFileName << "\"\n";

        // indice
        // estado atual
        
        outputFile.close();
    } catch (std::exception &e) {
        std::cout << std::endl
                  << e.what() << std::endl;
    }
    return 0;
}
