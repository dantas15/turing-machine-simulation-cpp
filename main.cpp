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

        // indice
        // estado atual

        // Creating the tape
        word = 'B' + word + 'B';

        size_t tapeIndex = 0;
        std::string currState = tm.initialState;

        size_t i = 0;

        char oi = '1';
        while (true) {
            for (size_t i = 0; i < word.size(); i++) {
                if ((size_t)tapeIndex == i) {
                    std::cout << "{" << currState << "}";
                    outputFile << "{" << currState << "}";
                }
                outputFile << word[i];
            }
            outputFile << std::endl;

            for (i = 0; i < tm.finalStates.size(); i++) {
                if (tm.finalStates[i] == currState) {
                    outputFile << "aceita\n";
                    return 0;
                }
            }

            char currLetter = word[tapeIndex];

            transition nextTransition;

            for(i = 0; i < tm.transitions.size(); i++) {
                if ((tm.transitions.at(i).fromState == currState) && (currLetter == tm.transitions.at(i).readSymbol)) {
                    nextTransition = tm.transitions.at(i);
                }
            }

            currState = nextTransition.toState;
            word[tapeIndex] = nextTransition.writeSymbol;

            if (nextTransition.moveDirection == RIGHT_DIRECTION) {
                tapeIndex++;
            } else if (nextTransition.moveDirection == LEFT_DIRECTION) {
                tapeIndex--;
            }

            std::cin >> oi;
        }

    } catch (std::exception& e) {
        std::cout << std::endl
                  << e.what() << std::endl;
    }
    return 0;
}
