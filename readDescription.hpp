#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

#include "types.hpp"

#pragma once

bool isWhitespace(const std::string& str) {
    return std::all_of(str.begin(), str.end(), [](unsigned char c) {
        return std::isspace(c);
    });
}

void readTuringMachineDescription(TuringMachine& tm) {
    std::string fileName;
    std::cin >> fileName;

    std::ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        throw std::runtime_error("Error opening file!");
    }

    std::string input;
    std::string aux;
    char charAux;

    // Read states
    std::getline(inputFile, input, '(');  // ignore initial "("

    std::getline(inputFile, input, '}');
    input.erase(0, input.find('{') + 1);

    std::istringstream statesStream(input);
    while (std::getline(statesStream, aux, ',')) {
        tm.states.push_back(aux);
    }

    // Read alphabet
    std::getline(inputFile, input, '}');
    input.erase(0, input.find('{') + 1);
    std::replace(input.begin(), input.end(), ',', ' ');
    std::istringstream alphabetStream(input);
    while (alphabetStream >> charAux) {
        tm.alphabet.push_back(charAux);
    }

    // Read tape alphabet
    std::getline(inputFile, input, '}');
    input.erase(0, input.find('{') + 1);
    std::replace(input.begin(), input.end(), ',', ' ');
    std::istringstream tapeStream(input);
    while (tapeStream >> charAux) {
        tm.tape.push_back(charAux);
    }

    // Read transitions
    std::getline(inputFile, input, '}');
    input.erase(0, input.find('{') + 1);
    std::istringstream transitionsStream(input.substr(1));
    std::string transitionStr;

    // reading each transition
    while (std::getline(transitionsStream, transitionStr, '\n') && !isWhitespace(transitionStr)) {
        // Removing the last comma
        transitionStr.erase(transitionStr.rfind(')') + 1, transitionStr.length());

        std::istringstream tParseStream(transitionStr);

        // Parsing the transitionStr and fill in the transition struct
        transition t;

        // Extract "t.fromState"
        while (tParseStream && tParseStream.peek() != EOF) {
            char c = tParseStream.get();
            if (isalnum(c) || c == '_') {  // check if is alphanumeric
                t.fromState += c;
            } else if (c == ',' || c == ')') {
                // sorry for using break :sad:
                break;
            }
        }

        tParseStream >> t.readSymbol;

        std::string auxStr = tParseStream.str();
        // pointing to the second tuple -- after "->"
        auxStr.erase(auxStr.begin(), auxStr.begin() + auxStr.rfind('('));

        tParseStream.str(auxStr);

        // Extract "t.toState"
        while (tParseStream && tParseStream.peek() != EOF) {
            char c = tParseStream.get();
            if (isalnum(c) || c == '_') {  // check if is alphanumeric
                t.toState += c;
            } else if (c == ',' || c == ')') {
                // sorry for using break :sad:
                break;
            }
        }

        tParseStream >> t.writeSymbol;

        // Skip ","
        tParseStream.get();

        tParseStream >> t.moveDirection;

        tm.transitions.push_back(t);
    }  // transitions

    // Read initial state
    std::getline(inputFile, input);
    std::getline(inputFile, input);

    tm.initialState = input;
    tm.initialState.erase(0, tm.initialState.find('q'));

    tm.initialState = tm.initialState.substr(0, tm.initialState.find(','));

    std::getline(inputFile, input, ',');

    std::getline(inputFile, input, '}');
    input.erase(0, input.find('{') + 1);
    input = input.substr(0, input.rfind('}'));

    std::istringstream finalStatesStream(input);
    
    while (std::getline(finalStatesStream, aux, ',')) {
        tm.finalStates.push_back(aux);
    }
}